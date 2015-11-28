#include "Audit.h"
#include "Dentist.h"
#include "Common.h"
#include "Butcher.h"


Audit::Audit()
{
}


Audit::~Audit()
{
}

void Audit::apply(Dentist *dentist)
{
	cout << "Zubar vytrhl " << dentist->getNumberOfPatient() 
		<< " zubu" << endl;
}

void Audit::apply(Common *common)
{
	cout << "Obvodak pichl " << common->getNumberOfPatient()
		<< " tetanovek" << endl;
}

void Audit::apply(Butcher *butcher)
{
	cout << "Reznik zabil " << butcher->getNumberOfPatient()
		<< " pacientu" << endl;
}
