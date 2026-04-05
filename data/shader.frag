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
    vec3 direction;
    float linearAttenuation;
    bool enabled;
};

uniform Material mat;

#define N_LIGHTS 8
uniform Light lights[N_LIGHTS];
uniform int nLights;
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
        // Inicializar las componentes de luz
        vec3 totalLight = vec3(0.0f, 0.0f, 0.0f);
        vec3 diffuseComponent = vec3(0.0f, 0.0f, 0.0f);
        vec3 specularComponent = vec3(0.0f, 0.0f, 0.0f);

        // Anyadir el aporte ambiental
        totalLight += vec3(ambient, ambient, ambient);
        
        // Si la luz esta activa, calcular los aportes difuso y especular
        if (nLights > 0)
        {
            for(int i; i < nLights; i++)
            {
                Light light = lights[i];
                
                vec3 lightPos = light.pos;
                vec3 fPos3 = fPos.xyz;

                switch (light.type)
                {
                    case 0:
                        // Calcular la componente difusa (utilizando el angulo de incidencia con respecto a la normal)
                        vec3 p_normal = normalize(fNorm.xyz);
                        vec3 p_lightRay = -1 * (normalize(light.direction));

                        diffuseComponent = light.color * max(dot(p_normal, p_lightRay), 0.0f);

                        // Calcular la componente especular (utilizando el angulo entre el rayo reflejado y el vector vista desde la camara)
                        vec3 p_eye = normalize(fPos3 - camPos);
                        vec3 p_half = normalize(p_eye - p_lightRay);

                        specularComponent = light.color * pow(max(dot(p_half, p_eye), 0.0f), mat.shininess);

                        break;

                    case 1:
                        // Calcular la componente difusa (utilizando el angulo de incidencia con respecto a la normal)
                        vec3 s_normal = normalize(fNorm.xyz);
                        vec3 s_lightRay = normalize(lightPos - fPos3);

                        diffuseComponent = light.color * max(dot(s_normal, s_lightRay), 0.0f);

                        // Calcular la componente especular (utilizando el angulo entre el rayo reflejado y el vector vista desde la camara)
                        vec3 s_reflectedRay = normalize(reflect(s_lightRay, s_normal));
                        vec3 s_eye = normalize(fPos3 - camPos);

                        specularComponent = light.color * pow(max(dot(s_reflectedRay, s_eye), 0.0f), mat.shininess);

                        // Calcular la componente de luz total
                        float s_objectLightDistance = length(lightPos - fPos3);
                        float s_attenuation = 1 / (1 + light.linearAttenuation * s_objectLightDistance);

                //                    diffuseComponent *= s_attenuation;
                //                    specularComponent *= s_attenuation;

                        break;

                    case 2:

                        break;

                    default:
                        break;
                }

                totalLight += diffuseComponent + specularComponent;
            }
        }
        
        // Calcular el color final del fragmento (color final multiplicado por la luz total de la escena)
        gl_FragColor = (fColor * tColor) * vec4(totalLight, 1.0f);
    }
    else
    {
        gl_FragColor = (fColor * tColor);
    }
}