#include "Patient.h"
#include "Dentist.h"
#include "Common.h"
#include "Butcher.h"


Patient::Patient()
{
}


Patient::~Patient()
{
}

void Patient::apply(Dentist *dentist)
{
	dentist->incrementNumberOfPatient();

	cout << "Huhly huhly" << endl;
}

void Patient::apply(Common *common)
{
	common->incrementNumberOfPatient();

	cout << "au" << endl;
}

void Patient::apply(Butcher *butcher)
{
	butcher->incrementNumberOfPatient();

	cout << "Pacient skapal" << endl;
}
