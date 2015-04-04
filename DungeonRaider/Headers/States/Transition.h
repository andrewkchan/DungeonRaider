#ifndef TRANSITION_H
#define TRANSITION_H


#include <vector>
#include "TransitionRule.h"

class Transition
{
	/*
	Class Transition

	This class defines transitions between two states. Each state should have
	an array (or vector) of possible transitions to different states, and 
	on each update the state controller should check the transitions in the current
	state and see whether the actor satisfies the rules that the transition requires to 
	be true for the transition to occur.
	
	Transitions do not need to know what states they lead from or into, only whether they can
	occur or not.
	*/
private:
	//the rules that must be satisfied in order for the transition to occur
	//stores actual TransitionRule objects
	std::vector<TransitionRuleBase*> transitionRules; 
public:
	Transition() {} //default constructor
	Transition(const Transition& srcTransition) //copy constructor
	{
		transitionRules = srcTransition.transitionRules; //copies vector data, should be safe
	}
	~Transition()
	{
		while (!transitionRules.empty())
		{
			delete transitionRules.back();
			transitionRules.pop_back();
		}
	}
	
	
	/*
	Adds a rule for this transition to happen.
	@example:
	vvvvvvvvvvvvvvvvvvvvvvv
	Transition walkToJump;
	walkToJump.addTransitionRule(TransitionRule(actor.isOnGround(), false));
	vvvvvvvvvvvvvvvvvvvvvvv
	Creates a transition walkToJump with the rule that the actor must be off the ground
	in order for the transition to occur.
	*/
	template<class ComponentType, typename compareType>
	void addTransitionRule(TransitionRule<ComponentType, compareType> rule);


	//returns whether the actor can transition or not according to the transition rules.
	bool canTransition(Actor& actor);

	Transition& operator=(const Transition& srcTransition);
};









#endif