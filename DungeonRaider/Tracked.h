#ifndef TRACKED_H
#define TRACKED_H

#include <vector>
#include "Tracker.h"

/*
class Tracked

A base class for things that are constantly being observed, but need to notify their observers if they change
location.

Subjects NEVER notify observers of events themselves. The observers notify their listeners of events.
*/

class Tracked
{
private:
	std::vector<Tracker*>trackers_;
public:
	Tracked(){}
	Tracked(const Tracked& src)
	{
		trackers_ = src.trackers_;
		for (unsigned int i = 0; i < trackers_.size(); i++)
		{
			trackers_[i]->notifyMove(this);
		}
	}
	virtual ~Tracked() //don't delete the observers themselves, but tell them we can no longer be observed
	{
		for (unsigned int i = 0; i < trackers_.size(); i++)
		{
			trackers_[i]->notifyMove(0);
		}
	}

	void addObserver(Tracker* tracker)
	{
		trackers_.push_back(tracker);
	}
	void removeObserver(Tracker* tracker)
	{
		for (unsigned int i = 0; i < trackers_.size(); i++)
		{
			if (trackers_.at(i) == tracker)
			{
				trackers_.erase(trackers_.begin() + i);
			}
		}
	}

};





#endif