#ifndef DATA_STRUCTS_H
#define DATA_STRUCTS_H


enum GENDER
{
	MALE,
	FEMALE
};


struct Employee
{

	/**
	* @brief employee name
	*/
	char *name;

	/**
	* @brief male or female?
	*/
	GENDER gender;

	/**
	* @brief year of birth
	*/
	unsigned int birth;

	/**
	* @brief how much we pay him?
	*/
	double salary;

	/**
	* @brief personal number
	*/
	unsigned int personalNumber;

};


struct ListItem
{

	/**
	* @brief next item. For the last item, value is NULL
	*/
	ListItem *next;

	/**
	* @brief stored employee instance
	*/
	Employee *employee;

};


struct EmployeeList
{

	ListItem *first;

	unsigned int length;

};

#endif
