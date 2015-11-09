#pragma once
#include "IPet.h"

class Dog :
	public IPet
{
public:

	Dog();

	virtual ~Dog();

	/**
	 * @brief haf haf
	 * @return string with "haf haf"
	 */
	virtual string makeSound() const;
};

