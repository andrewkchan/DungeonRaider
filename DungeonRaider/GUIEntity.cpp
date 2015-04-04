#include "Entities\GUIEntity.h"
#include "Components\GUIComponent.h"

void GUIEntity::drawToWindow(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		window.draw(components[i]->onDraw(), pos2D_.getTransform());
	}
}
void GUIEntity::addComponent(GUIComponent* component)
{
	components.push_back(component);
}
void GUIEntity::update(float frameTime)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->update(frameTime, *this);
	}
}


GUIEntity::~GUIEntity()
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}