#pragma once

#include <memory>

#include "IPetFactory.h"
#include "Cat.h"

using namespace std;

class CatFactory :
	public IPetFactory
{
public:
	CatFactory();
	virtual ~CatFactory();

	virtual IPet *createPet(const string &name);

};

