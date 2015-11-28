#include "Dentist.h"
#include "IVisitor.h"

Dentist::Dentist()
{
}


Dentist::~Dentist()
{
}

void Dentist::visitMe(IVisitor *visitor)
{
	visitor->apply(this);
}
