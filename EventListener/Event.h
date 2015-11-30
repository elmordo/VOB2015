#pragma once

#include <string>

using namespace std;


class Event
{

	void *sender;

	string data;

	bool stopFlag;

public:

	Event();

	Event(void *sender, string data);

	Event(const Event &original);

	virtual ~Event();

	bool getStopFlag() const;

	void setStopFlag(bool val);

	string getData() const;

	void *getSender();

};

