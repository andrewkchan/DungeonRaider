#ifndef GUIENTITY_H
#define GUIENTITY_H

#include "Entity.h"
#include "GUIComponent.h"
#include <SFML/Graphics.hpp>
#include <vector>

/*
class GUIEntity

This entity has a position in 2D screen space only.
*/
class GUIEntity : public Entity
{
protected:
	sf::Transformable pos2D_; //the position of the GUIEntity in 2D screen-space
	
	std::vector<GUIComponent*>components;
public:
	GUIEntity(float x = 0.0f, float y = 0.0f) : 
		Entity()
	{
		pos2D_.setPosition(x, y);
	}
	virtual ~GUIEntity();

	virtual void drawToWindow(sf::RenderWindow& window);
	virtual void addComponent(GUIComponent* component);

	//returns the first component of the specified type possessed by the entity.
	template<class GUIComponentType>
	GUIComponentType* getComponent()
	{
		GUIComponentType* output;
		for (unsigned int i = 0; i < components.size(); i++)
		{
			output = dynamic_cast<GUIComponentType*>(components[i]);
			if (output)
			{
				return output;
			}
		}
		return 0;
	}
	//returns the component at the specified index of the component list, 0 if out of range
	virtual GUIComponent* getComponentAt(unsigned int i)
	{
		if (i >= components.size() || i < 0)
		{
			return 0;
		}
		return components[i];
	}

	//returns the number of components currently owned by the GUIEntity
	virtual unsigned int getNumComponents()
	{
		return components.size();
	}


	virtual void update(float frameTime);
};




#endif