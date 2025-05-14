#pragma once
#include"FileManager.h"

// Padel Stuff
class BookingSystem
{
    static bool foundSlot(long long memberId, const Slot& slot);
    static set<Slot>bookedSlots;
public:
    static bool isSlotAvailable(const Slot& slot);
    static Slot searchNext(Date date, int slotId, string location);
    static void checkSlotTimePassed();
    static void makeBooking(const Slot& slot, long long memberId);
    static bool cancelBooking(long long memberId, Slot slot);
    static void removeSlot(long long memberId, const Slot& slot);
    static long long getCourtId(string location);
    static void setBookedSlots(const set<Slot> &bookedslots);
};