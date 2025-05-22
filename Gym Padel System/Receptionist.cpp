#include "Receptionist.h"
Receptionist::Receptionist() {}

Receptionist::Receptionist(string firstName, string middleName, string lastName, int id, int Salary) : Staff(firstName, middleName, lastName, Date(), id, Salary)
{}

void Receptionist::sendRenewalNoti()
{
	Date todays = Date::getTodaysDate();
	for (int i = 1; i <= FileManager::members.size(); i++)
	{
		Date memberEndDate = FileManager::members[i].getPlan().getEndDate();
		bool memberHasPlan = FileManager::members[i].getPlan().getName() != "";
		if (Date::oneWeekLeft(todays, memberEndDate) and memberHasPlan)
			FileManager::members[i].pushMessage(Messages::earlyRenewal());
	}
}

void Receptionist::cancelSub(long long memberID)
{
	FileManager::members[memberID].cancelPlan();
}

void Receptionist::renewSub(long long memberID)
{
	FileManager::members[memberID].renewPlan();
}

bool Receptionist::addToClass(long long classId, long long memberId)
{
	if (FileManager::classes[classId].hasSpace())
	{
		FileManager::classes[classId].addMember(memberId);
		FileManager::members[memberId].joinClass(classId);
		int classPrice = FileManager::classes[classId].getClassPrice();
		FileManager::members[memberId].incPaidBy(classPrice);
		return true; // Added
	}
	return false;
}

// check
bool Receptionist::removeFromClass(long long index, long long memberId)
{
	long long classID = FileManager::getMemberClassID(memberId, FileManager::classes[index].getClassName());
	if (FileManager::members[memberId].inClass(classID))
	{
		FileManager::members[memberId].leaveClass(classID);
		FileManager::classes[classID].removeMember(memberId);
		addFirstInWaiting(classID);
		return true;
	}
	return false;
}

void Receptionist::addToWaiting(long long classId, long long memberId)
{
	if (FileManager::members[memberId].getVipStatus())
		FileManager::vipWaitingList[classId].push(memberId);
	else
		FileManager::waitingLists[classId].push(memberId);
}

void Receptionist::addFirstInWaiting(long long classId)
{
	long long id = 0;
	if (FileManager::vipWaitingList[classId].size())
	{
		id = FileManager::vipWaitingList[classId].front();
		FileManager::vipWaitingList[classId].pop();
	}

	else if (FileManager::waitingLists[classId].size())
	{
		id = FileManager::waitingLists[classId].front();
		FileManager::waitingLists[classId].pop();
	}

	if (id == 0) return;
	// Send Message And Add
	addToClass(classId, id);
	FileManager::members[id].pushMessage(Messages::addedTo(FileManager::classes[classId].getClassName()));
}

long long Receptionist::getLastMemberId()
{
	return FileManager::members.rbegin()->first;
}

long long Receptionist::getLastClassId()
{
	return FileManager::classes.rbegin()->first;
}

int Receptionist::applyDiscount(string planName, double rate)
{
	return ReadData::getPrice(planName) - rate * ReadData::getPrice(planName);
}

string Receptionist::getRole() const
{
	return "Receptionist";
}