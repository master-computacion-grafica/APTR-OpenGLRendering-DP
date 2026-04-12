#version 330


struct Material
{
	sampler2D colorText;
	bool useColorText;
	bool computeLight;
	float shininess;
	float ambientK;
};

struct Light
{
	vec4 position;
	vec4 direction;
	vec4 color;
	float linearAttenuation;
	int type;
	bool enable;
};

uniform Material material;
uniform Light lights[8];
uniform int nLights;

uniform vec4 cameraPos;

in vec4 fColor;
in vec4 fNorm;
in vec4 fPos;
in vec2 fTexCoord;

#define DIRECTIONAL 0
#define POINT 1
#define SPOT 2

void main()
{
	vec4 tColor = vec4(1, 1, 1, 1);

	if(material.useColorText)
		tColor = texture(material.colorText, fTexCoord);

	if(material.computeLight)
	{
		float diffuseLightComponent = 0;
		float specularLightComponent = 0;
		vec4 totalLightComponent = vec4(0,0,0,1);
		vec3 N = normalize(fNorm.xyz);
		totalLightComponent += vec4(material.ambientK, material.ambientK, material.ambientK, 0);

		for(int i = 0; i < nLights; i++)
		{
			Light l = lights[i];
			if(l.enable)
			{
				vec3 lDir = normalize(l.position.xyz-fPos.xyz);
				vec3 eye = normalize(fPos.xyz - cameraPos.xyz);
				switch(lights[i].type)
				{
					case DIRECTIONAL:
					vec3 auxDir = -1 * normalize(l.direction.xyz);
					vec3 h = normalize(eye - auxDir);
					diffuseLightComponent = max(dot(N, auxDir), 0.0f);
					specularLightComponent = pow(max(dot(h, eye), 0.0f), material.shininess);

					break;

					case POINT:
					float distance = length(l.position - fPos);

					float att = 1 / (1 + l.linearAttenuation * distance);

					diffuseLightComponent = max(dot(N, lDir), 0.0f) * att;

					h = normalize(reflect(lDir, N));

					specularLightComponent = pow(max(dot(h, eye), 0.0f), material.shininess) * att;

					break;

					case SPOT:

					break;

					default:

					break;
				}

				totalLightComponent += vec4(l.color.xyz * (diffuseLightComponent + specularLightComponent), 0);
			}
			
		}
		
		gl_FragColor = (fColor * tColor) * totalLightComponent;
		
	}
	else
	{
		gl_FragColor = fColor * tColor;
	}


}