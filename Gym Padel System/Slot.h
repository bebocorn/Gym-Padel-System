#pragma once
#include "Date.h"

// every slot = 1 hour from 0 - 23
class Slot
{
	int hour, courtID;
	Date date;
public:
	Slot();
	Slot(int CourtId, int Hour, Date Date);

	void setCourtID(int CourtId);
	void setHour(int Hour);
	void setDate(const Date& Date);

	int getCourtID() const;
	int getHour() const;
	Date getDate() const;

	// Operator Overloading
	bool operator == (const Slot& slot) const;
	bool operator < (const Slot & slot) const;
};

inline void from_json(const json& j, Slot& u)
{
	u = Slot
	{
		j.at("Court ID").get<int>(),
		j.at("Hour").get<int>(),
		j.at("Date").get<Date>()
	};
}

inline void to_json(json& j, const Slot& u)
{
	j = json
	{
		{"Court ID", u.getCourtID()},
		{"Hour", u.getHour()},
		{"Date", u.getDate()}
	};
}