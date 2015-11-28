#include "Butcher.h"
#include "IVisitor.h"


Butcher::Butcher()
{
}


Butcher::~Butcher()
{
}

void Butcher::visitMe(IVisitor *visitor)
{
	visitor->apply(this);
}
