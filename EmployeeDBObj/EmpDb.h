#pragma once

#include <map>
#include <memory>
#include <exception>   // we have to throw exception when no employee found in non-const find

#include "Employee.h"


using namespace std;

/**
 * @brief employee database
 */
class EmpDb
{
public:
    
    /**
     * @brief store employess and index them by their personal numbers
     */
	typedef std::map<uint, Employee*> EmpMap;

	typedef std::allocator<Employee> EmpAlloc;

private:

    /**
     * @brief employee container
     */
	EmpMap employees;

public:

    /**
     * @brief create empty database
     */
	EmpDb();

    /**
     * @brief copy given database
     * @param original database with data
     */
	EmpDb(const EmpDb &original);

    /**
     * @brief do nothing
     */
	virtual ~EmpDb();

    /**
     * @brief add copy of given employee into database
     * @param emp employee to add
     */
	void addEmployee(Employee *emp);

    /**
     * @brief remove employee with given personal number
     *      if no employee found, shit happend
     * @param pn personal number of employee
     */
	void deleteEmployee(uint pn);

    /**
     * @brief remove all employees from database
     */
	void deleteAll();

    /**
     * @brief find emplyoee by its personal number
     * @param pn personal number
     * @return copy of employee
     * @throw exception no employee found
     */
	const Employee *find(uint pn) const;

    /**
     * @brief find emplyoee by its personal number
     * @param pn personal number
     * @return reference to employee
     * @throw exception no employee found
     */
	Employee *find(uint pn);

    /**
     * @brief copy internal storage
     * @return copy of internal map
     */
	EmpMap getAll() const;

};

