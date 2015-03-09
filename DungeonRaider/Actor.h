#ifndef ACTOR_H
#define ACTOR_H


#include "Entity.h"
#include "Component.h"
#include "Tracker.h"
#include "Tracked.h"
#include "DrawableComponent.h"
#include "TransformComponent.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

//fwd declarations
class World;




class Actor : public Entity
{
	/*
	Class Actor

	This class represents everything that has a real, ingame position in ingame space.
	It inherits from Entity.
	
	*/
protected:
	//----------------------------
	std::vector<Component*>otherComponents; //all components without guaranteed onDraw() function
	std::vector<DrawableComponent*>drawableComponents; //all components WITH guaranteed onDraw() function
	TransformComponent transformComponent; //position of Actor placed here for easy access for other components!
	//----------------------------
public:
	/*
	Default constructor, creates default (empty) component list.
	*/
	Actor(const glm::vec4& inputPos = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) 
		: 
		Entity(),
		transformComponent(inputPos)
	{}

	/*
	Copy constructor
	Note: This is often called when ActorManager pushes a new Actor on, since it must resize its container of actors
	*/
	Actor(const Actor& srcActor);
	virtual ~Actor();

	/*
	Actor tick function, called automatically each iteration of the game loop. Automatically updates
	all components attached to the actor.
	*/
	virtual void update(float frameTime);

	/*
	Attach a new Component to the Actor. Only the Component::update() function will be automatically called.
	*/
	virtual void addOtherComponent(Component* component);
	
	/*
	Attach a new DrawableComponent to the Actor. DrawableComponent::update() and DrawableComponent::onDraw() will be automatically called.
	Note that having multiple DrawableComponents may affect performance considerably.
	*/
	virtual void addDrawableComponent(DrawableComponent* component);

	/*
	Draws the actor to the specified window.
	*/
	virtual void drawToWindow(sf::RenderWindow& window);

	/*
	Get a reference to the actor's position component.
	*/
	virtual TransformComponent& getTransform() { return transformComponent; }

	/*
	Gets a pointer to the component at the specified index of the Actor's non-drawn components.
	NOTE: Memory addresses and indexes of components are very volatile.
	*/
	Component* getOtherComponentAt(unsigned int index);
	/*
	Gets a pointer to the drawable component at the specified index of the Actor's drawable components.
	NOTE: Memory addresses and indexes of components are not guaranteed const.
	*/
	DrawableComponent* getDrawableComponentAt(unsigned int index);

	/*
	Returns the number of non-drawn components owned by the actor.
	*/
	virtual unsigned int getNumOtherComponents() { return otherComponents.size(); }
	/*
	Returns the number of drawn components owned by the actor.
	*/
	virtual unsigned int getNumDrawableComponents() { return drawableComponents.size(); }

	
	template<class ComponentType>
	/*
	Gets a pointer to the first (non-drawn) component the actor has of the specified type, null if none.
	NOTE: Memory addresses of components are very volatile.
	*/
	ComponentType* getOtherComponent()
	{
		ComponentType* output;
		for (unsigned int i = 0; i < otherComponents.size(); i++)
		{
			output = dynamic_cast<ComponentType*>(otherComponents[i]);
			if (output)
			{
				return output;
			}
		}
		return 0;
	}

	template<class DrawableComponentType>
	/*
	Gets a pointer to the first drawable component the actor has of the specified type, null if none.
	NOTE: Memory addresses of components are very volatile.
	*/
	DrawableComponentType* getDrawableComponent()
	{
		DrawableComponentType* output;
		for (unsigned int i = 0; i < drawableComponents.size(); i++)
		{
			output = dynamic_cast<DrawableComponentType*>(drawableComponents[i]);
			if (output)
			{
				return output;
			}
		}
		return 0;
	}

	template<class ComponentType>
	/*
	Sets a given tracker to track the first (non-drawn) component the actor has of the specified type, null if none.
	This allows for safe handling of component addresses, which are liable to change.

	Ex: Actor::trackOtherComponent<HealthComponent>(lifeChecker)
	will set a Tracker object lifeChecker to track the first HealthComponent that the specified Actor possesses.
	*/
	void trackOtherComponent(Tracker& tracker)
	{
		ComponentType* output = 0;
		for (unsigned int i = 0; i < otherComponents.size(); i++)
		{
			output = dynamic_cast<ComponentType*>(otherComponents[i]);
			if (output)
			{
				tracker.setNewSubject(static_cast<Tracked*>(output));
				return;
			}
		}
		tracker.setNewSubject(output); //track null if component not found
	}

	template<class DrawableComponentType>
	/*
	Sets a given tracker to track the first drawable component the actor has of the specified type, null if none.
	This allows for safe handling of component addresses, which are liable to change.

	Ex: Actor::trackOtherComponent<SpriteComponent>(spriteChecker)
	will set a Tracker object spriteChecker to track the first SpriteComponent that the specified Actor possesses.
	*/
	void trackDrawableComponent(Tracker& tracker)
	{
		DrawableComponentType* output = 0;
		for (unsigned int i = 0; i < drawableComponents.size(); i++)
		{
			output = dynamic_cast<DrawableComponentType*>(drawableComponents[i]);
			if (output)
			{
				tracker.setNewSubject(static_cast<Tracked*>(output));
				return;
			}
		}
		tracker.setNewSubject(0);
	}

	Actor& operator=(const Actor& srcActor);
};





#endif