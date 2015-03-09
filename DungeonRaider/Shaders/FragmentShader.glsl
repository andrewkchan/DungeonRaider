#version 150

in vec3 vColor;
in vec2 vTexCoord;

out vec4 outColor;

//uniform sampler2D tex;
uniform sampler2D texSeptember;
uniform sampler2D texPuppy;

void main()
{
	vec4 colSeptember = texture(texSeptember, vTexCoord);
	vec4 colPuppy = texture(texPuppy, vTexCoord);
	outColor = mix(colSeptember, colPuppy, 0.3) * vec4(vColor, 1.0);
}