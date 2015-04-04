#ifndef ACTORMANAGER_H
#define ACTORMANAGER_H

class Actor;
namespace gWrap
{
	class Window;
}

#include <memory>
#include "GameState.h"

class ActorManager
{
	/*
	This class handles rendering and updating of all actors in a scene.
	*/
public:
	ActorManager();

	/*
	\brief	Add a new actor whose draw method will ALWAYS be called.

	@newActor	The actor to be added to the manager
	*/
	void pushDrawable(Actor* newActor); 

	/*
	\brief	Add a new actor whose draw method will NEVER be called.

	@newActor	The actor to be added to the manager
	*/
	void pushOther(Actor* newActor);

	/*
	\brief	Update all actors in the current frame.

	@frameTime	The amount of time in seconds to update each actor.
	*/
	void update(float frameTime);

	/*
	\brief Draw all actors in the current frame.

	@window		The window on which to draw the actors.
	*/
	void draw(gWrap::Window& window);

	int getNumTotalActors() { return otherActors.size() + drawableActors.size(); }
	int getNumDrawableActors() { return drawableActors.size(); }
	int getNumOtherActors() { return otherActors.size(); }
private:
	std::vector<std::unique_ptr<Actor>> otherActors; //actors that will NEVER be drawn
	std::vector<std::unique_ptr<Actor>> drawableActors; //actors whose draw methods will ALWAYS be called
};





#endif