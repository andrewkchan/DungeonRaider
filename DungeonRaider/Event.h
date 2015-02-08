#ifndef EVENT_H
#define EVENT_H


/*
class Event

A (safe) enum wrapper that allows various things to have completely unique associated IDs, while allowing
copies of those things to have the same IDs as the original.

Events can be added during runtime.
*/
class Event
{
private:
	static int nextID;
	const int ID;

	Event& operator=(const Event& src){} //no assignment, events are const!
public:
	Event() : ID(++nextID) {}
	Event(const Event& src) : ID(src.ID) {}
	virtual ~Event(){}

	friend bool operator==(const Event& event1, const Event& event2);
};

int Event::nextID = 0;

bool operator==(const Event& event1, const Event& event2)
{
	return event1.ID == event2.ID;
}





#endif