#pragma once
#include "IDoktor.h"
class Common :
	public IDoktor
{
public:
	Common();

	virtual ~Common();

	virtual void visitMe(IVisitor *visitor);
};

