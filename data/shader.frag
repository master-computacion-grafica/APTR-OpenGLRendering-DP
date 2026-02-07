#version 330

uniform sampler2D colorText;
uniform bool useColorText;
in vec4 fColor;
in vec2 fTexCoord;


void main()
{
	vec4 tColor = vec4(1, 1, 1, 0);
	
	if(useColorText)
		tColor = texture(colorText, fTexCoord);
	
	gl_FragColor = fColor + tColor;
}