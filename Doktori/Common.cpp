#include "Common.h"
#include "IVisitor.h"

Common::Common()
{
}


Common::~Common()
{
}

void Common::visitMe(IVisitor *visitor)
{
	visitor->apply(this);
}
