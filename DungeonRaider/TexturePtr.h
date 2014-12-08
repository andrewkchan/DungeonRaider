#ifndef TEXTUREPTR_H
#define TEXTUREPTR_H

#include <iostream>


class TexturePtr
{
	/*
	Class TexturePtr


	This class allows safe handling and copying of SDL_Texture structs. 

	We want a Sprite class that only holds a texture, and not a SDL_renderer or SDL_Surface pointer. 
	We also need the Sprite class to support safe copying using the assignment operator, so that we can
	easily copy animations and such. However, since SDL_Textures are actually stored
	in VRAM, SDL_CreateTexture() only returns a pointer to the SDL_Texture it creates. Thus if we want to copy
	a Sprite object, we can only copy the memory addresses of the SDL_Textures, which is highly unsafe, because what
	if we accidentally delete the texture that another sprite is using? 

	TexturePtr will allow us to share a texture pointer amongst Sprite objects that will be deletion-safe.
	TexturePtr does reference-counting; everytime a TexturePtr is copy-constructed or assigned to another,
	the count of Sprites referring to that TexturePtr increases by 1.
	If a Sprite holding a TexturePtr is destroyed, its destructor will 
	call TexturePtr's destructor, which will only delete the actual SDL_Texture if there are no other Sprites
	holding the same TexturePtr. 
	
	
	*/

//now that we are switching from SDL to SMFL, we'll see if we really need this class or not



};






#endif