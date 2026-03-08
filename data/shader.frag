#version 330

struct Material
{
    float shininess;
    bool lightEnable;

    sampler2D colorText;
    bool useColorText;
};

struct Light
{
    vec3 pos;
    int type;
    vec3 color;
    float linearAttenuation;
};

uniform Material mat;
uniform Light light;
uniform float ambient;

uniform vec3 camPos;

in vec4 fColor;
in vec2 fTexCoord;
in vec4 fNorm;
in vec4 fPos;

void main()
{
    // Inicializar y conseguir la componente color de la textura
	vec4 tColor = vec4(0, 0, 0, 0);
	
	if(mat.useColorText)
		tColor = texture(mat.colorText, fTexCoord);
    
    // Inicializar la componente de luz total
    float lightComponent = 0.0f;
    
    // Calcular la componente difusa (utilizando el angulo de incidencia con respecto a la normal)
    vec3 lightPos = light.pos;
    vec3 fPos3 = fPos.xyz;
    
    vec3 normal = normalize(fNorm.xyz);
    vec3 lightRay = normalize(lightPos - fPos3);
    float diffuseComponent = max(dot(normal,lightRay), 0.0f);
    
    // Calcular la componente especular (utilizando el angulo entre el rayo reflejado y el vector vista desde la camara)
    vec3 reflectedRay = normalize(reflect(lightRay, normal));
    vec3 eye = normalize(fPos3 - camPos);
    float specularComponent = pow(max(dot(reflectedRay, eye), 0.0f), mat.shininess);
    
    // Calcular la componente de luz total
    float objectLightDistance = length(lightPos - fPos3);
    float attenuation = 1 / (1 + light.linearAttenuation * objectLightDistance);
    
    lightComponent = ambient + (diffuseComponent + specularComponent) * attenuation;
	
    // Calcular el color final del fragmento
	gl_FragColor = (fColor + tColor) * lightComponent * vec4(light.color, 1.0f);
}