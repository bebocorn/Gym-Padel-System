#include "Subscription.h"

Subscription::Subscription() {}

Subscription::Subscription(string Name, Date EndDate)
{
	name = Name;
	endDate = EndDate;
}

void Subscription::setPlanName(string Name)
{
	name = Name;
}

void Subscription::setPlan(const Subscription& subscription)
{
	name = subscription.name;
	endDate = subscription.endDate;
}

void Subscription::setEndDate(const Date& EndDate)
{
	endDate = EndDate;
}

// When Member Subscribe
void Subscription::calcEndDate()
{
	endDate = Date::extendBy(Date::getTodaysDate(), ReadData::getDuration(name) / 30);
}

string Subscription::getName() const
{
	return name;
}

Date Subscription::getEndDate() const
{
	return endDate;
}

void Subscription::extendPlan(string planName)
{
	endDate = Date::extendBy(endDate, ReadData::getDuration(planName) / 30);
}

void Subscription::cancelPlan()
{
	name = "";
	endDate = Date::getTodaysDate();
}

bool Subscription::operator==(const Subscription& subscription) const
{
	return name == subscription.name and
		endDate == subscription.endDate;
}