#include "Entities\ActorManager.h"
#include "GraphicsWrappers\Window.h"
#include "Entities\Actor.h"

ActorManager::ActorManager()
{}
void ActorManager::pushDrawable(Actor* newActor)
{
	if (newActor)
	{
		drawableActors.push_back(std::unique_ptr<Actor>(newActor));
	}
}
void ActorManager::pushOther(Actor* newActor)
{
	if (newActor)
	{
		otherActors.push_back(std::unique_ptr<Actor>(newActor));
	}
}

typedef std::vector<std::unique_ptr<Actor>>::iterator actorIterator;
void ActorManager::draw(gWrap::Window& window)
{
	for (actorIterator it = drawableActors.begin(); it != drawableActors.end(); ++it)
	{
		(*it)->drawToWindow(window);
	}
}
void ActorManager::update(float frameTime)
{
	//TODO: Manage dead/destroyed actors

	for (actorIterator it = drawableActors.begin(); it != drawableActors.end(); ++it)
	{
		(*it)->update(frameTime);
	}
	for (actorIterator it = otherActors.begin(); it != otherActors.end(); ++it)
	{
		(*it)->update(frameTime);
	}
}