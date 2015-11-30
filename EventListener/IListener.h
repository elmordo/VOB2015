#pragma once

#include "Event.h"

class IListener
{
public:

	IListener();

	virtual ~IListener();

	virtual void handle(Event &e) = 0;

};

