#include "ReadData.h"


string ReadData::getName(int number)
{
	if (number == 1)
		return "Basic";
	else if (number == 2)
		return "Standard";
	else if (number == 3)
		return "Premium";
	else if (number == 4)
		return "Ultimate";
}

int ReadData::getDuration(int number)
{
	if (number == 1)
		return 30;
	else if (number == 2)
		return 90;
	else if (number == 3)
		return 180;
	else if (number == 4)
		return 360;
}

int ReadData::getDuration(string planName)
{
	if (planName == "Basic")
		return getDuration(1);
	else if (planName == "Standard")
		return getDuration(2);
	else if (planName == "Premium")
		return getDuration(3);
	else if (planName == "Ultimate")
		return getDuration(4);
}

int ReadData::getPrice(int number)
{
	if (number == 1)
		return 100;
	else if (number == 2)
		return 300;
	else if (number == 3)
		return 600;
	else if (number == 4)
		return 1000;
}

int ReadData::getPrice(string planName)
{
	if (planName == "Basic")
		return getPrice(1);
	else if (planName == "Standard")
		return getPrice(2);
	else if (planName == "Premium")
		return getPrice(3);
	else if (planName == "Ultimate")
		return getPrice(4);
}

string ReadData::getWorkout(int id)
{
	if (id == 1)
		return "Cardio Blast";
	else if (id == 2)
		return "Hatha Yoga";
	else if (id == 3)
		return "Tabata Training";
	else if (id == 4)
		return "Full Body Strength";
	else if (id == 5)
		return "Upper/Lower Split";
	else if (id == 6)
		return "Push/Pull/Legs";
	else if (id == 7)
		return "Bicep Blast";
	else if (id == 8)
		return "Tricep Power";
	else if (id == 9)
		return "Back Builder";
	else if (id == 10)
		return "Leg Day";
	return string();
}

int ReadData::getVipPrice()
{
	return 500;
}
