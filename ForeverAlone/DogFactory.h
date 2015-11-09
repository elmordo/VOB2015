#pragma once

#include <memory>

#include "IPetFactory.h"
#include "Dog.h"

using namespace std;


class DogFactory :
	public IPetFactory
{
public:
	DogFactory();
	virtual ~DogFactory();

	virtual IPet *createPet(const string &name);
};

