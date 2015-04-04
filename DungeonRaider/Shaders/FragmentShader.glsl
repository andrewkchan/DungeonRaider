#version 150

in vec3 vColor;
in vec2 vTexCoord;

out vec4 outColor;

//uniform sampler2D tex;
uniform sampler2D texSeptember;
uniform sampler2D texPuppy;
uniform float alpha;

void main()
{
	vec4 colSeptember = texture(texSeptember, vTexCoord);
	vec4 colPuppy = texture(texPuppy, vTexCoord);
	outColor = mix(colSeptember, colPuppy, 0.3) * vec4(vColor * alpha, 1.0);
	//outColor = vec4(1.0, 1.0, 1.0, 1.0);
}