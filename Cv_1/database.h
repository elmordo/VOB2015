
#ifndef DATABASE_H
#define DATABASE_H

#include "stdlib.h"
#include "stdio.h"

#include "employee.h"
#include "data_structs.h"


EmployeeList *createDatabase();

Employee *createEmployeeRecord(EmployeeList *database, const char *name, GENDER gender, unsigned int birth, double salary, unsigned int personalNumber);

int dropEmployee(EmployeeList *database, unsigned int personalNumber);

unsigned int getNumberOfEmployees(EmployeeList *database);

void freeDatabase(EmployeeList *database);

Employee *findByPersonalNumber(EmployeeList *database, unsigned int pn);

ListItem *getFirstItem(EmployeeList *database);

/**
 * @brief return next item
 * @return pointer to next item or null if item is last
 */
ListItem *getNextItem(ListItem *item);

/**
 * @brief return employee stored in item
 * @return pointer to stored employee
 */
Employee *getEmployee(ListItem *item);


#endif