#include "AppOut.h"

AppOut *AppOut::instance = 0x0;

AppOut::AppOut()
{
}


AppOut::~AppOut()
{
}

AppOut *AppOut::getInstance()
{
	if (instance == 0x0)
	{
		instance = new AppOut();
	}

	return instance;
}

void AppOut::destroyInstance()
{
	if (instance)
	{
		delete instance;
	}
}

void AppOut::setPrefix(const string &val)
{
	prefix = val;
}

void AppOut::print(const string &msg)
{
	cout << prefix << msg << endl;
}
