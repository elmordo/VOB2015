#pragma once

#include "Employee.h"
#include "EmpDb.h"
#include <string>

using namespace std;

class Boss :
	public Employee
{

	string department;

	bool secretary;

public:

	Boss();

	Boss(const string &name, uint year, double salary, uint pn, GENDER sex, const string &dep, bool sec);

	Boss(const Boss &original);

	virtual ~Boss();

	void fireEmployee(EmpDb &db, uint pn);

	void changeSalary(EmpDb &db, uint pn, double newSalary);

	void hireNewEmployee(EmpDb &db, Employee *emp);

	string getDepartment() const;

	void setDepartment(const string &val);

	bool getSecretary() const;

	void setSecretary(bool val);

};

