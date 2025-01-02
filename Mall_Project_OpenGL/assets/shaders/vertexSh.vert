#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoords;


out vec2 v_TexCoord;
uniform mat4 proj , view , model;

void main()
{



	gl_Position = proj* view * model* vec4(aPos , 1.0);

	v_TexCoord = aTexCoords;
}