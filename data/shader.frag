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
    bool enabled;
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
    vec4 tColor = vec4(1, 1, 1, 1);

    if(mat.useColorText)
    tColor = texture(mat.colorText, fTexCoord);
    
    if (mat.lightEnable)
    {
        // Inicializar la componente de luz total
        vec3 totalLight = vec3(0.0f, 0.0f, 0.0f);

        // Si la luz esta activa, calcular los aportes difuso y especular
        if (light.enabled)
        {
            // Calcular la componente difusa (utilizando el angulo de incidencia con respecto a la normal)
            vec3 lightPos = light.pos;
            vec3 fPos3 = fPos.xyz;

            vec3 normal = normalize(fNorm.xyz);
            vec3 lightRay = normalize(lightPos - fPos3);
            vec3 diffuseComponent = light.color * max(dot(normal, lightRay), 0.0f);

            // Calcular la componente especular (utilizando el angulo entre el rayo reflejado y el vector vista desde la camara)
            vec3 reflectedRay = normalize(reflect(lightRay, normal));
            vec3 eye = normalize(fPos3 - camPos);
            vec3 specularComponent = light.color * pow(max(dot(reflectedRay, eye), 0.0f), mat.shininess);

            // Calcular la componente de luz total
            float objectLightDistance = length(lightPos - fPos3);
            float attenuation = 1 / (1 + light.linearAttenuation * objectLightDistance);

            diffuseComponent *= attenuation;
            specularComponent *= attenuation;

            totalLight = diffuseComponent + specularComponent + vec3(ambient, ambient, ambient);
        }
        else
        {
            // Si no hay luces encendidas, calcular la luz solo con el aporte ambiental
            totalLight = vec3(ambient, ambient, ambient);
        }

        // Calcular el color final del fragmento (color final multiplicado por la luz total de la escena)
        gl_FragColor = (fColor * tColor) * vec4(totalLight, 1.0f);
    }
    else
    {
        gl_FragColor = (fColor * tColor);
    }
}