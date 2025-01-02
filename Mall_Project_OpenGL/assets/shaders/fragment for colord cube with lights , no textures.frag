#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

struct Material {
 vec3 ambient;
 vec3 diffuse;
 vec3 specular;
 float shininess;
 };
 uniform Material material;

 struct Light {
 vec3 position;
 vec3 ambient;
 vec3 diffuse;
 vec3 specular;
 };
 uniform Light light;


//uniform sampler2D u_Texture;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
 
 // diffuse
 vec3 norm = normalize(Normal);
 vec3 lightDir = normalize(lightPos- FragPos);
 float diff = max(dot(norm, lightDir), 0.0);
 // specular
 vec3 viewDir = normalize(viewPos- FragPos);
 vec3 reflectDir = reflect(-lightDir, norm);
 float spec = pow(max(dot(viewDir, reflectDir), 0.0),
 material.shininess);


 vec3 ambient = light.ambient * material.ambient;
 vec3 diffuse = light.diffuse * (diff * material.diffuse);
 vec3 specular = light.specular * (spec * material.specular);
// vec3 result = (ambient+diffuse+specular) * vec3(texture(u_Texture , TexCoord)) ;
 vec3 result = (ambient+diffuse+specular);
 FragColor = vec4(result, 1.0);
}