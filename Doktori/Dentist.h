#pragma once
#include "IDoktor.h"
class Dentist :
	public IDoktor
{
public:
	Dentist();
	virtual ~Dentist();

	virtual void visitMe(IVisitor *visitor);
};

