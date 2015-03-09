#ifndef TRACKER_H
#define TRACKER_H

//fwd declarations
class Tracked;

/*
Class Observer

This base class 'observes' (contains a pointer to) a Subject and ensures that all moves of the Subject in memory are accounted for.
*/
class Tracker
{
private:
	Tracked* subject_;
public:
	Tracker(Tracked* subject = 0);
	Tracker(const Tracker& tracker);
	virtual ~Tracker();

	void setNewSubject(Tracked* newSubject);

	//to be called by the Tracked object when it changes location
	void notifyMove(Tracked* newLoc)
	{
		subject_ = newLoc;
	}
	//get the subject that is currently being tracked
	Tracked* getSubject()
	{
		return subject_;
	}

};






#endif