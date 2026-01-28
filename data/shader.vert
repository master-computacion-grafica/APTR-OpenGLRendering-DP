#version 330
uniform mat4 MVP;
attribute vec4 vPos; //buffer object para datos de posicion
attribute vec4 vColor;
attribute vec2 vTexCoord;


out vec4 fColor; //datos de salida extra para el siguiente shader
out vec2 fTexCoord;

void main() {
    gl_Position = MVP * vPos; //calculo de posicion de vertice
    fColor = vColor; //pasamos el color al siguiente shader
    fTexCoord = vTexCoord;
}