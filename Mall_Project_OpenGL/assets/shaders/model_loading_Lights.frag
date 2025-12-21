#version 330 core
out vec4 FragColor;



struct DirLight {
	vec3 direction;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight {
	vec3 position;
	
	float constant;
	float linear;
	float quadratic;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct SpotLight {
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;
  
	float constant;
	float linear;
	float quadratic;
  
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;       
};


in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;



vec3 normal , viewDir ,fragPos , difMap , specMap;
// function prototypes
vec3 CalcDirLight(DirLight light);
vec3 CalcPointLight(PointLight light);
vec3 CalcSpotLight(SpotLight light);

uniform float shininess;
uniform sampler2D texture_diffuse1; 
uniform sampler2D texture_specular1; 
uniform sampler2D texture_normal1; 

void main()
{    
// properties
	normal  = normalize(texture(texture_normal1, TexCoord).xyz *2.0f - 1.0f);
	viewDir = normalize(viewPos - FragPos);
	fragPos = FragPos;
	difMap  = vec3(texture(texture_diffuse1, TexCoord));
	specMap = vec3(texture(texture_specular1, TexCoord).r);
	// phase 1: directional lighting
//	vec3 result = CalcDirLight(dirLight);
	// phase 2: point lights
	vec3 result= CalcPointLight(pointLight);    
//	result += CalcPointLight(pointLight);    
	// phase 3: spot light
	result += CalcSpotLight(spotLight);    
	
	FragColor = vec4(result, 1.0);
}
vec3 CalcDirLight(DirLight light)
{
	vec3 lightDir = normalize(-light.direction);
	// diffuse shading
	float diff = max(dot(normal, lightDir), 0.0);
	// specular shading
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	// combine results
	vec3 ambient = light.ambient * difMap;
	vec3 diffuse = light.diffuse * diff * difMap;
	vec3 specular = light.specular * spec * specMap;
	return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light)
{
	vec3 lightDir = normalize(light.position - fragPos);
	// diffuse shading
	float diff = max(dot(normal, lightDir), 0.0);
	// specular shading
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	// attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
	// combine results
	vec3 ambient = light.ambient * difMap;
	vec3 diffuse = light.diffuse * diff * difMap;
	vec3 specular = light.specular * spec * specMap;
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	return (ambient + diffuse + specular);
}

// calculates the color when using a spot light.
vec3 CalcSpotLight(SpotLight light)
{
	vec3 lightDir = normalize(light.position - fragPos);
	// diffuse shading
	float diff = max(dot(normal, lightDir), 0.0);
	// specular shading
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	// attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
	// spotlight intensity
	float theta = dot(lightDir, normalize(-light.direction)); 
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
	// combine results
	vec3 ambient = light.ambient * difMap;
	vec3 diffuse = light.diffuse * diff * difMap;
	vec3 specular = light.specular * spec * specMap;
	ambient *= attenuation * intensity;
	diffuse *= attenuation * intensity;
	specular *= attenuation * intensity;
	return (ambient + diffuse + specular);
}