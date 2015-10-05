#include "Employee.h"


Employee::Employee()
{
    // set default values to members
	name = "Jezis Kristus";
	year = 1;
	salary = 0.0;
	personalNumber = 666;
	sex = MALE;
}

Employee::Employee(const string &name, uint year, double salary, uint pn, GENDER sex)
{
    // set given values to members
    // we have name conflicts, so use of `this` is necessary
	this->name = name;
	this->year = year;
	this->salary = salary;
	personalNumber = pn;
	this->sex = sex;
}

Employee::Employee(const Employee &original)
{
    // copy data from original instance
    // orignal is passed as reference so we can use . (dot)
	name = original.name;
	year = original.year;
	salary = original.salary;
	personalNumber = original.personalNumber;
	sex = original.sex;
}

Employee::~Employee()
{
    // nothing to do here
}

string Employee::getName() const
{
	return name;
}

void Employee::setName(const string &val)
{
	name = val;
}

uint Employee::getYear() const
{
	return year;
}

void Employee::setYear(uint val)
{
	year = val;
}

double Employee::getSalary() const
{
	return salary;
}

void Employee::setSalary(double val)
{
	salary = val;
}

uint Employee::getPersonalNumber() const
{
	return personalNumber;
}

void Employee::setPersonalNumber(uint val)
{
	personalNumber = val;
}

Employee::GENDER Employee::getSex() const
{
	return sex;
}

void Employee::setSex(Employee::GENDER val)
{
	sex = val;
}
