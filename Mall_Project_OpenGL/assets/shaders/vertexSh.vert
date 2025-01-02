#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormals;
layout (location = 2) in vec2 aTexCoords;


out vec2 v_TexCoord;
uniform mat4 projection , view , model;

void main()
{



	gl_Position = projection* view * model* vec4(aPos , 1.0);

	v_TexCoord = aTexCoords;
}