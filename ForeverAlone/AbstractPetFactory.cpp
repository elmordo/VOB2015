#include "AbstractPetFactory.h"


AbstractPetFactory::AbstractPetFactory()
{
}


AbstractPetFactory::~AbstractPetFactory()
{
}

IPetFactory *AbstractPetFactory::createFactory(FACTORY_TYPE type)
{
	switch (type)
	{
	case CAT_FACTORY:
		return new CatFactory();
		break;

	case DOG_FACTORY:
		return new DogFactory();
		break;
	}

	return NULL;
}
