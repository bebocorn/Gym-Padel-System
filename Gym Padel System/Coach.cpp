#include "Coach.h"

Coach::Coach() {}

Coach::Coach(string firstName, string middleName, string lastName, string ClassName, Date dob, long long id, unordered_set<long long> AssignedClasses, int Salary) : Staff(firstName, middleName, lastName, dob, id, Salary)
{
	className = ClassName;
	assignedClasses = AssignedClasses;
}

Coach::Coach(string firstName, string middleName, string lastName, int id, int Salary)
{
	fName = firstName;
	mName = middleName;
	lName = lastName;
	ID = id;
	salary = Salary;
}

void Coach::setClassName(string ClassName)
{
	className = ClassName;
}

string Coach::getClassName() const
{
	return className;
}

void Coach::assignClass(long long classId)
{
	assignedClasses.insert(classId);
}

void Coach::unAssignClass(long long classId)
{
	assignedClasses.erase(classId);
}

unordered_set<long long> Coach::getAssignedClasses() const
{
	return assignedClasses;
}

void Coach::clearAssignedClasses()
{
	assignedClasses.clear();
}

string Coach::getRole() const
{
	return "Coach";
}