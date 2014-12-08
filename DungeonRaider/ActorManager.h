#ifndef ACTORMANAGER_H
#define ACTORMANAGER_H


#include "Actor.h"
#include "GameState.h"

class ActorManager
{
	/*
	Class ActorManager
	
	This class handles rendering and updating of a huge array of actors. 
	This class is also a huge hack for now.
	
	Only 1 instance of this class should exist at a time.
	*/
private:
	Actor* actorArray; //an array of the actors managed by this class
	int numActors; //the number of actors managed by this class
	int actorArrayLength; //length of actorArray (NOTE: should be greater than numActors, so empty elements in the array)

	Attributes skeletonAttributes;
	Actor* skeletonPrototype;

public:
	ActorManager()
	{
		//default constructor
		actorArray = new Actor[4]; //by default, get enough size for 4 actors in the array
		actorArrayLength = 4; 
		numActors = 0;


		//initialize/define prototypes
		
		skeletonAttributes.canBreatheUnderwater = true;
		skeletonAttributes.isPoisonImmune = true;
		skeletonAttributes.maxHealth = 100;
		skeletonAttributes.maxJumpSpeed = 0.0;
		skeletonAttributes.maxMoveSpeed = 2.0;
		skeletonAttributes.maxQuickMoveSpeed = 3.0;
		skeletonPrototype = new Actor(&skeletonAttributes);
	}
	~ActorManager()
	{
		//destructor
		delete[] actorArray;
		actorArray = 0;
		delete skeletonPrototype;
		skeletonPrototype = 0;
	}

	void instantiateSkeleton();
	void pushActor(Actor newActor);
	void update(double frameTime); //update all actors in the current frame
	void draw(SDL_Renderer* renderer); //draw all actors in the current frame
	int getNumActors() { return numActors; }
};





#endif