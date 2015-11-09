#include "DogFactory.h"


DogFactory::DogFactory()
{
}


DogFactory::~DogFactory()
{
}

IPet *DogFactory::createPet(const string &name)
{
	allocator<Dog> dogAlloc;
	Dog *dog = dogAlloc.allocate(1);
	dogAlloc.construct(dog);

	dog->setName(name);

	return dog;
}
