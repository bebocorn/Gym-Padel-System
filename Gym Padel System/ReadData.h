#pragma once
#include<iostream>
using namespace std;


// For Reading Only
class ReadData
{
public:
	static string getName(int number);
	static int getDuration(int number);
	static int getDuration(string planName);
	static int getPrice(int number);
	static int getPrice(string planName);
	static string getWorkout(int id);
	static int getVipPrice();
	
};