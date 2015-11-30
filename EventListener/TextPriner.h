#pragma once

#include <iostream>

#include "IListener.h"

using namespace std;


class TextPrinter :
	public IListener
{

public:

	TextPrinter();

	virtual ~TextPrinter();

	virtual void handle(Event &e);

};

