#pragma once

#include <iostream>
#include "IVisitor.h"

using namespace std;

class Patient :
	public IVisitor
{
public:
	Patient();

	virtual ~Patient();

	virtual void apply(Dentist *dentist);

	virtual void apply(Common *common);

	virtual void apply(Butcher *butcher);
};

