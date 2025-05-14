#include "FileManager.h"
#include"Manager.h"
#include"Receptionist.h"

// ifstream -> read
// ofstream -> write

// From Json Uses Class Constructor

// Map Uses Self Balancing Tree -> Red Black Tree So Retrieval Is In O(Log n)
map<long long, Member> FileManager::members;
map<long long, Coach> FileManager::coachesInfo;
map<long long, Court> FileManager::courts;
unordered_map<long long, queue<long long>> FileManager::waitingLists;
unordered_map<long long, queue<long long>>FileManager::vipWaitingList;
map<long long, ClassSession> FileManager::classes;
unordered_map<int, Staff*> FileManager::staff;
bool FileManager::reset;

FileManager::FileManager() {}

vector<ClassSession> FileManager::getSessions(string className)
{
	vector<ClassSession> classSessions;
	auto it = classes.begin();

	while (it != classes.end())
	{
		if (it->second.getClassName() == className)
		{
			classSessions.push_back(it->second);
		}
		it++;
	}
	return classSessions;
}

bool FileManager::AlreadyInClass(long long MemberID, long long ClassID)
{
	unordered_set<long long> subClassesIDs = members[MemberID].getSubClasses();

	auto it = subClassesIDs.begin();
	while (it != subClassesIDs.end())
	{
		if (classes[ClassID].getClassName() == classes[*it].getClassName())
			return true;
		it++;
	}
	return false;
}

set<Slot> FileManager::getBookedSlots()
{
	set<Slot>bookedSlots;
	auto it = members.begin();
	while (it != members.end())
	{
		set<Slot>currentMember = members[it->first].getSlots();
		for (auto x = currentMember.begin(); x != currentMember.end(); x++)
			bookedSlots.insert(*x);
		it++;
	}
	return bookedSlots;
}

long long FileManager::GetMemberClassID(long long MemberID, string ClassName)
{
	unordered_set<long long> subClassesIDs = members[MemberID].getSubClasses();

	auto it = subClassesIDs.begin();
	while (it != subClassesIDs.end())
	{
		if (ClassName == classes[*it].getClassName())
			return *it;
		it++;
	}
	return 0;
}



void FileManager::Load()
{
	loadAccounts();
	loadClasses();
	loadWaitLists();
	loadVipWaitingList();
	loadCoachesInfo();
	loadCourts();
	loadStaff();
	loadReset();	
}

void FileManager::Save()
{
	saveAccounts();
	saveClasses();
	saveWaitLists();
	saveVipWaitingList();
	saveCoachesInfo();
	saveCourts();
	saveStaff();
	saveReset();
}

void FileManager::loadAccounts()
{
	json Accounts;
	// Open Accounts File
	ifstream file("Accounts.json");
	// Load To Accounts
	try
	{
		file >> Accounts;
	}
	catch (...) {}	
	file.close();
	// User Exists, Look For Matching ID
	auto it = Accounts.begin();
	while (it != Accounts.end())
	{
		long long id = stoll(it.key());
		members[id] = it.value();
		it++;
	}
}


void FileManager::saveAccounts()
{
	json Accounts;	
	auto it = members.begin();
	while (it != members.end())
	{
		string id = to_string(it->second.getID());
		if (id == "0")
		{
			it++;
			continue;
		}
		Accounts[id] = it->second;
		it++;
	}
	ofstream file("Accounts.json");
	file << Accounts.dump(4);
	file.close();
}

void FileManager::loadClasses()
{
	ifstream file("Classes.json");
	json Classes;
	try
	{
		file >> Classes;
	}
	catch (...) {}
	auto it = Classes.begin();
	while (it != Classes.end())
	{
		classes[stoll(it.key())] = it.value();
		it++;
	}
}

void FileManager::saveClasses()
{
	ofstream file("Classes.json");
	json Classes;
	auto it = classes.begin();
	while (it != classes.end())
	{
		Classes[to_string(it->first)] = it->second;
		it++;
	}
	file << Classes.dump(4);
	file.close();
}



void FileManager::loadWaitLists()
{
	json waitingListsJson;
	ifstream file("WaitLists.json");
	try
	{
		file >> waitingListsJson;
	}
	catch (...) {}
	file.close();
	auto it = waitingListsJson.begin();
	while (it != waitingListsJson.end())
	{
		long long classId = stoll(it.key());
		for (long long memberId : it.value())
			waitingLists[classId].push(memberId);
		it++;
	}
}

void FileManager::saveWaitLists()
{
	json waitingListsJson;
	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		queue<long long>currentClass = it->second;
		string classId = to_string(it->first);
		while (currentClass.size())
		{
			waitingListsJson[classId].push_back(currentClass.front());
			currentClass.pop();
		}
		it++;
	}
	ofstream file("WaitLists.json");
	file << waitingListsJson.dump(4);
	file.close();
}

void FileManager::loadVipWaitingList()
{
	json waitingListsJson;
	ifstream file("Vip WaitingLists.json");
	try
	{
		file >> waitingListsJson;
	}
	catch (...) {}	file.close();
	auto it = waitingListsJson.begin();
	while (it != waitingListsJson.end())
	{
		long long classId = stoll(it.key());
		for (long long memberId : it.value())
			vipWaitingList[classId].push(memberId);
		it++;
	}
}


void FileManager::saveVipWaitingList()
{
	json waitingListsJson;
	auto it = vipWaitingList.begin();
	while (it != vipWaitingList.end())
	{
		queue<long long>currentClass = it->second;
		string className = to_string(it->first);
		while (currentClass.size())
		{
			waitingListsJson[className].push_back(currentClass.front());
			currentClass.pop();
		}
		it++;
	}
	ofstream file("Vip WaitingLists.json");
	file << waitingListsJson.dump(4);
	file.close();
}




void FileManager::loadCoachesInfo()
{
	json CoachesInfo;
	ifstream file("Coaches Info.json");
	try
	{
		file >> CoachesInfo;
	}
	catch (...) {}
	file.close();
	auto it = CoachesInfo.begin();
	while (it != CoachesInfo.end())
	{
		long long id = stoll(it.key());
		coachesInfo[id] = it.value();
		it++;
	}
}

void FileManager::saveCoachesInfo()
{
	json CoachesInfo;
	auto it = coachesInfo.begin();
	while (it != coachesInfo.end())
	{
		string id = to_string(it->second.getID());
		CoachesInfo[id] = it->second;
		it++;
	}
	ofstream file("Coaches Info.json");
	file << CoachesInfo.dump(4);
	file.close();
}


void FileManager::loadCourts()
{
	json Courts;
	ifstream file("Courts.json");
	try
	{
		file >> Courts;
	}
	catch (...) {}	
	file.close();
	auto it = Courts.begin();
	while (it != Courts.end())
	{
		courts[stoll(it.key())] = it.value();
		it++;
	}
}

void FileManager::saveCourts()
{
	json Courts;
	auto it = courts.begin();
	while (it != courts.end())
	{
		string id = to_string(it->first);
		Courts[id] = it->second;
		it++;
	}
	ofstream file("Courts.json");
	file << Courts.dump(4);
	file.close();
}


Staff* fromJson(const json& entry)
{
	string role = entry["Role"];
	Staff* staffPtr = nullptr;

	if (role == "Manager")
		staffPtr = new Manager();
	else if (role == "Coach")
		staffPtr = new Coach();
	else if (role == "Receptionist")
		staffPtr = new Receptionist();

	staffPtr->setFname(entry["First Name"]);
	staffPtr->setMname(entry["Middle Name"]);
	staffPtr->setLname(entry["Last Name"]);
	staffPtr->setID(entry["ID"]);
	staffPtr->setSalary(entry["Salary"]);

	return staffPtr;
}

json jsonToStaffMap()
{
	json j;
	auto it = FileManager::staff.begin();
	while (it != FileManager::staff.end())
	{
		int id = it->first;
		Staff* s = it->second;
		j[to_string(id)] =
		{
			{"First Name", s->getFname()},
			{"Middle Name", s->getMname()},
			{"Last Name", s->getLname()},
			{"Role", s->getRole()},
			{"ID", s->getID()},
			{"Salary", s->getSalary()}
		};
		it++;
	}
	return j;
}

void FileManager::loadStaff()
{
	json s;
	ifstream file("Staff.json");
	try 
	{
		file >> s;
	}
	catch (...) {}

	for (auto it = s.begin(); it != s.end(); it++)
	{
		int id = stoi(it.key());
		Staff* staffPtr = fromJson(it.value());
		if (staffPtr)
			staff[id] = staffPtr;
	}
}

void FileManager::saveStaff()
{
	json s;
	for (auto it = staff.begin(); it != staff.end(); it++)
	{
		Staff* st = it->second;

		s[to_string(it->first)] =
		{
			{"First Name", st->getFname()},
			{"Middle Name", st->getMname()},
			{"Last Name", st->getLname()},
			{"Role", st->getRole()},
			{"ID", st->getID()},
			{"Salary", st->getSalary()}
		};
	}
	ofstream file("Staff.json");
	file << s.dump(4);
	file.close();
}

void FileManager::loadReset()
{
	json j;
	ifstream file("Reset.json");
	try
	{
		file >> j;
	}
	catch (...) {  }
	file.close();
	reset = j["Reset"];
}

void FileManager::saveReset()
{
	json j;
	j["Reset"] = reset;
	ofstream file("Reset.json");
	file << j;
	file.close();
}

void FileManager::itsFirstDay()
{
	if (Date::isFirstDay() && reset)
	{
		clearWaitingList();
		clearVipWaitingList();
		clearMembersInClasses();
		clearVisits();
		clearTotalPaid();
		clearVip();
		reset = 0;
	}
	else
		reset = 1;
}

void FileManager::handleSubscriptions()
{
	auto it = members.begin();
	while (it != members.end())
	{
		Date userEndDate = members[it->first].getEndDate();
		if (!Date::isFutureDate(userEndDate))
			members[it->first].cancelPlan();
		it++;
	}
}

void FileManager::clearWaitingList()
{
	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		while (waitingLists[it->first].size())
			waitingLists[it->first].pop();
		it++;
	}
}

void FileManager::clearVipWaitingList()
{
	auto it = vipWaitingList.begin();
	while (it != vipWaitingList.end())
	{
		while (vipWaitingList[it->first].size())
			vipWaitingList[it->first].pop();
		it++;
	}
}

void FileManager::clearMembersInClasses()
{
	auto it = classes.begin();
	while (it != classes.end())
	{
		classes[it->first].clearClassMembers();
		it++;
	}
}

void FileManager::clearVisits()
{
	auto it = members.begin();
	while (it != members.end())
	{
		members[it->first].setVisits(0);
		it++;
	}
}

void FileManager::clearTotalPaid()
{
	auto it = members.begin();
	while (it != members.end())
	{
		members[it->first].setTotalPaid(0);
		it++;
	}
}

void FileManager::clearVip()
{
	auto it = members.begin();
	while (it != members.end())
	{
		members[it->first].setVipStatus(0);
		it++;
	}
}

bool FileManager::matchingNameAndId(string firstName, string middleName, string lastName, long long id)
{
	if (members.find(id) == members.end())
		return false;
	string fName = members[id].getFname();
	string mName = members[id].getMname();
	string lName = members[id].getLname();
	return fName == firstName && mName == middleName && lName == lastName;
}

bool FileManager::isStaff(string firstName, string middleName, string lastName, int id)
{
	if (staff.find(id) == staff.end())
		return false;
	string fName = staff[id]->getFname();
	string mName = staff[id]->getMname();
	string lName = staff[id]->getLname();
	return fName == firstName && mName == middleName && lName == lastName;
}

void FileManager::clearInbox(long long memberId)
{
	members[memberId].clearInbox();
}