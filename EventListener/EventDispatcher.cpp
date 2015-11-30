#include "EventDispatcher.h"


EventDispatcher::EventDispatcher()
{
	inProcess = false;
}


EventDispatcher::~EventDispatcher()
{
	// destroy all listeners
	for (IListener *listener : listeners)
	{
		delete listener;
	}
}


void EventDispatcher::addEventListener(IListener *listener)
{
	listeners.push_back(listener);
}

void EventDispatcher::removeEventListener(IListener *listener)
{
	// search for listener
	listeners.remove(listener);
	delete listener;
}

EventDispatcher::ListenerList EventDispatcher::getListeners()
{
	return listeners;
}

void EventDispatcher::dispatchEvent(const Event &e)
{
	queue.push_back(e);

	dispatch();
}

void EventDispatcher::dispatch()
{
	if (inProcess == false)
	{
		inProcess = true;

		while (queue.size())
		{
			Event &e = queue.front();

			// copy listener list of listeners (for case when listener list is 
			// changed during event processing)
			ListenerList backup = listeners;
			ListenerList::iterator pos = backup.begin();

			// while some listener is not notified and event propagation is not stopped
			// notify next listener
			while (!e.getStopFlag() && pos != backup.end())
			{
				(*pos)->handle(e);
				++pos;
			}

			queue.pop_front();
		}

		inProcess = false;
	}
}
