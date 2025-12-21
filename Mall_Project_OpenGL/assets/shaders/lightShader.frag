#version 330 core
out vec4 FragColor;

// PBR textures
uniform sampler2D albedoMap;
uniform sampler2D metallicMap;
uniform sampler2D roughnessMap;
uniform sampler2D normalMap;
uniform sampler2D aoMap;

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
#define Max_Lights_Number 30

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;
in mat3 TBN;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLights[Max_Lights_Number];
uniform SpotLight spotLight;
uniform int pointLightsNumber;
// Function prototypes
vec3 CalcDirLight(DirLight light, vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir);

void main() {
    // Fetch data from PBR maps
    vec3 albedo = texture(albedoMap, TexCoord).rgb;
    float metallic = texture(metallicMap, TexCoord).r;
    float roughness = texture(roughnessMap, TexCoord).r;
    vec3 normalMap = texture(normalMap, TexCoord).rgb;
    normalMap = normalize(normalMap * 2.0 - 1.0); // Convert to world-space
    vec3 normal = normalize(TBN * normalMap);
    float ao = texture(aoMap, TexCoord).r;

    // Calculate lighting
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 result = vec3(0.0);

    // Apply lights
    //result += CalcDirLight(dirLight, albedo, metallic, roughness, normal, viewDir);
    for(int i = 0 ; i<pointLightsNumber; ++i){
    result += CalcPointLight(pointLights[i], albedo, metallic, roughness, normal, viewDir);
    }
    //result += CalcSpotLight(spotLight, albedo, metallic, roughness, normal, viewDir);

    // Apply ambient occlusion
    result *= ao;

    FragColor = vec4(result, 1.0);
}

// PBR lighting calculations
vec3 CalcDirLight(DirLight light, vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);
    vec3 halfwayDir = normalize(viewDir + lightDir);

    // Calculate NDF (Normal Distribution Function)
    float NDF = pow(max(dot(normal, halfwayDir), 0.0), 1.0 / roughness);

    // Calculate diffuse and specular contributions
    float diff = max(dot(normal, lightDir), 0.0);
    float spec = NDF * metallic;

    vec3 ambient = light.ambient * albedo;
    vec3 diffuse = light.diffuse * diff * albedo;
    vec3 specular = light.specular * spec;

    return ambient + diffuse + specular;
}

vec3 CalcPointLight(PointLight light, vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - FragPos);
    vec3 halfwayDir = normalize(viewDir + lightDir);

    // Calculate NDF (Normal Distribution Function)
    float NDF = pow(max(dot(normal, halfwayDir), 0.0), 1.0 / roughness);

    // Calculate diffuse and specular contributions
    float diff = max(dot(normal, lightDir), 0.0);
    float spec = NDF * metallic;

    // Attenuation
    float distance = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    vec3 ambient = light.ambient * albedo;
    vec3 diffuse = light.diffuse * diff * albedo;
    vec3 specular = light.specular * spec;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return ambient + diffuse + specular;
}

vec3 CalcSpotLight(SpotLight light, vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - FragPos);
    vec3 halfwayDir = normalize(viewDir + lightDir);

    // Calculate NDF (Normal Distribution Function)
    float NDF = pow(max(dot(normal, halfwayDir), 0.0), 1.0 / roughness);

    // Calculate diffuse and specular contributions
    float diff = max(dot(normal, lightDir), 0.0);
    float spec = NDF * metallic;

    // Attenuation and spotlight intensity
    float distance = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    vec3 ambient = light.ambient * albedo;
    vec3 diffuse = light.diffuse * diff * albedo;
    vec3 specular = light.specular * spec;

    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;

    return ambient + diffuse + specular;
}
