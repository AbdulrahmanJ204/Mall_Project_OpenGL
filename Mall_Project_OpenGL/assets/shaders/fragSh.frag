#version 330 core
out vec4 FragColor;

in vec2 v_TexCoord;
uniform sampler2D u_Texture;
void main(){
//FragColor = vec4(1.0 , 1.0 , 1.0 , 1.0);
FragColor = texture(u_Texture, v_TexCoord);
}
