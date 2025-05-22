#pragma once
#include"Staff.h"
#include"FileManager.h"
#include"Messages.h"

class Receptionist : public Staff
{
public:
	Receptionist();
	Receptionist(string firstName, string middleName, string lastName, int id, int Salary);
	static void sendRenewalNoti();
	static void cancelSub(long long memberID);
	static void renewSub(long long memberID);
	static bool addToClass(long long classId, long long memberId);
	static bool removeFromClass(long long index, long long memberId);
	static void addToWaiting(long long classId, long long memberId);
	static void addFirstInWaiting(long long classId);
	static long long getLastMemberId();
	static long long getLastClassId();
	static int applyDiscount(string planName, double rate);
	string getRole() const;
};