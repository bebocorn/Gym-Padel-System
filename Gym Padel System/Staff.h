#pragma once
#include "Person.h"


class Staff : public Person
{
protected:
	int ID;
	int salary;
public:
	Staff();
	Staff(string firstName, string middleName, string lastName, Date dob, int id, int Salary);

	int getID() const;
	int getSalary()const;
	virtual string getRole() const = 0;

	void setID(int id);
	void setSalary(int Salary);
};