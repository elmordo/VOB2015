#pragma once
#include "IPet.h"
class Cat :
	public IPet
{
public:
	Cat();

	virtual ~Cat();

	virtual string makeSound() const;
};

