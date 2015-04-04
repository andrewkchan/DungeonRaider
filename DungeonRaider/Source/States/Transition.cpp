#include "States\Transition.h"

template<class ComponentType, typename compareType>
void Transition::addTransitionRule(TransitionRule<ComponentType, compareType> rule)
{
	//create a pointer to a copy of the input rule
	//push that pointer onto the vector of TransitionRule pointers
	transitionRules.push_back(new TransitionRule(rule));
}

bool Transition::canTransition(Actor& actor)
{
	for (std::size_t i = 0; i < transitionRules.size(); i++)
	{
		if (!transitionRules[i]->isSatisfied(actor))
		{
			//if any of the transition rules are not satisfied, return false
			return false;
		}
	}
	return true;
}

Transition& Transition::operator=(const Transition& srcTransition)
{
	//check for self-assignment
	if (this == &srcTransition)
	{
		return *this;
	}

	//copy the vector of transition rules
	//don't worry, this copies actual data, not just the reference, so should be safe
	transitionRules = srcTransition.transitionRules; 
	return *this;
}