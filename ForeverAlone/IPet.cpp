#include "IPet.h"


IPet::IPet()
{
}


IPet::~IPet()
{
}

string IPet::getName() const
{
	return name;
}

void IPet::setName(const string &name)
{
	this->name = name;
}
