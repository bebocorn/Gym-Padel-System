#include "Receptionist.h"

Receptionist::Receptionist() {}

Receptionist::Receptionist(string firstName, string middleName, string lastName, int id, int Salary) : Staff(firstName, middleName, lastName, Date(), id, Salary)
{}

void Receptionist::sendRenewalNoti()
{
	for (int i = 1; i <= FileManager::members.size(); i++)
	{
		if (Date::oneWeekLeft(Date::getTodaysDate(), FileManager::members[i].getEndDate()))
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
		FileManager::members[memberId].setTotalPaid(FileManager::members[memberId].getTotalPaid() + FileManager::classes[classId].getClassPrice());
		return true;
	}
	return false;
}

bool Receptionist::removeFromClass(long long index, long long memberId)
{
	long long classID = FileManager::GetMemberClassID(memberId, FileManager::classes[index].getClassName());
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

	// Send Message And Add
	if (id == 0) return;
	FileManager::members[id].setTotalPaid(FileManager::members[id].getTotalPaid() + FileManager::classes[classId].getClassPrice());
	FileManager::members[id].joinClass(classId);
	FileManager::classes[classId].addMember(id);
	FileManager::members[id].pushMessage(Messages::addedTo(FileManager::classes[classId].getClassName()));
}

void Receptionist::removeMemberFromGym(long long memberId)
{
	FileManager::members.erase(memberId);
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

void Receptionist::addNewClass(const ClassSession& cs)
{
	FileManager::classes[cs.getClassId()] = cs;
}

string Receptionist::getRole() const
{
	return "Receptionist";
}