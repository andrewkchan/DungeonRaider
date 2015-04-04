#include "GraphicsWrappers\Sprite.h"

namespace gWrap
{
	Sprite::Sprite() :
		diffuseTex(0),
		depthTex(0),
		textureRect()
	{
		sf::Transformable::setOrigin(0.0f, getGlobalBounds().height);
	}

	Sprite::Sprite(const sf::Texture& newDiffuseTex, const sf::Texture& newDepthTex) :
		diffuseTex(0),
		depthTex(0),
		textureRect()
	{
		setDiffuseTex(newDiffuseTex);
		setDepthTex(newDepthTex);
		sf::Transformable::setOrigin(0.0f, getGlobalBounds().height);
	}

	void Sprite::setDiffuseTex(const sf::Texture& texture, bool resetRect)
	{
		// Recompute the texture area if requested, or if there was no valid texture & rect before
		if (resetRect || (!diffuseTex && (textureRect == sf::IntRect())))
			setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));

		//assign new texture
		diffuseTex = &texture;
	}

	void Sprite::setDepthTex(const sf::Texture& texture, bool resetRect)
	{
		// Recompute the texture area if requested, or if there was no valid texture & rect before
		if (resetRect || (!depthTex && (textureRect == sf::IntRect())))
			setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));

		//assign new texture
		depthTex = &texture;
	}

	void Sprite::setTextureRect(const sf::IntRect& rectangle)
	{
		if (rectangle != textureRect)
		{
			textureRect = rectangle;
			updatePositions();
			updateTexCoords();
		}
	}
	
	const sf::Texture* Sprite::getDiffuseTex() const
	{
		return diffuseTex;
	}
	const sf::Texture* Sprite::getDepthTex() const
	{
		return depthTex;
	}

	const sf::IntRect& Sprite::getTextureRect() const
	{
		return textureRect;
	}

	sf::FloatRect Sprite::getLocalBounds() const
	{
		float width = static_cast<float>(std::abs(textureRect.width));
		float height = static_cast<float>(std::abs(textureRect.height));

		return sf::FloatRect(0.f, 0.f, width, height);
	}
	sf::FloatRect Sprite::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	//-----------------------------
	//Private and Protected functions
	//-----------------------------

	void Sprite::draw(Window& window, float positionalDepth, sf::RenderStates states) const
	{
		if (diffuseTex)
		{
			states.transform *= getTransform();
			states.texture = diffuseTex;
			window.draw(vertices, depthTex, positionalDepth, states);
		}
	}
	void Sprite::drawDiffuse(Window& window, sf::RenderStates states) const
	{
		if (diffuseTex)
		{
			states.transform *= getTransform();
			states.texture = diffuseTex;
			window.draw(vertices, false, states);
		}
	}
	void Sprite::drawDepth(Window& window, sf::RenderStates states) const
	{
		if (depthTex)
		{
			states.transform *= getTransform();
			states.texture = diffuseTex;
			window.draw(vertices, false, states);
		}
	}

	void Sprite::updatePositions()
	{
		sf::FloatRect bounds = getLocalBounds();

		vertices[0].position = sf::Vector2f(0.0f, 0.0f);

		vertices[1].position = sf::Vector2f(0.0f, bounds.height);

		vertices[2].position = sf::Vector2f(bounds.width, 0.0f);

		vertices[3].position = sf::Vector2f(bounds.width, bounds.height);

		sf::Transformable::setOrigin(0.0f, getGlobalBounds().height);
	}
	void Sprite::updateTexCoords()
	{
		float left = static_cast<float>(textureRect.left);
		float right = left + textureRect.width;
		float top = static_cast<float>(textureRect.top);
		float bottom = top + textureRect.height;

		vertices[0].texCoords = sf::Vector2f(left, top);

		vertices[1].texCoords = sf::Vector2f(left, bottom);

		vertices[2].texCoords = sf::Vector2f(right, top);

		vertices[3].texCoords = sf::Vector2f(right, bottom);
	}
}