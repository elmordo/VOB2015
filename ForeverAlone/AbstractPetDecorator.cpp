#include "AbstractPetDecorator.h"


AbstractPetDecorator::AbstractPetDecorator()
{
	parent = NULL;
}


AbstractPetDecorator::~AbstractPetDecorator()
{
}

IPet *AbstractPetDecorator::getParent() const
{
	return parent;
}

void AbstractPetDecorator::setParent(IPet *parent)
{
	this->parent = parent;
}

string AbstractPetDecorator::getName() const
{
	return parent->getName();
}
