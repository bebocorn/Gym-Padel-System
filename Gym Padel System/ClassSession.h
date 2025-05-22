#pragma once
#include<iostream>
#include<unordered_set>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;



class ClassSession
{
private:
	long long classId;
	string classDay, classTime, className;
	int classCapacity, classPrice;
	unordered_set<long long>classMembers;
public:
	ClassSession();
	ClassSession(string ClassDay, string ClassTime, string ClassName, int ClassCapacity, unordered_set<long long>ClassMembers, long long ClassId, int ClassPrice);


	void setClassId(long long ClassId);
	void setClassTime(string ClassTime);
	void setClassDay(string ClassDay);
	void setClassCapacity(int Capacity);
	void setClassMembers(unordered_set<long long>ClassMembers);
	void setClassName(string ClassName);
	void setClassPrice(int price);

	long long getClassId() const;
	string getClassTime() const;
	string getClassDay() const;
	int getClassCapacity() const;
	unordered_set<long long>getClassMembers() const;
	string getClassName()const;
	int getClassPrice()const;

	void addMember(long long memberId);
	void removeMember(long long memberId);
	void clearClassMembers();
	bool hasSpace();
};

inline void to_json(json& j, const ClassSession& u)
{
	j = json
	{
		{"Day", u.getClassDay()},
		{"Time", u.getClassTime()},
		{"Name", u.getClassName()},
		{"Capacity", u.getClassCapacity()},
		{"Members", u.getClassMembers()},
		{"Class ID",u.getClassId()},
		{"Price", u.getClassPrice()}
	};
}

inline void from_json(const json& j, ClassSession& u)
{
	u = ClassSession
	{
		j.at("Day").get<string>(),
		j.at("Time").get<string>(),
		j.at("Name").get<string>(),
		j.at("Capacity").get<int>(),
		j.at("Members").get<unordered_set<long long>>(),
		j.at("Class ID").get<long long>(),
		j.at("Price").get<int>()
	};
}