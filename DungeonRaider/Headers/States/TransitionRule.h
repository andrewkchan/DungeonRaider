#ifndef TRANSITIONRULE_H
#define TRANSITIONRULE_H


//fwd declarations
class Actor;

#include "Comparer.h"
#include "TransitionRuleBase.h"

template<class ComponentType, typename compareType>
class TransitionRule : public TransitionRuleBase
{
	/*
	Class TransitionRule
	
	This class defines a boolean rule that an actor must satisfy in order to
	undergo a state transition. The transitions that a state holds must always
	have at least 1 transition rule.
	
	Since TransitionRule is a template, we cannot store it normally in an std::vector. We have to make
	it inherit a non-templated base class (TransitionRuleBase), and make an std::vector of pointers to 
	that base class.
	*/
private:
	//the value that some attribute of the actor must satisfactorily compare to
	compareType _compareToThis;


	//NOTE: the below is a POINTER TO MEMBER FUNCTION (not pointer to regular function)
	//this means that it holds the relative memory address of a function
	//and can therefore be used to call member functions of class instances
	//NOTE2: The typedef defines the POINTER TO MEMBER FUNCTION of class ComponentType,
	//with return type compareType as "ComponentGetterPtr" (yes, the grammar is very confusing)
	typedef compareType(ComponentType::*ComponentGetterPtr)();

	//a pointer to the getter function for the actor value we want to compare
	//for example, we can assign this to &HealthComponent::getHealth
	//and we can then attach _getter to some instance of a HealthComponent
	//and call it to get the actor's health.
	ComponentGetterPtr _getterPtr;
	
	//NOTE: the below is a POINTER TO A MEMBER OBJECT
	//this way the pointer to the member function knows WHICH DAMN COMPONENT of the actor to call the function from
	//again, this holds relative memory addresses, and can be used to access instance members
	//NOTE2: The typedef defines a pointer to actor's member of type ComponentType as "ComponentPtr"
	typedef ComponentType(Actor::*ComponentPtr);

	ComponentPtr _componentPtr;

	Comparer comparisonOperator;
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
	virtual ~TransitionRule()
	{
		//don't try to delete pointers to members!
		_getterPtr = 0;
		_componentPtr = 0;
	}

	/*
	Constructor for a rule that compares values of type compareType from classes of type ComponentType.
	ComponentPtr is a pointer to the component from which the member function getterToCompare() will be called.
	ComponentGetterPtr is a pointer to the getter function that returns the value to be compared.
	TransitionRule::Comparer is an enum that denotes the comparison type.
	compareType compareToThis is the value that the comparison must satisfy.
	===
	@example:
	===
	TransitionRule<MotionComponent, float>(&Actor::MotionComponent, &MotionComponent::getSpeed(), GREATER_THAN_EQUALS, 1.2) 
	creates a transition rule where the actor's speed must be greater than or equal to 1.2 in order to satisfy the rule.

	----NOTE----
	The types being compared must have comparison operators ==,!=,<=,>=,<,> defined for them, otherwise
	TransitionRule::isSatisfied() will produce undefined behaviour.
	*/
	TransitionRule(ComponentPtr componentPtr, ComponentGetterPtr getterFunctionPtr, 
		Comparer inputOperator, compareType compareToThis) :
		comparisonOperator(inputOperator), _componentPtr(componentPtr), _getterPtr(getterFunctionPtr),
		_compareToThis(compareToThis)
	{}
	/*
	Constructor for a rule that compares with EQUALS only. Use this constructor for bool values.
	ComponentPtr is a pointer to the component from which the member function getterToCompare() will be called.
	ComponentGetterPtr is a pointer to the getter function that returns the value to be compared.
	TransitionRule::Comparer is an enum that denotes the comparison type.
	compareType compareToThis is the value that the comparison must satisfy.
	===
	@example:
	===
	TransitionRule<MotionComponent, bool>(&Actor::MotionComponent, &MotionComponent::isOnGround(), false) 
	creates a transition rule where the actor must be off the ground in order to satisfy the rule.

	---NOTE---
	The types being compared must have the comparison operator == defined for them, otherwise
	TransitionRule::isSatisfied() will produce undefined behaviour.
	*/
	TransitionRule(ComponentPtr componentPtr, ComponentGetterPtr getterFunctionPtr, compareType compareToThis) :
		comparisonOperator(EQUALS), _componentPtr(componentPtr), 
		_getterPtr(getterFunctionPtr), _compareToThis(compareToThis)
	{}

	/*
	Returns whether the transition rule has been satisfied or not for the specified actor.
	*/
	virtual bool isSatisfied(Actor& actor)
	{
		compareType valueToCompare = ((actor.*_componentPtr).*_getterPtr)(); 
		//call the getter function in the actor instance to get the value to compare


		switch (comparisonOperator)
		{
		case EQUALS:
		{
			return valueToCompare == _compareToThis;
		}
		case NOT_EQUALS:
		{
			return valueToCompare != _compareToThis;
		}
		case GREATER_THAN:
		{
			return valueToCompare > _compareToThis;
		}
		case LESS_THAN:
		{
			return valueToCompare < _compareToThis;
		}
		case GREATER_THAN_EQUALS:
		{
			return valueToCompare >= _compareToThis;
		}
		case LESS_THAN_EQUALS:
		{
			return valueToCompare <= _compareToThis;
		}
		}

		//if something above goes wrong, eh just let the actor transition
		return true;
	}
};





#endif