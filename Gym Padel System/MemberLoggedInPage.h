#pragma once

#include <QMainWindow>
#include "ui_MemberLoggedInPage.h"
#include "FileManager.h"
#include "Receptionist.h"

class MemberLoggedInPage : public QMainWindow
{
	Q_OBJECT

public:
	MemberLoggedInPage(Slot s,long long mID,QWidget *parent = nullptr);
	~MemberLoggedInPage() override;

private:
	Ui::MemberLoggedInPageClass ui;
	int classSessionNumber;
	long long MemberID;
	bool Visited;
	Slot slotMember;
	vector<ClassSession> classSessions;

private slots:


	void setAllWidgetsVisibleFalse();

	//Gym Widget
	void MakePlanButtonClicked();
	void ExitMPWButtonClicked();
	void ConfirmPlanButtonClicked();
	void RenewPlanButtonClicked();
	void RenewPlanWidgetButtonClicked();
	void ExitRPWButtonClicked();
	void RenewPlanWidgetEButtonClicked();
	void OkClicked();
	void CancelPlanButtonClicked();
	void ConfirmationMsgSButtonClicked();
	void ConfirmationMsgBButtonClicked();
	void ExitCPW();
	void AddWorkoutButtonClicked();
	void ConfirmAddWorkoutButtonClicked();
	void ExitAWWButtonClicked();
	void ViewPastWorkoutsButtonClicked();
	void ExitVPWWButtonClicked();

	//Class Widget
	void BookClassButtonClicked();
	void VCSTButtonClicked();
	void ExitBCButtonClicked();
	void VCSTConfirmButtonClicked();
	void ExitBCTButtonClicked();
	void UnbookClassButtonClicked();
	void ConfirmUnbookButtonClicked();
	void ExitUBCButtonClicked();
	void WLConfirmationMsgBClicked();
	void WLConfirmationMsgOClicked();

	//Padel Widget
	void ShowCourtsButtonClicked();
	void ExitCWButtonClicked();
	void CheckButtonClicked();
	void BookCourtButtonClicked();
	void CancelBookingButtonClicked();
	void ConfirmCancelBookingButtonClicked();
	void ExitCBWButtonClicked();
	void NextAvailableSlotBClicked();
	void NextAvailableSlotSClicked();

	//Profile Widget
	void ProfileButtonClicked();
	void ExitPWButtonClicked();
	void VIPButtonClicked();
	void VIPConfirmButtonClicked();

	//Notification Widget
	void NotificationButtonClicked();
	void NotificationButtonDotClicked();
	void HaveNotification();
	void ExitNWButtonClicked();

	void ExitButtonClicked();
};
