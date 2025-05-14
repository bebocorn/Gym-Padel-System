#pragma once
#include<iostream>
#include<fstream>
#include<queue>
#include"json.hpp"
#include"ClassSession.h"
#include"Member.h"
#include"Court.h"
#include"Slot.h"
#include"Messages.h"
#include"Coach.h"
using json = nlohmann::json;
using namespace std;


class FileManager
{
private:
	static void loadAccounts();
	static void saveAccounts();
	static void loadClasses();
	static void saveClasses();
	static void loadWaitLists();
	static void saveWaitLists();
	static void loadVipWaitingList();
	static void saveVipWaitingList();
	static void loadCoachesInfo();
	static void saveCoachesInfo();
	static void loadCourts();
	static void saveCourts();
	static void loadStaff();
	static void saveStaff();
	static void loadReset();
	static void saveReset();


	// At End Of Month
	static void clearWaitingList();
	static void clearVipWaitingList();
	static void clearMembersInClasses();
	static void clearVisits();
	static void clearTotalPaid();
	static void clearVip();

public:
	FileManager();
	static map<long long, Member>members;
	static map<long long, Coach>coachesInfo;
	static map<long long, Court>courts;
	static unordered_map<long long, queue<long long>>waitingLists;
	static unordered_map<long long, queue<long long>>vipWaitingList;
	static map<long long, ClassSession>classes;
	static unordered_map<int, Staff*>staff;
	static bool reset;
	static vector<ClassSession> getSessions(string className);
	static long long GetMemberClassID(long long MemberID, string ClassName);
	static bool AlreadyInClass(long long MemberID, long long ClassID);
	static set<Slot> getBookedSlots();


	static void Load();
	static void Save();
	static void itsFirstDay();

	// Handle Ended Subs
	static void handleSubscriptions();

	// Utilities
	static void clearInbox(long long memberId);
	static bool matchingNameAndId(string firstName, string middleName, string lastName, long long id);
	static bool isStaff(string firstName, string middleName, string lastName, int id);
};