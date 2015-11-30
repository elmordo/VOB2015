#pragma once

#include <list>

#include "IListener.h"
#include "Event.h"

using namespace std;


class EventDispatcher
{
public:

	typedef list<IListener*> ListenerList;

	typedef list<Event> EventQueue;

private:

	ListenerList listeners;

	EventQueue queue;

	bool inProcess;

	void dispatch();

public:
	
	EventDispatcher();

	virtual ~EventDispatcher();

	/**
	 * @brief memory management is delegated to the dispatcher
	 */
	void addEventListener(IListener *listener);

	void removeEventListener(IListener *listener);

	ListenerList getListeners();

	void dispatchEvent(const Event &e);

};

