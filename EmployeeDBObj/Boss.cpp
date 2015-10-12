#include "Boss.h"


Boss::Boss()
{
	department = "Jidelna";
	secretary = false;
}

Boss::Boss(const string &name, uint year, double salary, uint pn, GENDER sex, const string &dep, bool sec) 
	: Employee(name, year, salary, pn, sex)
{
	department = dep;
	secretary = sec;
}

Boss::Boss(const Boss &original) : Employee(original)
{
	department = original.department;
	secretary = original.secretary;
}

Boss::~Boss()
{
}

string Boss::getDepartment() const
{
	return department;
}

void Boss::setDepartment(const string &val)
{
	department = val;
}

bool Boss::getSecretary() const
{
	return secretary;
}

void Boss::setSecretary(bool val)
{
	secretary = val;
}

void Boss::fireEmployee(EmpDb &db, uint pn)
{
	db.deleteEmployee(pn);
}

void Boss::changeSalary(EmpDb &db, uint pn, double newSalary)
{
	db.find(pn)->setSalary(newSalary);
}

void Boss::hireNewEmployee(EmpDb &db, Employee *emp)
{
	db.addEmployee(emp);
}

