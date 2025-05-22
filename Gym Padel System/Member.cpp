#include "Member.h"
using namespace std;

Member::Member() : ID(0), isVip(0), visits(0), totalPaid(0) {}

Member::Member(string FirstName, string MiddleName, string LastName, Date dob, long long id, string planName, deque<string> PastWorkouts, bool vip, int Visits, unordered_set<long long> SubClasses, Date endDate, int TotalPaid, set<Slot> Slots, vector<string>Inbox) : Person(FirstName, MiddleName, LastName, dob)
{
    ID = id;
    pastWorkouts = PastWorkouts;
    isVip = vip;
    visits = Visits;
    subClasses = SubClasses;
    plan.setPlanName(planName);
    plan.setEndDate(endDate);
    totalPaid = TotalPaid;
    slotsVec = Slots;
    inbox = Inbox;
}

void Member::setID(long long id)
{
    ID = id;
}

void Member::setVipStatus(bool vip)
{
    isVip = vip;
}

void Member::setVisits(int Visits)
{
    visits = Visits;
}

// Sets Name And End Date
void Member::setPlan(int PlanNumber)
{
    plan.setPlanName(ReadData::getName(PlanNumber));
    plan.calcEndDate();
}

void Member::setSubClasses(unordered_set<long long> SubClasses)
{
    subClasses = SubClasses;
}

void Member::setTotalPaid(int TotalPaid)
{
    totalPaid = TotalPaid;
}

void Member::setSlots(set<Slot> Slots)
{
    slotsVec = Slots;
}

void Member::setInbox(vector<string> Inbox)
{
    inbox = Inbox;
}

void Member::setPlan(const Subscription& sub)
{
    plan = sub;
}

bool Member::getVipStatus() const
{
    return isVip;
}

void Member::addWorkout(string workout)
{
    // We Need Last 5 Only, Pop Front
    while (pastWorkouts.size() >= 5)
        pastWorkouts.pop_front();
    pastWorkouts.push_back(workout);
}

void Member::removeSlot(const Slot& slot)
{
    // O(Log n)
    slotsVec.erase(slot);
}

bool Member::inClass(long long classId)
{
    // O(1)
    return subClasses.find(classId) != subClasses.end();
}

void Member::addSlot(const Slot& slot)
{
    // O(Log n)
    slotsVec.insert(slot);
}

void Member::pushMessage(string Message)
{
    // If Message Already In Inbox, Just Return
    for (int i = 0; i < inbox.size(); i++)
    {
        if (inbox[i] == Message)
            return;
    }
    inbox.push_back(Message);
}

void Member::clearInbox()
{
    // O(n)
    inbox.clear();
}

void Member::incPaidBy(int money)
{
    totalPaid += money;
}

long long Member::getID() const
{
    return ID;
}

deque<string> Member::getPastWorkouts() const
{
    return pastWorkouts;
}


int Member::getVisits() const
{
    return visits;
}

int Member::getTotalPaid() const
{
    return totalPaid;
}

unordered_set<long long> Member::getSubClasses() const
{
    return subClasses;
}

set<Slot> Member::getSlots() const
{
    return slotsVec;
}

vector<string> Member::getInbox() const
{
    return inbox;
}

Subscription Member::getPlan() const
{
    return plan;
}

bool Member::isSubscribed() const
{
    return plan.getName() != "";
}

void Member::joinClass(long long classId)
{
    // O(1)
    subClasses.insert(classId);
}

void Member::leaveClass(long long classId)
{
    // O(1)
    subClasses.erase(classId);
}

void Member::renewPlan()
{
    plan.extendPlan(plan.getName());
}

void Member::cancelPlan()
{
    plan.cancelPlan();
}

bool Member::operator == (const Member& member) const
{
    return fName == member.fName and
        mName == member.mName and
        lName == member.lName and
        dateOfBirth == member.dateOfBirth and
        ID == member.ID and
        pastWorkouts == member.pastWorkouts and
        plan == member.plan and
        isVip == member.isVip and
        visits == member.visits and
        subClasses == member.subClasses and
        totalPaid == member.totalPaid and
        slotsVec == member.slotsVec and
        inbox == member.inbox;
}