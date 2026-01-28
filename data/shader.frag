#version 330

uniform sampler2D colorText; //unidad de textura de color
uniform bool useColorText;
in vec4 fColor; //variable de entrada
in vec2 fTexCoord;
void main()
{
    vec4 tColor = vec4(0, 0, 0, 0);
    
    if(useColorText)
        tColor=texture(colorText, fTexCoord);

    gl_FragColor = fColor+tColor; //asignar color de salida
}