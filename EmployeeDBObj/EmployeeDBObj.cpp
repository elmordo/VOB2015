// EmployeeDBObj.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"
#include "EmpDb.h"

using namespace std;

char getAction()
{
	cout << "Co chces delat?" << endl;
	cout << "1 - pridat zamestnance" << endl;
	cout << "2 - vypis vse" << endl;
	cout << "0 - konec" << endl;

	char action;
	cin >> action;

	return action;
}

void addEmp(EmpDb &db)
{
	string name;
	double salary;
	Employee::GENDER sex;
	uint pn;
	uint year;
	char helper;

	cout << "Zadej jmeno: ";
	cin >> name;
	cout << "Plat: ";
	cin >> salary;
	cout << "Rok narozeni: ";
	cin >> year;
	cout << "Osobni cislo: ";
	cin >> pn;

	cout << "Pohlavi (m/z): ";
	cin >> helper;

	if (helper == 'm')
		sex = Employee::MALE;
	else
		sex = Employee::FEMALE;

	db.addEmployee(Employee(name, year, salary, pn, sex));
}

void printAll(const EmpDb &db)
{
	EmpDb::EmpMap lst = db.getAll();

	for (EmpDb::EmpMap::const_iterator pos = lst.cbegin(); pos != lst.cend(); ++pos)
	{
		// print info
		cout << pos->second.getName() << endl;
		cout << pos->second.getYear() << endl;
		cout << pos->second.getSalary() << endl;
		cout << pos->second.getPersonalNumber() << endl;

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	EmpDb db;
	char action;

	do
	{
		action = getAction();

		switch (action)
		{
		case '1':
			addEmp(db);
			break;

		case '2':
			printAll(db);
			break;
		}
	} while (action != '0');

	return 0;
}

