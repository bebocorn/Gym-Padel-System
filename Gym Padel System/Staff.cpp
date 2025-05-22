#include "Staff.h"

Staff::Staff() : ID(0), salary(0) {}

Staff::Staff(string firstName, string middleName, string lastName, Date dob, int id, int Salary) : Person(firstName, middleName, lastName, dob)
{
	ID = id;
	salary = Salary;
}

int Staff::getID() const
{
	return ID;
}

int Staff::getSalary() const
{
	return salary;
}

void Staff::setID(int id)
{
	ID = id;
}

void Staff::setSalary(int Salary)
{
	salary = Salary;
}