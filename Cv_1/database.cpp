#include "database.h"


ListItem *findItem(ListItem *first, unsigned int personalNumber, ListItem **previous)
{
	ListItem *needle = NULL;
	*previous = 0x0;

	while (first && !needle)
	{
		if (first->employee->personalNumber == personalNumber)
		{
			needle = first;
		}
		else
		{
			*previous = first;
			first = first->next;
		}
	}

	return needle;
}

EmployeeList *createDatabase()
{
	EmployeeList *db = (EmployeeList*)malloc(sizeof(EmployeeList));

	db->first = NULL;
	db->length = 0;

	return db;
}

Employee *createEmployeeRecord(EmployeeList *database, const char *name, GENDER gender, unsigned int birth, double salary, unsigned int personalNumber)
{
	Employee *employee = createEmployee(name, gender, birth, salary, personalNumber);
	ListItem *item = (ListItem*)malloc(sizeof(ListItem));

	item->next = database->first;
	item->employee = employee;

	database->first = item;
	++database->length;

	return employee;
}

int dropEmployee(EmployeeList *database, unsigned int personalNumber)
{
	ListItem *previous;
	ListItem *item = findItem(database->first, personalNumber, &previous);

	if (!item)
	{
		return 1;
	}

	if (previous)
	{
		previous->next = item->next;
	}
	else
	{
		database->first = item->next;
	}

	freeEmployee(item->employee);
	free(item);

	--database->length;

	return 0;
}

void freeDatabase(EmployeeList *database)
{
	// free employees
	ListItem *backup;

	while (database->first != NULL)
	{
		backup = database->first->next;
		free(database->first);
		database->first = backup;
	}

	free(database);
}

Employee *findByPersonalNumber(EmployeeList *database, unsigned int pn)
{
	Employee *emp = NULL;
	ListItem *item = database->first;

	while (!emp && item)
	{
		if (item->employee->personalNumber == pn)
		{
			emp = item->employee;
		}

		item = item->next;
	}

	return emp;
}

unsigned int getNumberOfEmployees(EmployeeList *database)
{
	return database->length;
}

ListItem *getFirstItem(EmployeeList *database)
{
	return database->first;
}

ListItem *getNextItem(ListItem *item)
{
	return item->next;
}

Employee *getEmployee(ListItem *item)
{
	return item->employee;
}
