#pragma once

#include <string>
#include <iostream>

using namespace std;


class AppOut
{

	string prefix;

	static AppOut *instance;

	AppOut();

public:

	virtual ~AppOut();

	static AppOut *getInstance();

	static void destroyInstance();

	void setPrefix(const string &val);

	void print(const string &msg);

};

