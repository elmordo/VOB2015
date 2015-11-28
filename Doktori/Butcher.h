#pragma once
#include "IDoktor.h"
class Butcher :
	public IDoktor
{
public:
	Butcher();

	virtual ~Butcher();

	virtual void visitMe(IVisitor *visitor);
};

