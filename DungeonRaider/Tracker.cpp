#include "Tracker.h"
#include "Tracked.h"

Tracker::Tracker(Tracked* subject) : subject_(subject)
{
	if (subject_)
	{
		subject_->addObserver(this);
	}
}
Tracker::Tracker(const Tracker& tracker) : subject_(tracker.subject_)
{
	if (subject_)
	{
		subject_->addObserver(this);
	}
}
Tracker::~Tracker()
{
	if (subject_)
	{
		subject_->removeObserver(this);
	}
}

void Tracker::setNewSubject(Tracked* newSubject)
{
	if (subject_)
	{
		subject_->removeObserver(this);
	}
	subject_ = newSubject;
	if (subject_)
	{
		subject_->addObserver(this);
	}
}