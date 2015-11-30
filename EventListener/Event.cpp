#include "Event.h"


Event::Event()
{
	stopFlag = false;
	sender = 0x0;
}

Event::Event(void *sender, string data)
{
	this->data = data;
	this->sender = sender;
	stopFlag = false;
}

Event::Event(const Event &original)
{
	data = original.data;
	sender = original.sender;
	stopFlag = original.stopFlag;
}

Event::~Event()
{
}

bool Event::getStopFlag() const
{
	return stopFlag;
}

void Event::setStopFlag(bool val)
{
	stopFlag = val;
}

string Event::getData() const
{
	return data;
}

void *Event::getSender()
{
	return sender;
}
