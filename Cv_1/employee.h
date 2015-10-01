#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structs.h"
#include "utils.h"


Employee *createEmployee(const char *name, GENDER gender, unsigned int birth, double salary, unsigned int personalNumber);

void printEmployeeInfo(const Employee *employee);

void updateEmployeeName(Employee *employee, const char* name);

void freeEmployee(Employee *employee);


#endif
