#include "BookingSystem.h"
#include <ctime>

map<long long, set<Slot>> BookingSystem::bookedSlots;
set<Slot> BookingSystem::bookedSlotsSet;

// Slot Not Booked
bool BookingSystem::isSlotAvailable(const Slot& slot)
{
	// O(Log n)
	auto testSlot = bookedSlotsSet.lower_bound(slot);
	return (testSlot == bookedSlotsSet.end() || !(*testSlot == slot));
}

// Closest Free Slot, QUERIES -> OPTIMIZE
Slot BookingSystem::searchNext(Date date, int hour, int courtId)
{
	Date newDate = date;
	Slot candidateSlot;
	while (true)
	{
		candidateSlot = Slot(courtId, hour, newDate);
		bool available = isSlotAvailable(candidateSlot);
		if (available)
			break;
		else
		{
			hour++;
			if (hour == 24)
			{
				// Check Next Day
				newDate = Date::getNextDate(newDate);
				hour = 0;
			}
		}
	}
	return candidateSlot;
}

// Handle If Booking Passed, Runs 1 Time Only
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
	// O(Log n)
	int courtPrice = FileManager::courts[slot.getCourtID()].getBookingPrice();
	FileManager::members[memberId].incPaidBy(courtPrice);
	FileManager::members[memberId].addSlot(slot);
	bookedSlotsSet.insert(slot);
	bookedSlots[memberId].insert(slot);
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
	// Vip Can Cancel Whenever
	if (FileManager::members[memberId].getVipStatus() || hoursDiff > 3)
	{
		int halfPrice = FileManager::courts[slot.getCourtID()].getBookingPrice() * 0.5;
		FileManager::members[memberId].incPaidBy(-halfPrice);
		removeSlot(memberId, slot);
		return true;
	}
	return false;
}

void BookingSystem::removeSlot(long long memberId, const Slot& slot)
{
	// O(Log n)
	FileManager::members[memberId].removeSlot(slot);
	bookedSlots[memberId].erase(slot);
	bookedSlotsSet.erase(slot);
}

void BookingSystem::setBookedSlots(const map<long long, set<Slot>>& BookedSlots)
{
	bookedSlots = BookedSlots;
}

void BookingSystem::loadBookedSlotsSet()
{
	auto it = bookedSlots.begin();
	while (it != bookedSlots.end())
	{
		set<Slot>slotSet = bookedSlots[it->first];
		for (Slot slot : slotSet)
			bookedSlotsSet.insert(slot);
		it++;
	}
}