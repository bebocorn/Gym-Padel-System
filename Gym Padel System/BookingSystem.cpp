#include "BookingSystem.h"
#include <ctime>

set<Slot> BookingSystem::bookedSlots;

// Slot Not Booked
bool BookingSystem::isSlotAvailable(const Slot& slot)
{
	return bookedSlots.find(slot) == bookedSlots.end();
}

// Closest Free Slot
Slot BookingSystem::searchNext(Date date, int slotId, string location)
{
	long long courtId = getCourtId(location);
	Date newDate = date;
	Slot candidateSlot;
	while (true)
	{
		candidateSlot = Slot(courtId, slotId, newDate);
		bool available = isSlotAvailable(candidateSlot);
		if (available)
			break;
		else
		{
			slotId++;
			if (slotId == 24)
			{
				// Check Next Day
				newDate = Date::getNextDate(newDate);
				slotId = 0;
			}
		}
	}
	return candidateSlot;
}

// Handle If Booking Passed
void BookingSystem::checkSlotTimePassed()
{
	auto it = FileManager::members.begin();
	while (it != FileManager::members.end())
	{
		set<Slot>memberReservedSlots = FileManager::members[it->first].getSlots();
		auto itt = memberReservedSlots.begin();
		long long currentMemberId = it->first;
		while (itt != memberReservedSlots.end())
		{
			Slot currentSlot = *itt;
			tm targetTime = {};
			targetTime.tm_mday = itt->getDate().getDay();
			targetTime.tm_mon = itt->getDate().getMonth() - 1;
			targetTime.tm_year = itt->getDate().getYear() - 1900;
			targetTime.tm_hour = itt->getHour();
			targetTime.tm_min = 0;
			targetTime.tm_sec = 0;
			time_t target = mktime(&targetTime);
			time_t now = time(0);
			double hoursDiff = difftime(target, now) / 3600.0;
			if (hoursDiff < 0)
				removeSlot(currentMemberId, currentSlot);
			itt++;
		}
		it++;
	}
}

void BookingSystem::makeBooking(const Slot& slot, long long memberId)
{
	FileManager::members[memberId].setTotalPaid(FileManager::members[memberId].getTotalPaid() + FileManager::courts[slot.getCourtID()].getBookingPrice());
	FileManager::members[memberId].addSlot(slot);
	bookedSlots.insert(slot);
}

bool BookingSystem::cancelBooking(long long memberId, Slot slot)
{
	tm targetTime = {};
	targetTime.tm_mday = slot.getDate().getDay();
	targetTime.tm_mon = slot.getDate().getMonth() - 1;
	targetTime.tm_year = slot.getDate().getYear() - 1900;
	targetTime.tm_hour = slot.getHour();
	targetTime.tm_min = 0;
	targetTime.tm_sec = 0;

	time_t target = mktime(&targetTime);

	time_t now = time(0);

	double hoursDiff = difftime(target, now) / 3600.0;
	// Vip can cancel whenever
	if (FileManager::members[memberId].getVipStatus() || hoursDiff > 3)
	{
		FileManager::members[memberId].setTotalPaid(FileManager::members[memberId].getTotalPaid() - FileManager::courts[slot.getCourtID()].getBookingPrice() * 0.5);
		removeSlot(memberId, slot);
		return true;
	}
	return false;
}

void BookingSystem::removeSlot(long long memberId, const Slot& slot)
{
	FileManager::members[memberId].removeSlot(slot);
	bookedSlots.erase(slot);
}

long long BookingSystem::getCourtId(string location)
{
	auto it = FileManager::courts.begin();
	while (it != FileManager::courts.end())
	{
		if (location == it->second.getLocation())
			return it->second.getID();
		it++;
	}
	return -1;
}

void BookingSystem::setBookedSlots(const set<Slot> &bookedslots)
{
	bookedSlots = bookedslots;
}

bool BookingSystem::foundSlot(long long memberId, const Slot& slot)
{
	set<Slot>slots = FileManager::members[memberId].getSlots();
	auto it = slots.begin();
	while (it != slots.end())
	{
		Slot currentSlot = *it;
		if (currentSlot == slot)
			return true;
		it++;
	}
	return false;
}