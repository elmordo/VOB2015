#include "employee.h"


Employee *createEmployee(const char *name, GENDER gender, unsigned int birth, double salary, unsigned int personalNumber)
{
	// allocate data
	Employee *newEmployee = (Employee*)malloc(sizeof(Employee));

	// fill simple data
	newEmployee->gender = gender;
	newEmployee->birth = birth;
	newEmployee->salary = salary;
	newEmployee->personalNumber = personalNumber;

	// copy name
	int nameLength = strlen(name);
	newEmployee->name = (char*)calloc(nameLength + 1, sizeof(char));
	memcpy(newEmployee->name, name, nameLength + 1);

	return newEmployee;
}

void printEmployeeInfo(const Employee *employee)
{
	printf("Informace o zamestnanci%s", EOL);
	printf("-----------------------%s%s", EOL, EOL);
	printf("Zamestnanec  : %s %s", employee->name, EOL);
	printf("Osobni cislo : %u %s", employee->personalNumber, EOL);
	printf("Pohlav       : %s %s", employee->gender == MALE ? "muz" : "zena", EOL);
	printf("Rok narozeni : %u %s", employee->birth, EOL);
	printf("Plat         : %f %s", employee->salary, EOL);
}

void updateEmployeeName(Employee *employee, const char* name)
{
	if (employee->name)
	{
		free(employee->name);
		employee->name = NULL;
	}

	// set new name
	int nameLength = strlen(name);
	employee->name = (char*)calloc(nameLength + 1, sizeof(char));
	memcpy(employee->name, name, nameLength + 1);

}

void freeEmployee(Employee *employee)
{
	free(employee->name);
	free(employee);
}