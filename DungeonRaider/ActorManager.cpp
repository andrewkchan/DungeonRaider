#include "ActorManager.h"

void ActorManager::pushActor(Actor newActor)
{
	++numActors;
	if (numActors >= actorArrayLength)
	{
		//if we need to increase the size of the array...

		//create a temporary array to hold the elements of the old array
		Actor* tempActorArray = new Actor[actorArrayLength];
		for (int i = 0; i < actorArrayLength; i++)
		{
			tempActorArray[i] = actorArray[i];
		}

		//delete the old array's elements
		delete[] actorArray;

		//increase the size of the new array by 5
		actorArrayLength += 5;
		actorArray = new Actor[actorArrayLength];
		
		//copy all old elements back into the new array
		for (int i = 0; i < (actorArrayLength - 5); i++)
		{
			actorArray[i] = tempActorArray[i];
		}

		//FINALLY, add in the new actor element
		actorArray[numActors - 1] = newActor;
	}
	else
	{
		actorArray[numActors - 1] = newActor;
	}
}
void ActorManager::instantiateSkeleton()
{
	pushActor(*skeletonPrototype);
}
void ActorManager::draw(SDL_Renderer* renderer)
{

}
void ActorManager::update(double frameTime)
{
	for (int i = 0; i < numActors; i++)
	{
		actorArray[i].update(frameTime);
	}
}