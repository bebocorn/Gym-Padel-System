#pragma once
#include "Person.h"


class Staff : public Person
{
protected:
	long long ID;
	int salary;
public:
	Staff();
	Staff(string firstName, string middleName, string lastName, Date dob, long long id, int Salary);

	long long getID() const;
	int getSalary()const;
	virtual string getRole() const = 0;

	void setID(long long id);
	void setSalary(int Salary);
};