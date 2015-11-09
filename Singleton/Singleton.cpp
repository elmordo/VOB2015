// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "AppOut.h"

void print1()
{
	AppOut::getInstance()->print("Ahoj");
}

void print2()
{
	AppOut::getInstance()->print("Nazdar");
}

void print3()
{
	AppOut::getInstance()->print("Cau");
}

int _tmain(int argc, _TCHAR* argv[])
{
	AppOut *out = AppOut::getInstance();

	out->setPrefix(">>> ");

	print1();
	print2();

	out->setPrefix("**** ");

	print3();

	getchar();

	return 0;
}

