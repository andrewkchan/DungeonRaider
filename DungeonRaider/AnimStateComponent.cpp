#include "AnimStateComponent.h"

AnimStateComponent::AnimStateComponent() :
stateController_(0),
isVisible_(true),
indexOfCurrentState_(0),
timeInCurrentState_(0.0f),
currentFrame_(sf::Sprite())
{}

AnimStateComponent::AnimStateComponent(sf::Texture& spriteSheet, AnimStateController* stateController) :
stateController_(stateController),
isVisible_(true),
indexOfCurrentState_(0),
timeInCurrentState_(0.0f),
currentFrame_(sf::Sprite(spriteSheet))
{
	if (stateController_)
		indexOfCurrentState_ = stateController_->getIndexOfDefaultState();
}

AnimStateComponent::AnimStateComponent(const AnimStateComponent& src) :
isVisible_(src.isVisible_),
timeInCurrentState_(0.0f),
currentFrame_(src.currentFrame_)
{
	setStateController(src.stateController_);
}

void AnimStateComponent::setStateController(AnimStateController* controller)
{
	stateController_ = controller;
	if (stateController_)
		indexOfCurrentState_ = stateController_->getIndexOfDefaultState();
	//leave the game to deal with the old AnimStateController
}

void AnimStateComponent::update(double frameTime, Actor* actor)
{
	if (stateController_)
	{
		int nextState = stateController_->updateState(frameTime, *actor, indexOfCurrentState_);
		if (nextState != indexOfCurrentState_)
		{
			//get the time elapsed since we SHOULD have changed state
			float timeElapsedSinceStateChange = stateController_->getMaxTimeOfState(indexOfCurrentState_);
			//then set the time spent in the new state to compensate for this "lag"
			if (timeElapsedSinceStateChange > 0.0f)
				timeInCurrentState_ = timeInCurrentState_ - timeElapsedSinceStateChange;
			else
				timeInCurrentState_ = 0.0f;
			indexOfCurrentState_ = nextState;
		}
	}
}

sf::Sprite& AnimStateComponent::onDraw()
{
	if (stateController_)
		currentFrame_.setTextureRect(stateController_->OnDraw(indexOfCurrentState_, timeInCurrentState_));
	return currentFrame_;
}

AnimStateComponent& AnimStateComponent::operator=(const AnimStateComponent& animStateComponent)
{
	//check for self-assignment
	if (&animStateComponent == this)
	{
		return *this;
	}

	isVisible_ = animStateComponent.isVisible_;
	indexOfCurrentState_ = animStateComponent.indexOfCurrentState_;
	timeInCurrentState_ = 0.0f;
	setStateController(animStateComponent.stateController_);
	return *this;
}
