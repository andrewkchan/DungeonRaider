#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

//fwd declarations
class Observer;
class Actor;
class Event;

/*
class Subject

A base class for things that need to keep track of observers and notify them of some event.
*/
/*
class Subject
{
private:
	std::vector<Observer*>observers_;
public:
	Subject(){}
	virtual ~Subject(){} //don't delete the observers themselves

	void addObserver(Observer* observer)
	{
		observers_.push_back(observer);
	}
	void removeObserver(Observer* observer)
	{
		for (unsigned int i = 0; i < observers_.size(); i++)
		{
			if (observers_.at(i) == observer)
			{
				observers_.erase(observers_.begin() + i);
			}
		}
	}
	virtual void notify(const Actor& actor, Event event)
	{
		for (unsigned int i = 0; i < observers_.size(); i++)
		{
			observers_.at(i)->onNotify(actor, event);
		}
	}
};
*/




#endif