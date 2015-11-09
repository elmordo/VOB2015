#pragma once
#include "AbstractPetDecorator.h"
class ShoutSound :
	public AbstractPetDecorator
{
public:
	ShoutSound();

	virtual ~ShoutSound();

	virtual string makeSound() const;

};

