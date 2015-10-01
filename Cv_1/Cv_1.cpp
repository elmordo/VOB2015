// Cv_1.cpp : Defines the entry point for the console application.
//

#include "employee.h"
#include "database.h"

#include <stdio.h>

enum ACTIONS
{
	NEW_EMPLOYEE = 1,
	EDIT_EMPLOYEE,
	DELETE_EMPLOYEE,
	INFO_EMPLOYEE,
	PRINT_ALL,
	END = 0,
};

int mainMenu()
{
	printf("Vyberte co chcete delat: %s", EOL);
	printf("Novy zamestnanec                   %d%s", NEW_EMPLOYEE, EOL);
	printf("Upravit zamestnance                %d%s", EDIT_EMPLOYEE, EOL);
	printf("Smazat zamestance                  %d%s", DELETE_EMPLOYEE, EOL);
	printf("Vypsat informace o zamestnanci     %d%s", INFO_EMPLOYEE, EOL);
	printf("Vypsat vsechny zamestnance         %d%s", PRINT_ALL, EOL);
	printf("Konec                              %d%s%s", END, EOL, EOL);
	printf("Vyber akci: ");

	int action;

	scanf_s("%d", &action);

	return action;
}

Employee *newEmployee(EmployeeList *database)
{
	// read data from user
	char name[1024];
	unsigned int birth, personalNumber;
	double salary;
	char genderOpt[8];
	GENDER gender;

	printf("Jmeno (max 1024 znaku): ");
	scanf_s("%s", name, sizeof(name));

	printf("Rok narozeni: ");
	scanf_s("%u", &birth);

	printf("Osobni cislo: ");
	scanf_s("%u", &personalNumber);

	printf("Plat: ");
	scanf_s("%lf", &salary);

	printf("Pohlavi (m - muz, z - zena): ");
	scanf_s("%s", genderOpt, sizeof(genderOpt));

	switch (genderOpt[0])
	{
	case 'm':
		gender = MALE;
		break;

	case 'z':
		gender = FEMALE;
		break;

	default:
		printf("Chyba: Nezname pohlavi%s", EOL);
		return NULL;
	}

	Employee *emp = createEmployeeRecord(database, name, gender, birth, salary, personalNumber);

	return emp;
}

void printAll(EmployeeList *db)
{
	ListItem *item = getFirstItem(db);

	while (item)
	{
		Employee *emp = getEmployee(item);

		printf("%u %s %s", emp->personalNumber, emp->name, EOL);
		item = getNextItem(item);
	}
}

unsigned int readPersonalNumber()
{
	unsigned int pn;

	printf("Zadejte osobni cislo: ");
	scanf_s("%u", &pn);

	return pn;
}

void removeEmployee(EmployeeList *db)
{
	dropEmployee(db, readPersonalNumber());
}

void printInfo(EmployeeList *db)
{
	Employee *emp = findByPersonalNumber(db, readPersonalNumber());

	if (emp)
	{
		// some employee found
		printEmployeeInfo(emp);
	}
	else
	{
		printf("Zamestnanec nebyl nalezen%s", EOL);
	}
}

void edit(EmployeeList *db)
{
	Employee *emp = findByPersonalNumber(readPersonalNumber());

	if (!emp)
	{
		printf("Zamestnanec nebyl nalezen.%s", EOL);
		return;
	}

	// read data from user
	char name[1024];
	unsigned int birth, personalNumber;
	double salary;
	char genderOpt[8];
	GENDER gender;

	printf("Jmeno (max 1024 znaku): ");
	scanf_s("%s", name, sizeof(name));

	printf("Rok narozeni: ");
	scanf_s("%u", &birth);

	printf("Osobni cislo: ");
	scanf_s("%u", &personalNumber);

	printf("Plat: ");
	scanf_s("%lf", &salary);

	printf("Pohlavi (m - muz, z - zena): ");
	scanf_s("%s", genderOpt, sizeof(genderOpt));

	switch (genderOpt[0])
	{
	case 'm':
		gender = MALE;
		break;

	case 'z':
		gender = FEMALE;
		break;

	default:
		printf("Chyba: Nezname pohlavi%s", EOL);
		return;
	}

	emp->gender = gender;
	emp->salary = salary;
	emp->personalNumber = personalNumber;
	emp->birth = birth;


}

int main(int argc, char** aggv)
{
	EmployeeList *db = createDatabase();
	
	// busy loop of application
	bool stillGoing = true;

	while (stillGoing)
	{
		int action = mainMenu();

		switch (action)
		{
		case NEW_EMPLOYEE:
			newEmployee(db);
			break;

		case EDIT_EMPLOYEE:
			break;

		case DELETE_EMPLOYEE:
			removeEmployee(db);
			break;

		case INFO_EMPLOYEE:
			printInfo(db);
			break;

		case PRINT_ALL:
			printAll(db);
			break;

		case END:
			stillGoing = false;
			break;

		default:
			printf("Neplatna volba%s", EOL);
		}
	}

	// wait for key press
	getchar();

	return 0;
}
