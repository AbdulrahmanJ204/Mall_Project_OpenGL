#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture_diffuse1; 
uniform sampler2D texture_specular1; 
uniform sampler2D texture_normal; 

void main()
{    
    FragColor = texture(texture_diffuse1, TexCoord);
}