#include "CatFactory.h"


CatFactory::CatFactory()
{
}


CatFactory::~CatFactory()
{
}

IPet *CatFactory::createPet(const string &name)
{
	allocator<Cat> catAlloc;
	Cat *cat = catAlloc.allocate(1);
	catAlloc.construct(cat);

	cat->setName(name);

	return cat;
}