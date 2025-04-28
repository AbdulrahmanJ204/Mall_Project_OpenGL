#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image/stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <mesh.h>
#include <shader.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

class Model {
public:
    // Model data
    std::vector<Texture1> textures_loaded; // Stores all the textures loaded so far
    std::vector<Mesh> meshes;
    std::string directory;
    bool gammaCorrection;

    // Constructor, expects a filepath to a 3D model
    Model(std::string const& path, bool gamma = false) : gammaCorrection(gamma) {
        loadModel(path);
    }

    // Draws the model, and thus all its meshes
    void Draw(Shader& shader) {
        for (unsigned int i = 0; i < meshes.size(); i++)
            meshes[i].Draw(shader);
    }

private:
    const aiScene* scene; // Store the scene for embedded textures

    // Loads a model with supported ASSIMP extensions from file
    void loadModel(std::string const& path) {
        // Read file via ASSIMP
        Assimp::Importer importer;
        scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

        // Check for errors
        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
            return;
        }

        // Retrieve the directory path of the filepath
        directory = path.substr(0, path.find_last_of('/'));

        // Process ASSIMP's root node recursively
        processNode(scene->mRootNode, scene);
    }

    // Processes a node in a recursive fashion
    void processNode(aiNode* node, const aiScene* scene) {
        // Process each mesh located at the current node
        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(mesh, scene));
        }

        // Process each of the children nodes
        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene);
        }
    }

    // Processes a mesh and returns a Mesh object
    Mesh processMesh(aiMesh* mesh, const aiScene* scene) {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture1> textures;

        // Process vertices
        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            Vertex vertex;
            glm::vec3 vector;

            // Positions
            vector.x = mesh->mVertices[i].x;
            vector.y = mesh->mVertices[i].y;
            vector.z = mesh->mVertices[i].z;
            vertex.Position = vector;

            // Normals
            if (mesh->HasNormals()) {
                vector.x = mesh->mNormals[i].x;
                vector.y = mesh->mNormals[i].y;
                vector.z = mesh->mNormals[i].z;
                vertex.Normal = vector;
            }

            // Texture coordinates
            if (mesh->mTextureCoords[0]) {
                glm::vec2 vec;
                vec.x = mesh->mTextureCoords[0][i].x;
                vec.y = mesh->mTextureCoords[0][i].y;
                vertex.TexCoords = vec;
            } else {
                vertex.TexCoords = glm::vec2(0.0f, 0.0f);
            }

            vertices.push_back(vertex);
        }

        // Process indices
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }

        // Process materials
        if (mesh->mMaterialIndex >= 0) {
            aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

            // Diffuse maps
            std::vector<Texture1> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

            // Specular maps
            std::vector<Texture1> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

            // Normal maps
            std::vector<Texture1> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
            textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

            // Height maps
            std::vector<Texture1> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
            textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
        }

        // Return a mesh object created from the extracted data
        return Mesh(vertices, indices, textures);
    }

    // Checks all material textures of a given type and loads them if not already loaded
    std::vector<Texture1> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName) {
        std::vector<Texture1> textures;
        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
            aiString str;
            mat->GetTexture(type, i, &str);

            // Check if texture was already loaded
            bool skip = false;
            for (unsigned int j = 0; j < textures_loaded.size(); j++) {
                if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0) {
                    textures.push_back(textures_loaded[j]);
                    skip = true;
                    break;
                }
            }

            if (!skip) {
                Texture1 texture;
                texture.id = TextureFromFile(str.C_Str(), this->directory, scene);
                texture.type = typeName;
                texture.path = str.C_Str();
                textures.push_back(texture);
                textures_loaded.push_back(texture);
            }
        }
        return textures;
    }

    // Loads a texture from file or embedded data
    unsigned int TextureFromFile(const char* path, const std::string& directory, const aiScene* scene) {
        std::string filename = std::string(path);

        // Check if the texture is embedded (starts with '*')
        if (filename[0] == '*') {
            // Embedded texture: use Assimp's texture loading
            int textureIndex = std::stoi(filename.substr(1)); // Extract the texture index
            const aiTexture* embeddedTexture = scene->mTextures[textureIndex];

            stbi_set_flip_vertically_on_load(true);
            // Load the embedded texture
            if (embeddedTexture->mHeight == 0) {
                // Compressed texture (e.g., PNG, JPG)
                return TextureFromMemory(reinterpret_cast<const unsigned char*>(embeddedTexture->pcData), embeddedTexture->mWidth);
            } else {
                // Uncompressed texture (e.g., raw pixel data)
                return TextureFromPixels(embeddedTexture->pcData, embeddedTexture->mWidth, embeddedTexture->mHeight);
            }
        } else {
            // External texture: load from file
            filename = directory + '/' + filename;
            stbi_set_flip_vertically_on_load(false);

            unsigned int textureID;
            glGenTextures(1, &textureID);

            int width, height, nrComponents;
            unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
            if (data) {
                GLenum format = GL_RED;
                std::cout << nrComponents << std::endl;
                if (nrComponents == 1)
                    format = GL_RED;
                else if (nrComponents == 2)
                {
                    //// Convert two-channel texture to RGBA
                    //unsigned char* rgbaData = new unsigned char[width * height * 4]; // Allocate memory for RGBA data
                    //for (int i = 0; i < width * height; i++) {
                    //    rgbaData[i * 4 + 0] = data[i * 2 + 0]; // Red channel (grayscale)
                    //    rgbaData[i * 4 + 1] = data[i * 2 + 0]; // Green channel (grayscale)
                    //    rgbaData[i * 4 + 2] = data[i * 2 + 0]; // Blue channel (grayscale)
                    //    rgbaData[i * 4 + 3] = data[i * 2 + 1]*0.2; // Alpha channel
                    //}
                    //format = GL_RGBA;
                    //stbi_image_free(data); // Free the original data
                    //data = rgbaData;
                }
                else if (nrComponents == 3)
                    format = GL_RGB;
                else if (nrComponents == 4)
                    format = GL_RGBA;

                glBindTexture(GL_TEXTURE_2D, textureID);
                glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                if (nrComponents == 2) {
                    delete[] data; // Free the converted RGBA data
                }
                else {
                    stbi_image_free(data); // Free the original data
                }
            } else {
                std::cout << "Texture failed to load at path: " << path << std::endl;
                stbi_image_free(data);
            }

            return textureID;
        }
    }

    // Helper function to load embedded compressed textures (e.g., PNG, JPG)
    unsigned int TextureFromMemory(const unsigned char* data, unsigned int size) {
        unsigned int textureID;
        glGenTextures(1, &textureID);

        int width, height, nrComponents;
        unsigned char* imageData = stbi_load_from_memory(data, size, &width, &height, &nrComponents, 0);
        if (imageData) {
            GLenum format = GL_RED;
            if (nrComponents == 1)
                format = GL_RED;
            else if (nrComponents == 3)
                format = GL_RGB;
            else if (nrComponents == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(imageData);
        } else {
            std::cout << "Failed to load embedded texture from memory" << std::endl;
        }

        return textureID;
    }

    // Helper function to load embedded uncompressed textures (e.g., raw pixel data)
    unsigned int TextureFromPixels(const aiTexel* pixels, unsigned int width, unsigned int height) {
        unsigned int textureID;
        glGenTextures(1, &textureID);

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        return textureID;
    }
};