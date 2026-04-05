#version 330

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 NORM;

attribute vec4 vPos;

attribute vec4 vColor;
attribute vec2 vTexCoord;
attribute vec4 vNorm;

out vec4 fColor;
out vec2 fTexCoord;
out vec4 fNorm;
out vec4 fPos;

void main()
{
	gl_Position = MVP * vPos;

	fColor = vColor;

	fTexCoord = vTexCoord;
    
    fNorm = normalize(NORM * vNorm);
    
    fPos = M * vPos;
}