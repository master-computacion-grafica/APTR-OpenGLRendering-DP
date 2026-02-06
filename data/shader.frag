#version 330

uniform sampler2D colorText;
uniform bool useColorText;
in vec4 fColor;
in vec2 fTextCoord;


void main()
{
	vec4 tColor = vec4(0, 0, 0, 0);
	
	if(useColorText)
		tColor = texture(colorText, fTextCoord);
	
	gl_FragColor = fColor + tColor;
}