#ifndef TRANSITIONRULE_H
#define TRANSITIONRULE_H

#include "Comparer.h"
#include "Component.h"
#include "Actor.h"

class TransitionRule
{
	/*
	Class TransitionRule
	
	This class defines a boolean rule that an actor must satisfy in order to
	undergo a state transition. The transitions that a state holds must always
	have at least 1 transition rule.
	
	*/
private:
	//the value that some attribute of the actor must satisfactorily compare to
	int _compareToThisInt;
	bool _compareToThisBool;
	float _compareToThisFloat;

	//NOTE: the below are POINTERS TO MEMBER FUNCTIONS (not pointers to regular functions)
	//this means that they hold the relative memory address of a function
	//and can therefore be used to call member functions of class instances
	int (Component::*_intFunctionToCompare)(); //points to int getter for a component (variable name="intFunctionToCompare")
	bool (Component::*_boolFunctionToCompare)(); //points to bool getter for a component (var name="boolFunctionToCompare")
	float (Component::*_floatFunctionToCompare)(); //points to float getter for a component (var name="floatFunctionToCompare")
	
	//NOTE: the below is a POINTER TO A MEMBER OBJECT
	//this way the pointer to the member function knows WHICH DAMN COMPONENT of the actor to call the function from
	//again, this holds relative memory addresses, and can be used to access instance members
	Component (Actor::*_component);

	Comparer comparisonOperator;
	enum Type{
		BOOLEAN,
		INTEGER,
		FLOAT
	} comparisonType; //keeps track of how to dereference the void pointer, _toCompare
	TransitionRule() {} //private constructor b/c transition rules must be constructed with parameters
public:
	TransitionRule(const TransitionRule& srcRule) //copy constructor
	{
		comparisonType = srcRule.comparisonType;
		comparisonOperator = srcRule.comparisonOperator;

		switch (comparisonType)
		{
		case BOOLEAN:
			_compareToThisBool = srcRule._compareToThisBool;
			_boolFunctionToCompare = srcRule._boolFunctionToCompare;
			break;
		case INTEGER:
			_compareToThisInt = srcRule._compareToThisInt;
			_intFunctionToCompare = srcRule._intFunctionToCompare;
			break;
		case FLOAT:
			_compareToThisFloat = srcRule._compareToThisFloat;
			_floatFunctionToCompare = srcRule._floatFunctionToCompare;
			break;
		default:
			//this is a problem.
			break;
		}

		_component = srcRule._component;
	}

	/*
	Constructor for a rule that compares floats.
	Component (Actor::*component) is a pointer to the component from which the member function getterToCompare() will be called.
	float (Component::*getterToCompare)() is a pointer to the getter function that returns the value to be compared.
	TransitionRule::Comparer is an enum that denotes the comparison type.
	float compareToThis is the float value that the comparison must satisfy.
	@example:
	TransitionRule(&Actor::MotionComponent, &MotionComponent::getSpeed(), GREATER_THAN_EQUALS, 1.2) creates a transition rule
	where the actor's speed must be greater than or equal to 1.2 in order to satisfy the rule.
	*/
	TransitionRule(Component (Actor::*component), float (Component::*getterToCompare)(), 
		Comparer inputOperator, float compareToThis) :
		comparisonOperator(inputOperator), comparisonType(FLOAT)
	{
		_component = component;
		_floatFunctionToCompare = getterToCompare;
		_compareToThisFloat = compareToThis;
	}
	/*
	Constructor for a rule that compares ints.
	Component (Actor::*component) is a pointer to the component from which the member function getterToCompare() will be called.
	int (Component::*getterToCompare)() is a pointer to the getter function that returns the value to be compared.
	TransitionRule::Comparer is an enum that denotes the comparison type.
	int compareToThis is the int value that the comparison must satisfy.
	@example:
	TransitionRule(&Actor::HealthComponent, &HealthComponent::getHealth(), LESS_THAN_EQUALS, 20) creates a transition rule
	where the actor's health must be less than or equal to 20 in order to satisfy the rule.
	*/
	TransitionRule(Component (Actor::*component), int (Component::*getterToCompare)(), 
		Comparer inputOperator, int compareToThis) :
		comparisonOperator(inputOperator), comparisonType(INTEGER)
	{
		_component = component;
		_intFunctionToCompare = getterToCompare;
		_compareToThisInt = compareToThis;
	}
	/*
	Constructor for a rule that compares bools.
	Component (Actor::*component) is a pointer to the component from which the member function getterToCompare() will be called.
	bool (Component::*getterToCompare)() is a pointer to the getter function that returns the value to be compared.
	bool compareToThis is the bool value that the comparison must satisfy.
	@example:
	TransitionRule(&Actor::MotionComponent, &MotionComponent::getIsOnGround(), false) creates a transition rule
	where the actor must be off the ground in order to satisfy the rule.
	*/
	TransitionRule(Component (Actor::*component), bool (Component::*getterToCompare)(), 
		bool compareToThis) :
		comparisonType(BOOLEAN)
	{
		_component = component;
		_boolFunctionToCompare = getterToCompare;
		_compareToThisBool = compareToThis;
	}

	/*
	Returns whether the transition rule has been satisfied or not for the specified actor.
	*/
	bool isSatisfied(Actor& actor)
	{
		//VERY UGLY - probably redo this whole system?
		switch (comparisonType)
		{
		case BOOLEAN:
		{
			//dereferences the actor's component, then calls _boolFunctionToCompare() on the dereferenced component
			bool valToCompare = (
				actor.*(_component).*(_boolFunctionToCompare)
				)();

			return _compareToThisBool && valToCompare;
			break;
		}
		case INTEGER:
		{
			//dereferences the actor's component, then calls _intFunctionToCompare() on the dereferenced component
			int valToCompare = (
				actor.*(_component).*(_intFunctionToCompare)
				)();
			switch (comparisonOperator)
			{
				
			case EQUALS:
			{
				return _compareToThisInt == valToCompare;
				break;
			}
			case NOT_EQUALS:
			{
				return _compareToThisInt != valToCompare;
				break;
			}
			case GREATER_THAN:
			{
				return _compareToThisInt > valToCompare;
				break;
			}
			case LESS_THAN:
			{
				return _compareToThisInt < valToCompare;
				break;
			}
			case GREATER_THAN_EQUALS:
			{
				return _compareToThisInt >= valToCompare;
				break;
			}
			case LESS_THAN_EQUALS:
			{
				return _compareToThisInt <= valToCompare;
				break;
			}
			default:
			{
				//throw an error!
				return false;
				break;
			}
			}
		}
		case FLOAT:
		{
			//dereferences the actor component, then calls floatFunctionToCompare() on the dereferenced component
			float valToCompare = (
				actor.*(_component).*(_floatFunctionToCompare)
				)();
			switch (comparisonOperator)
			{
			case EQUALS:
			{
				return _compareToThisFloat == valToCompare;
				break;
			}
			case NOT_EQUALS:
			{
				return _compareToThisFloat != valToCompare;
				break;
			}
			case GREATER_THAN:
			{
				return _compareToThisFloat > valToCompare;
				break;
			}
			case LESS_THAN:
			{
				return _compareToThisFloat < valToCompare;
				break;
			}
			case GREATER_THAN_EQUALS:
			{
				return _compareToThisFloat >= valToCompare;
				break;
			}
			case LESS_THAN_EQUALS:
			{
				return _compareToThisFloat <= valToCompare;
				break;
			}
			default:
			{
				//throw an error!
				return false;
				break;
			}
			}
		} //end of case:FLOAT

		}//end of overall switch
		return false;
	}
};





#endif