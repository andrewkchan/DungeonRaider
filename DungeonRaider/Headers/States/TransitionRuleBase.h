#ifndef TRANSITIONRULEBASE_H
#define TRANSITIONRULEBASE_H


//fwd declarations of dependencies
class Actor;

class TransitionRuleBase
{
	/*
	Class TransitionRuleBase

	A base class developed specifically for easy storage of
	TransitionRule<> templates of different types.
	*/
private:
public:
	TransitionRuleBase() {}
	virtual ~TransitionRuleBase() {}

	virtual bool isSatisfied(Actor& actor) { return true; }
};






#endif