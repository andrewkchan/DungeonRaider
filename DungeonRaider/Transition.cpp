#include "Transition.h"

bool Transition::canTransition()
{
	for (std::size_t i = 0; i < transitionRules.size(); i++)
	{
		if (!transitionRules[i].isSatisfied())
		{
			//if any of the transition rules are not satisfied, return false
			return false;
		}
	}
	return true;
}