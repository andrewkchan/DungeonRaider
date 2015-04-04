#version 150

in vec2 vTexCoord;

out vec4 outColor;

uniform sampler2D texColorbuffer;
uniform sampler2D texDepthStencil;

void main()
{
	/*
	float z = texture(texDepthStencil, vTexCoord).r;      // fetch the z-value from our depth texture
	float n = 1.0;                                // the near plane
	float f = 30.0;                               // the far plane
	float c = (2.0 * n) / (f + n - z * (f - n));  // convert to linear values 
	outColor.rgb = vec3(c); */
	outColor = texture(texColorbuffer, vTexCoord);
}