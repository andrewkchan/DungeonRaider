#version 150

in vec3 position;
in vec2 texCoord;
in vec3 inVColor;

out vec3 vColor;
out vec2 vTexCoord;

uniform mat4 projTrans;
uniform mat4 viewTrans;
uniform mat4 modelTrans;
uniform float size;

void main()
{
	vColor = inVColor;
	vTexCoord = texCoord;
	//gl_Position = projTrans * viewTrans * modelTrans * vec4(position * size, 1.0);
	gl_Position = projTrans * viewTrans * modelTrans * vec4(position, 1.0);
}