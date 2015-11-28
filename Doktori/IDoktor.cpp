#include "IDoktor.h"


IDoktor::IDoktor()
{
	numberOfPatients = 0;
}

IDoktor::IDoktor(const IDoktor &original)
{
	numberOfPatients = original.numberOfPatients;
}

IDoktor::~IDoktor()
{
}

int IDoktor::getNumberOfPatient() const
{
	return numberOfPatients;
}

void IDoktor::incrementNumberOfPatient()
{
	++numberOfPatients;
}