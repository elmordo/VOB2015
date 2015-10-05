#include "EmpDb.h"


EmpDb::EmpDb()
{
    // nothing to do here
    // employee map is initialized by its default constructor
}

EmpDb::EmpDb(const EmpDb &original)
{
    // copy data from original instance
	employees = original.employees;
}


EmpDb::~EmpDb()
{
    // nothing to do here
}

void EmpDb::addEmployee(const Employee &emp)
{
    // add employee into map
    // key is personal number
    // value is employee instance
	employees[emp.getPersonalNumber()] = emp;
}

void EmpDb::deleteEmployee(uint pn)
{
    // search for employee with given pn
	EmpMap::iterator it = employees.find(pn);

    // was employee found?
    // if not, iterator points to "one position after last item"
	if (it != employees.end())
	{
        // remove item from map
		employees.erase(it);
	}
}

void EmpDb::deleteAll()
{
    // clear container with employees
	employees.clear();
}

Employee EmpDb::find(uint pn) const
{
    // get iterator to employee with personalNumber == pn
    // for more information about iterators see
    // http://www.cprogramming.com/tutorial/stl/iterators.html
	EmpMap::const_iterator item = employees.find(pn);

    // if iterator is equal to end (one item after the last item), 
    // employee was not found
	if (item == employees.cend())
	{
        // same behaviour is usualy required (see non-const version below)
		throw exception();
	}

    // return copy of employee
	return item->second;
}

Employee &EmpDb::find(uint pn)
{
    // get iterator to employee with personalNumber == pn
    // for more information about iterators see
    // http://www.cprogramming.com/tutorial/stl/iterators.html
	EmpMap::iterator item = employees.find(pn);

    // if iterator is equal to end (one item after the last item), 
    // employee was not found
	if (item == employees.end())
	{
        // we can not return r-value as reference (see documentation)
        // so we have to throw some expcetion
        // std::exception is used here, but some special exception should be defined
		throw exception();
	}

    // return reference to employee
	return item->second;
}

EmpDb::EmpMap EmpDb::getAll() const
{
    // whole map is copied here
	return employees;
}
