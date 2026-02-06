#version 330

uniform mat4 mMat;
uniform mat4 MVP;
in vec4 vPos;

void main()
{
	gl_Position=MVP*mMat*vPos;
}