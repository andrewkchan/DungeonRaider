#ifndef FLOATVALUEDISPLAYTEXT_H
#define FLOATVALUEDISPLAYTEXT_H


#include "TextComponent.h"
#include <string>


template<class TrackedObjectType>
/*
class FloatValueDisplayText

A text component that tracks and continuously displays a given numerical value belonging to a Tracked subclass.

Template param @TrackedObjectType	-The class that contains the value being tracked (HealthComponent, Actor...)

The numerical value is tracked through a function of the class containing the value. For example, if you want to
track health, template-ize ValueDisplayText for HealthComponents, and construct ValueDisplayText with
the member function pointer &HealthComponent::getHealth() as a parameter. This specifies the "blueprint" for
the type and way that ValueDisplayText will track a value. To begin tracking the value of a specific object,
use FloatValueDisplayText's member function setNewSubject(Tracked*).
*/
class FloatValueDisplayText : public TextComponent
{
private:
	std::string prefix;

	//NOTE: the below is a POINTER TO MEMBER FUNCTION (not pointer to regular function)
	//this means that it holds the relative memory address of a function
	//and can therefore be used to call member functions of class instances
	//NOTE2: The typedef defines the POINTER TO MEMBER FUNCTION of class TrackedObjectType,
	//with float return type as "TrackedAccessorPtr" (yes, the grammar is very confusing)
	typedef float(TrackedObjectType::*TrackedCallback)();

	TrackedCallback trackedCallback;
public:
	/*
	Constructor with params to set the prefix that will be displayed before the actual value.

	Param std::string @prefix				-String to display before displaying the tracked value, ex: "Health:" before health is displayed
	Param TrackedCallback @inputCallback	-A member function pointer accessing the value to be tracked, ex: "&HealthComponent::getHealth()" to track health

	The given member function pointer must (obviously) refer to a member function of the templated class TrackedObjectType.
	*/
	FloatValueDisplayText(const sf::Font& font, const std::string& inputPrefix = "value:", TrackedCallback inputCallback = 0) :
		TextComponent(font),
		prefix(inputPrefix),
		trackedCallback(inputCallback)
	{}

	void setPrefix(const std::string& inputPrefix)
	{
		prefix = inputPrefix;
	}
	/*
	Set a new accessor for the value to display.
	*/
	void setValueCallback(TrackedCallback inputCallback)
	{
		trackedCallback = inputCallback;
	}
	virtual void update(float frameTime, GUIEntity& entity)
	{
		TextComponent::update(frameTime, entity);
		TrackedObjectType* T = dynamic_cast<TrackedObjectType*>(Tracker::getSubject());
		if (T)
		{
			TextComponent::setString(
				prefix +
				std::to_string((T->*trackedCallback)())
				);
		}
		
	}
};




#endif