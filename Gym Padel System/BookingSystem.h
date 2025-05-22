#pragma once
#include"FileManager.h"

// Padel Stuff
class BookingSystem
{
    // Memory Load -> Better Time Complexity
    static map<long long, set<Slot>>bookedSlots;
    static set<Slot>bookedSlotsSet;
public:
    static bool isSlotAvailable(const Slot& slot);
    static Slot searchNext(Date date, int hour, int courtId);
    static void checkSlotTimePassed();
    static void makeBooking(const Slot& slot, long long memberId);
    static bool cancelBooking(long long memberId, Slot slot);
    static void removeSlot(long long memberId, const Slot& slot);
    static void setBookedSlots(const map<long long, set<Slot>>& BookedSlots);
    static void loadBookedSlotsSet();
};