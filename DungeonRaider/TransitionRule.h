#ifndef TRANSITIONRULE_H
#define TRANSITIONRULE_H

#include "Comparer.h"

class TransitionRule
{
	/*
	Class TransitionRule
	
	This class defines a boolean rule that an actor must satisfy in order to
	undergo a state transition. The transitions that a state holds must always
	have at least 1 transition rule.
	
	*/
private:
	float _floatComparer;
	int _intComparer;
	bool _boolComparer;
	void* _toCompare; //the value of the actor that will be compared
	Comparer comparisonOperator;
	enum Type{
		BOOLEAN,
		INTEGER,
		FLOAT
	} comparisonType; //keeps track of how to dereference the void pointer, _toCompare
	TransitionRule() {} //private constructor b/c transition rules must be constructed with parameters
public:
	/*
	Constructor for a rule that compares floats.
	float* toCompare is the actor's float value that will be compared.
	TransitionRule::Comparer is an enum that denotes the comparison type.
	float compareToThis is the float value that the comparison must satisfy.
	@example:
	TransitionRule(actor.getSpeed(), GREATER_THAN_EQUALS, 1.2) creates a transition rule
	where the actor's speed must be greater than or equal to 1.2 in order to satisfy the rule.
	*/
	TransitionRule(float* toCompare, Comparer inputOperator, float compareToThis) :
		comparisonOperator(inputOperator), comparisonType(FLOAT)
	{
		_toCompare = toCompare;
		_floatComparer = compareToThis;
	}
	/*
	Constructor for a rule that compares ints.
	int* toCompare is the actor's float value that will be compared.
	TransitionRule::Comparer is an enum that denotes the comparison type.
	int compareToThis is the int value that the comparison must satisfy.
	@example:
	TransitionRule(actor.getHealth(), LESS_THAN_EQUALS, 20) creates a transition rule
	where the actor's health must be less than or equal to 20 in order to satisfy the rule.
	*/
	TransitionRule(int* toCompare, Comparer inputOperator, int compareToThis) :
		comparisonOperator(inputOperator), comparisonType(INTEGER)
	{
		_toCompare = toCompare;
		_intComparer = compareToThis;
	}
	/*
	Constructor for a rule that compares bools.
	bool* toCompare is the actor's bool value that will be compared.
	bool compareToThis is the bool value that the comparison must satisfy.
	@example:
	TransitionRule(actor.getIsOnGround(), false) creates a transition rule
	where the actor must be off the ground in order to satisfy the rule.
	*/
	TransitionRule(bool* toCompare, bool compareToThis) :
		comparisonType(BOOLEAN)
	{
		_toCompare = toCompare;
		_boolComparer = compareToThis;
	}

	/*
	Returns whether the transition rule has been satisfied or not.
	*/
	bool isSatisfied()
	{
		//VERY UGLY - probably redo this whole system?
		switch(comparisonType)
		{
		case BOOLEAN:
			return *(static_cast<bool*>(_toCompare)) && _boolComparer;
			break;
		case INTEGER:
			switch (comparisonOperator)
			{
			case EQUALS:
				return *(static_cast<int*>(_toCompare)) == _intComparer;
				break;
			case NOT_EQUALS:
				return *(static_cast<int*>(_toCompare)) != _intComparer;
				break;
			case GREATER_THAN:
				return *(static_cast<int*>(_toCompare)) > _intComparer;
				break;
			case LESS_THAN:
				return *(static_cast<int*>(_toCompare)) < _intComparer;
				break;
			case GREATER_THAN_EQUALS:
				return *(static_cast<int*>(_toCompare)) >= _intComparer;
				break;
			case LESS_THAN_EQUALS:
				return *(static_cast<int*>(_toCompare)) <= _intComparer;
				break;
			default:
				//throw an error!
				return false;
				break;
			}
		case FLOAT:
			switch (comparisonOperator)
			{
			case EQUALS:
				return *(static_cast<float*>(_toCompare)) == _floatComparer;
				break;
			case NOT_EQUALS:
				return *(static_cast<float*>(_toCompare)) != _floatComparer;
				break;
			case GREATER_THAN:
				return *(static_cast<float*>(_toCompare)) > _floatComparer;
				break;
			case LESS_THAN:
				return *(static_cast<float*>(_toCompare)) < _floatComparer;
				break;
			case GREATER_THAN_EQUALS:
				return *(static_cast<float*>(_toCompare)) >= _floatComparer;
				break;
			case LESS_THAN_EQUALS:
				return *(static_cast<float*>(_toCompare)) <= _floatComparer;
				break;
			default:
				//throw an error!
				return false;
				break;
			}
		}
		return false;
	}
};





#endif