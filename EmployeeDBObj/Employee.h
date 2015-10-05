#pragma once

#include <string>

#include "base.h"

using namespace std;


class Employee
{
public:

	/**
	 * @brief specify gender of employee
	 */
	enum GENDER
	{
		MALE,
		FEMALE,
	};

private:
	
    /**
     * @brief employee name
     */
	string name;

    /**
     * @brief year of birth
     */
	uint year;

    /**
     * @brief how much we pay him/her?
     */
	double salary;

    /**
     * @biref unique personal number
     */
	uint personalNumber;

    /**
     * @brief man or woman?
     */
	GENDER sex;

public:

    /**
     * @brief create instance with default values
     */
	Employee();

    /**
     * @brief create instance with given data
     * @param name name of employee
     * @param year year of birth
     * @param salary how much we pay him/her?
     * @param pn personal number
     * @param sex woman or man
     */
	Employee(const string &name, uint year, double salary, uint pn, GENDER sex);

    /**
     * @param copytor
     */
	Employee(const Employee &original);

    /**
     * @param destructor (do nothing)
     */
	virtual ~Employee();

    /**
     * @brief name accessor
     * @return name of employee
     */
	string getName() const;

    /**
     * @biref set new name to employee
     * @param val new name to set
     */
	void setName(const string &val);

    /**
     * @brief year of birth accessor
     * @return year of birth
     */
	uint getYear() const;

    /**
     * @brief set new year of birth
     * @param val new year of birth
     */
	void setYear(uint val);

    /**
     * @brief salary accessor
     * @return salary
     */
	double getSalary() const;

    /**
     * @brief set new salary
     * @brief val new salary to set
     */
	void setSalary(double val);

    /**
     * @brief personal number accessor
     * @return current personal number
     */
	uint getPersonalNumber() const;

    /**
     * @brief set new personal number
     * @param val new parsonal number to set
     */
	void setPersonalNumber(uint val);

    /**
     * @brief gender accessor
     * @return MALE or FEMALE
     */
	GENDER getSex() const;

    /**
     * @brief set new gender (surgery heh?)
     * @param val new gender
     */
	void setSex(GENDER val);

};

