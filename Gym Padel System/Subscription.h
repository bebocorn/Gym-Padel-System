#pragma once
#include<iostream>
#include "Date.h"
#include"ReadData.h"
using namespace std;


// Basic, Standard, Premium, Ultimate 
class Subscription
{
private:
	string name;
	Date endDate;
public:
	Subscription();
	Subscription(string Name, Date EndDate);

	void setPlanName(string Name);
	void setPlan(const Subscription& subscription);
	void setEndDate(const Date& EndDate);
	void calcEndDate();

	string getName() const;
	Date getEndDate() const;

	void extendPlan(string planName);
	void cancelPlan();

	// Opertor Overloading
	bool operator == (const Subscription& subscription) const;
};