#pragma once
#include "IPet.h"
class AbstractPetDecorator :
	public IPet
{

	IPet *parent;

public:
	
	AbstractPetDecorator();

	virtual ~AbstractPetDecorator();

	IPet *getParent() const;

	void setParent(IPet *parent);

	virtual string getName() const;

};

