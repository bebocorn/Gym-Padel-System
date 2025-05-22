#pragma once
#include <iostream>
#include"json.hpp"
using json = nlohmann::json;
using namespace std;

class Court
{
private:
	int courtId, bookingPrice;
	string courtLocation, courtName;
public:
	Court();
	Court(int CourtId, string CourtLocation, string CourtName, int BookingPrice);

	void setID(int CourtId);
	void setLocation(string CourtLocation);
	void setName(string CourtName);
	void setBookingPrice(int price);

	int getID() const;
	int getBookingPrice() const;
	string getLocation() const;
	string getName() const;
};


inline void from_json(const json& j, Court& u)
{
	u = Court
	{
		j.at("ID").get<int>(),
		j.at("Location").get<string>(),
		j.at("Name").get<string>(),
		j.at("Booking Price").get<int>()
	};
}

inline void to_json(json& j, const Court& u)
{
	j = json
	{
		{"ID", u.getID()},
		{"Location", u.getLocation()},
		{"Name", u.getName()},
		{"Booking Price", u.getBookingPrice()}
	};
}