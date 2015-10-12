// EmployeeDBObj.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"
#include "EmpDb.h"
#include "Boss.h"

using namespace std;

char getAction()
{
	cout << "Co chces delat?" << endl;
	cout << "1 - pridat zamestnance" << endl;
	cout << "2 - vypis vse" << endl;
	cout << "3 - pridat sefa" << endl;
	cout << "0 - konec" << endl;

	char action;
	cin >> action;

	return action;
}

void setupEmp(Employee &emp)
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

	emp.setName(name);
	emp.setSalary(salary);
	emp.setPersonalNumber(pn);
	emp.setYear(year);
	emp.setSex(sex);
}

void addEmp(EmpDb &db)
{
	EmpDb::EmpAlloc alloc;
	Employee *emp = alloc.allocate(1);
	alloc.construct(emp);

	setupEmp(*emp);

	db.addEmployee(emp);
}

void addBoss(EmpDb &db)
{
	allocator<Boss> alloc;
	Boss *boss = alloc.allocate(1);
	alloc.construct(boss);

	setupEmp(*boss);

	cout << "Oddeleni ktere trpi krutovladou: ";
	string department;
	cin >> department;

	boss->setDepartment(department);

	cout << "Ma sekretarku? (ano, ne) ";
	string sec;
	cin >> sec;

	if (sec == "ano")
	{
		boss->setSecretary(true);
	}

	db.addEmployee(boss);
}

void printAll(const EmpDb &db)
{
	EmpDb::EmpMap lst = db.getAll();

	for (EmpDb::EmpMap::const_iterator pos = lst.cbegin(); pos != lst.cend(); ++pos)
	{
		// print info
		cout << "Jmeno: " << pos->second->getName() << endl;
		cout << "Rok narozeni: " << pos->second->getYear() << endl;
		cout << "Plat: " << pos->second->getSalary() << endl;
		cout << "PN: " << pos->second->getPersonalNumber() << endl;

		cout << "Typ: ";

		if (dynamic_cast<Boss*>(pos->second) != NULL)
		{
			cout << "Velky zly sef";
		}
		else
		{
			cout << "Chudak bezvyznamny a nahraditelny zamestnanec";
		}

		cout << endl;

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

		case '3':
			addBoss(db);
			break;
		}
	} while (action != '0');

	return 0;
}

