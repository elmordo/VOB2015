#pragma once
#include "AbstractPetDecorator.h"
class HtmlSound :
	public AbstractPetDecorator
{
public:
	HtmlSound();
	virtual ~HtmlSound();

	virtual string makeSound() const;
};

