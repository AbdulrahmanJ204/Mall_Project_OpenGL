#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

struct Material {
 sampler2D diffuse; // removed ambient since they have the same color.
 sampler2D specular;
 float shininess;
 };
 uniform Material material;

 struct Light {
 vec3 position;
 vec3 ambient;
 vec3 diffuse;
 vec3 specular;
 float constant;
 float linear;
 float quadratic;
 };
 uniform Light light;

uniform vec3 viewPos;

void main()
{
 
 // diffuse
 vec3 norm = normalize(Normal);
 vec3 lightDir = normalize(light.position- FragPos);
 float diff = max(dot(norm, lightDir), 0.0);
 // specular
 vec3 viewDir = normalize(viewPos- FragPos);
 vec3 reflectDir = reflect(-lightDir, norm);
 float spec = pow(max(dot(viewDir, reflectDir), 0.0),material.shininess);
 
 float distance = length(light.position- FragPos);
 float attenuation = 1.0 / (light.constant + light.linear * distance +
 light.quadratic * (distance * distance));

 vec3 diffuse  = light.diffuse  * diff *	vec3(texture(material.diffuse,TexCoord));
 vec3 ambient  = light.ambient  *		vec3(texture(material.diffuse, TexCoord));
 vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoord));

 vec3 result = (ambient+diffuse+specular) * attenuation;
 FragColor = vec4(result, 1.0);
}