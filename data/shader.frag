#version 330

struct Material
{
	sampler2D colorText;
	bool useColorText;
	bool computeLight;
	int shininess;
	float ambientK;
};

struct Light
{
	vec4 position;
	vec4 direction;
	vec4 color;
	int type;
	bool enable;
};

Material material;
Light[] lights;

uniform vec4 cameraPos;

in vec4 fColor;
in vec4 fNorm;
in vec4 fPos;
in vec2 fTexCoord;


void main()
{
	vec4 tColor = vec4(0, 0, 0, 0);
	vec4 diffuseLightComponent = vec4(0,0,0,0);
	vec4 specularLightComponent = vec4(0,0,0,0);
	vec4 totalLightComponent = vec4(0,0,0,1);
	
	if(useColorText)
		tColor = texture(colorText, fTexCoord);
	
	if(material.computeLight)
	{
		totalLightComponent += vec4(material.ambientK, material.ambientK, material.ambientK, 0);
		if( lights.length() > 0)
		{
			for(int i = 0; i < lights.length(); i++)
			{
				Light l = lights[i];
				lvec = l.position-fPos;
				switch(lights[i].type)
				{
					case 0:
						vec4 auxDir = -1 * normalize(l.direction);
						diffuseLightComponent = l.color*max(dot(fNorm, l.direction), 0.0f);
						vec4 h = (cameraPos - fPos) - auxDir;
						specularLightComponent = pow(max(dot(h, cameraPos - fPos), 0.0f), material.shininess) * l.color;
					break;
					
					case 1:
					
					break;
					
					case 2:
					
					break;
					
					default:
					
					break;
				}
				totalLightComponent += diffuseLightComponent + specularLightComponent;
			}
		}
		gl_FragColor = (fColor * tColor) * totalLightComponent;
	}
	else
	{
		gl_FragColor = fColor + tColor;
	}
	
	
}