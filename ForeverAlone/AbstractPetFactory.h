#pragma once

#include "CatFactory.h"
#include "DogFactory.h"

class AbstractPetFactory
{
public:
	
	enum FACTORY_TYPE
	{
		CAT_FACTORY,
		DOG_FACTORY,
	};
	
	AbstractPetFactory();

	virtual ~AbstractPetFactory();

	IPetFactory *createFactory(FACTORY_TYPE type);

};

