#version 150 compatibility

uniform sampler2D texture; 			//diffuse texture for the thing currently being drawn
uniform sampler2D depthTexture; 	//depth texture for the thing currently being drawn (the depth values that will be tested)
uniform float positionalDepth; 		//the Y component of the vertice, added to its depth

out float gl_FragDepth;

/*
Get the non-linear depth value used by the depth-buffer for a given linear depth value
*/
void convertToNonLinearDepth(inout float depth)
{
	float nearPlane = 1.0;                                	// the near plane
	float farPlane = 30.0;                               	// the far plane
	depth = 
		(farPlane + nearPlane)/(farPlane - nearPlane) 
		- 
		(2 * nearPlane)/((farPlane - nearPlane) * depth);
}
/*
Same as above, but returns a value instead of modifying the argument
*/
float getNonLinearDepth(in float depth)
{
	float nearPlane = 1.0;                                	// the near plane
	float farPlane = 30.0;                               	// the far plane
	return
		(farPlane + nearPlane)/(farPlane - nearPlane) 
		- 
		(2 * nearPlane)/((farPlane - nearPlane) * depth);
}

/*
Clamp the depth of a given depth value between the near plane and the far plane.
*/
float clampDepth(in float depth)
{
	if(depth < 0.01)
	{
		return 0.01;
	}
	else if(depth > 1.0)
	{
		return 1.0;
	}
	return depth;
}

void main()
{
	//lookup pixel in the texture
	vec4 pixel = texture(texture, gl_TexCoord[0].xy);
	
	//add color to texture, if applicable
	gl_FragColor = gl_Color * pixel;
	
	//change pixel depth to the depth specified in the depth texture
	vec4 depthPixel = texture(depthTexture, gl_TexCoord[0].xy);
	float pixelDepth = depthPixel.r;
	convertToNonLinearDepth(pixelDepth); //convert the linear depth values in the depth texture to nonlinear depth values used by the depth-buffer
	
	if(depthPixel.a != 0.0)
	{
		gl_FragDepth = pixelDepth - positionalDepth; //add how far down the screen the vertice is to the depth
	}
	else
	{
		gl_FragDepth = clampDepth(pixelDepth);
	}
}