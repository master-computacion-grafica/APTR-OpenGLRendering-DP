#version 330

struct Material
{
	sampler2D colorText;
	bool useColorText;
};

struct Light
{
	vec4 position;
	vec4 color;
	int type;
};


in vec4 fColor;
in vec2 fTexCoord;


void main()
{
	vec4 tColor = vec4(0, 0, 0, 0);
	
	if(useColorText)
		tColor = texture(colorText, fTexCoord);
	
	gl_FragColor = fColor + tColor;
}