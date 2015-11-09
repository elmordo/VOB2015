#pragma once

#include <string>

#include "IPet.h"

using namespace std;

class IPetFactory
{
public:
	IPetFactory();
	virtual ~IPetFactory();

	virtual IPet *createPet(const string &name) = 0;

};

