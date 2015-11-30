// EventListener.cpp : Defines the entry point for the console application.
//
#include <cstdio>
#include "stdafx.h"

#include "Event.h"
#include "EventDispatcher.h"
#include "TextPriner.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	EventDispatcher dispatcher;
	Event e(0x0, "Hello world");

	dispatcher.addEventListener(new TextPrinter());
	dispatcher.addEventListener(new TextPrinter());
	dispatcher.addEventListener(new TextPrinter());
	dispatcher.dispatchEvent(e);

	getchar();

	return 0;
}

