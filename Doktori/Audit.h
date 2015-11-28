#pragma once

#include <iostream>

#include "IVisitor.h"

using namespace std;


class Audit :
	public IVisitor
{
public:
	Audit();

	virtual ~Audit();

	virtual void apply(Dentist *dentist);

	virtual void apply(Common *common);

	virtual void apply(Butcher *butcher);
};

