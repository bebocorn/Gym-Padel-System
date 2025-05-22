#include "Manager.h"

Manager::Manager() {}

Manager::Manager(string firstName, string middleName, string lastName, int id, int Salary) : Staff(firstName, middleName, lastName, Date(), id, Salary)
{}

// Sorts Descending Based On Visits
bool Manager::comp(const Member& a, const Member& b)
{
	return a.getVisits() > b.getVisits();
}

int Manager::getTotalRevenue()
{
	int totalPaidByGym = 0, totalPaidToGym = 0;
	auto staffIt = FileManager::staff.begin();
	while (staffIt != FileManager::staff.end())
	{
		// Sum Of Salaries
		totalPaidByGym += FileManager::staff[staffIt->first]->getSalary();
		staffIt++;
	}
	auto membersIt = FileManager::members.begin();
	while (membersIt != FileManager::members.end())
	{
		// Total Paid By Members
		totalPaidToGym += FileManager::members[membersIt->first].getTotalPaid();
		membersIt++;
	}
	return totalPaidToGym - totalPaidByGym;
}

vector<long long> Manager::getMostActive()
{
	// O(n Log n)
	vector<Member>myMembers;
	auto it = FileManager::members.begin();
	while (it != FileManager::members.end())
	{
		myMembers.push_back(it->second);
		it++;
	}
	sort(myMembers.begin(), myMembers.end(), comp);
	vector<long long>membersId(5);
	for (int i = 0; i < 5; i++)
		membersId[i] = myMembers[i].getID();
	return membersId;
}

string Manager::getRole() const
{
	return "Manager";
}
