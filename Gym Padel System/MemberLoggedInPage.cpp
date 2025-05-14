#include "MemberLoggedInPage.h"
#include <Qt>
#include <BookingSystem.h>

MemberLoggedInPage::MemberLoggedInPage(Slot slotMember,long long mID, QWidget *parent)
	: QMainWindow(parent)
{
	MemberID = mID;
	Visited = false;
	ui.setupUi(this);

	setAllWidgetsVisibleFalse();
	ui.DoneMsg->setVisible(false);
	ui.DoneMsgE->setVisible(false);
	ui.ClassTimeMsgE->setVisible(false);
	ui.WLConfirmationMsg->setVisible(false);
	ui.RenewPlanWidgetE->setVisible(false);
	ui.ConfirmationMsg->setVisible(false);
	ui.AddWorkoutMsgE->setVisible(false);	
	ui.ErrorMsgP->setVisible(false);
	ui.ClassMsgE->setVisible(false);
	ui.AvailableMsgP->setVisible(false);
	ui.CancelBookingMsgE->setVisible(false);
	ui.NextAvailableSlotMsg->setVisible(false);
	ui.NotificationButtonDot->setVisible(false);
	HaveNotification();



	//Connect Buttons

	//Gym Widget
	connect(ui.MakePlanButton, &QPushButton::clicked, this, &MemberLoggedInPage::MakePlanButtonClicked);
	connect(ui.ConfirmPlanButton, &QPushButton::clicked, this, &MemberLoggedInPage::ConfirmPlanButtonClicked);
	connect(ui.ExitMPWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitMPWButtonClicked);
	connect(ui.DoneMsgButton, &QPushButton::clicked, this, &MemberLoggedInPage::OkClicked);
	connect(ui.RenewPlanButton, &QPushButton::clicked, this, &MemberLoggedInPage::RenewPlanButtonClicked);
	connect(ui.ExitRPWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitRPWButtonClicked);
	connect(ui.RenewPlanWidgetButton, &QPushButton::clicked, this, &MemberLoggedInPage::RenewPlanWidgetButtonClicked);
	connect(ui.RenewPlanWidgetEButton, &QPushButton::clicked, this, &MemberLoggedInPage::RenewPlanWidgetEButtonClicked);
	connect(ui.AddWorkoutButton, &QPushButton::clicked, this, &MemberLoggedInPage::AddWorkoutButtonClicked);
	connect(ui.ConfirmAddWorkoutButton, &QPushButton::clicked, this, &MemberLoggedInPage::ConfirmAddWorkoutButtonClicked);
	connect(ui.ExitAWWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitAWWButtonClicked);
	connect(ui.CancelPlanButton, &QPushButton::clicked, this, &MemberLoggedInPage::CancelPlanButtonClicked);
	connect(ui.ConfirmationMsgS, &QPushButton::clicked, this, &MemberLoggedInPage::ConfirmationMsgSButtonClicked);
	connect(ui.ConfirmationMsgB, &QPushButton::clicked, this, &MemberLoggedInPage::ConfirmationMsgBButtonClicked);
	connect(ui.ExitButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitButtonClicked);
	connect(ui.ViewPastWorkoutsButton, &QPushButton::clicked, this, &MemberLoggedInPage::ViewPastWorkoutsButtonClicked);
	connect(ui.ExitVPWWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitVPWWButtonClicked);

	//Classes Widget
	connect(ui.BookClassButton, &QPushButton::clicked, this, &MemberLoggedInPage::BookClassButtonClicked);
	connect(ui.ExitBCButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitBCButtonClicked);
	connect(ui.VCSTButton, &QPushButton::clicked, this, &MemberLoggedInPage::VCSTButtonClicked);
	connect(ui.VCSTConfirmButton, &QPushButton::clicked, this, &MemberLoggedInPage::VCSTConfirmButtonClicked);
	connect(ui.WLConfirmationMsgB, &QPushButton::clicked, this, &MemberLoggedInPage::WLConfirmationMsgBClicked);
	connect(ui.WLConfirmationMsgO, &QPushButton::clicked, this, &MemberLoggedInPage::WLConfirmationMsgOClicked);
	connect(ui.ExitBCTButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitBCTButtonClicked);
	connect(ui.ConfirmUnbookButton, &QPushButton::clicked, this, &MemberLoggedInPage::ConfirmUnbookButtonClicked);
	connect(ui.UnbookClassButton, &QPushButton::clicked, this, &MemberLoggedInPage::UnbookClassButtonClicked);
	connect(ui.ConfirmUnbookButton, &QPushButton::clicked, this, &MemberLoggedInPage::ConfirmUnbookButtonClicked);
	connect(ui.ExitUBCButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitUBCButtonClicked);

	//Padel Widget
	connect(ui.ShowCourtsButton, &QPushButton::clicked, this, &MemberLoggedInPage::ShowCourtsButtonClicked);
	connect(ui.ExitCWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitCWButtonClicked);
	connect(ui.CheckButton, &QPushButton::clicked, this, &MemberLoggedInPage::CheckButtonClicked);
	connect(ui.BookCourtButton, &QPushButton::clicked, this, &MemberLoggedInPage::BookCourtButtonClicked);
	connect(ui.CancelBookingButton, &QPushButton::clicked, this, &MemberLoggedInPage::CancelBookingButtonClicked);
	connect(ui.ConfirmCancelBookingButton, &QPushButton::clicked, this, &MemberLoggedInPage::ConfirmCancelBookingButtonClicked);
	connect(ui.ExitCBWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitCBWButtonClicked);
	connect(ui.NextAvailableSlotS, &QPushButton::clicked, this, &MemberLoggedInPage::NextAvailableSlotSClicked);
	connect(ui.NextAvailableSlotB, &QPushButton::clicked, this, &MemberLoggedInPage::NextAvailableSlotBClicked);

	//Profile Widget
	connect(ui.ProfileButton, &QPushButton::clicked, this, &MemberLoggedInPage::ProfileButtonClicked);
	connect(ui.ExitPWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitPWButtonClicked);
	connect(ui.VIPButton, &QPushButton::clicked, this, &MemberLoggedInPage::VIPButtonClicked);
	connect(ui.VIPConfirmButton, &QPushButton::clicked, this, &MemberLoggedInPage::VIPConfirmButtonClicked);

	//Notification Widget
	connect(ui.NotificationButton, &QPushButton::clicked, this, &MemberLoggedInPage::NotificationButtonClicked);
	connect(ui.NotificationButtonDot, &QPushButton::clicked, this, &MemberLoggedInPage::NotificationButtonDotClicked);
	connect(ui.ExitNWButton, &QPushButton::clicked, this, &MemberLoggedInPage::ExitNWButtonClicked);

}


void MemberLoggedInPage::setAllWidgetsVisibleFalse()
{
	ui.MakePlanWidget->setVisible(false);
	ui.RenewPlanWidget->setVisible(false);
	ui.AddWorkoutWidget->setVisible(false);
	ui.ViewPastWorkoutsWidget->setVisible(false);
	ui.BookClassWidget->setVisible(false);
	ui.BookClassTimeWidget->setVisible(false);
	ui.ProfileWidget->setVisible(false);
	ui.VIPConfirmWidget->setVisible(false);
	ui.UnbookClassWidget->setVisible(false);	
	ui.CancelBookingWidget->setVisible(false);
	ui.CourtsWidget->setVisible(false);
	ui.NotificationWidget->setVisible(false);
	ExitCPW();
}

//Gym Widget
void MemberLoggedInPage::MakePlanButtonClicked()
{
	setAllWidgetsVisibleFalse();
	ui.DoneMsgE->setVisible(false);
	ui.MakePlanWidget->setGeometry(290, 290, 431, 360);
	ui.ConfirmPlanButton->setGeometry(140, 290, 141, 50);
	ExitRPWButtonClicked();
	ui.MakePlanWidget->setVisible(true);
	ui.ExitMPWButton->setVisible(true);
	ui.ConfirmPlanButton->setVisible(true);
}

void MemberLoggedInPage::ExitMPWButtonClicked()
{
	ui.MakePlanWidget->setVisible(false);
}

void MemberLoggedInPage::ConfirmPlanButtonClicked()
{
	if (ui.BasicRB->isChecked())
	{
		FileManager::members[MemberID].setPlan(1);
		FileManager::members[MemberID].setTotalPaid(FileManager::members[MemberID].getTotalPaid() + ReadData::getPrice("Basic"));
		ExitMPWButtonClicked();
		ui.DoneMsgLabel->setText("Done!");
		ui.DoneMsg->setVisible(true);
	}
	else if (ui.StandardRB->isChecked())
	{
		FileManager::members[MemberID].setPlan(2);
		FileManager::members[MemberID].setTotalPaid(FileManager::members[MemberID].getTotalPaid() + ReadData::getPrice("Standard"));
		ExitMPWButtonClicked();
		ui.DoneMsgLabel->setText("Done!");
		ui.DoneMsg->setVisible(true);
	}
	else if (ui.PremiumRB->isChecked())
	{
		FileManager::members[MemberID].setPlan(3);
		FileManager::members[MemberID].setTotalPaid(FileManager::members[MemberID].getTotalPaid() + ReadData::getPrice("Premium"));
		ExitMPWButtonClicked();
		ui.DoneMsgLabel->setText("Done!");
		ui.DoneMsg->setVisible(true);
	}
	else if (ui.UltimateRB->isChecked())
	{
		FileManager::members[MemberID].setPlan(4);
		FileManager::members[MemberID].setTotalPaid(FileManager::members[MemberID].getTotalPaid() + ReadData::getPrice("Ultimate"));
		ExitMPWButtonClicked();
		ui.DoneMsgLabel->setText("Done!");
		ui.DoneMsg->setVisible(true);
	}
	else
	{
		ui.MakePlanWidget->setGeometry(290, 290, 431, 421);
		ui.ConfirmPlanButton->setGeometry(140, 350, 141, 50);
		ui.DoneMsgE->setVisible(true);
	}
}

void MemberLoggedInPage::OkClicked()
{
	ui.DoneMsg->setVisible(false);
}

void MemberLoggedInPage::RenewPlanButtonClicked()
{
	setAllWidgetsVisibleFalse();
	int newPrice;
	bool isOneWeek = Date::oneOrMoreWeekLeft(Date::getTodaysDate(), FileManager::members[MemberID].getEndDate());
	if (FileManager::members[MemberID].getPlanName() == "")
	{
		setAllWidgetsVisibleFalse();
		ui.RenewPlanWidgetE->setVisible(true);
	}
	else if(isOneWeek)
	{
		newPrice = Receptionist::applyDiscount(FileManager::members[MemberID].getPlanName(), 0.25);
		FileManager::members[MemberID].setTotalPaid(FileManager::members[MemberID].getTotalPaid() + newPrice);
		QString np = QString::number(newPrice);
		ui.RenewPlanWidgetTxtEdit->setText("The new price is " + np + " due to early renewal\nAre you sure you want to renew?");
		ui.RenewPlanWidget->setVisible(true);
	}
	else
	{
		newPrice = ReadData::getPrice(FileManager::members[MemberID].getPlanName());
		FileManager::members[MemberID].setTotalPaid(FileManager::members[MemberID].getTotalPaid() + newPrice);
		QString np = QString::number(newPrice);
		ui.RenewPlanWidgetTxtEdit->setText("The price is " + np + "\nAre you sure you want to renew?");
		ui.RenewPlanWidget->setVisible(true);
	}
}

void MemberLoggedInPage::RenewPlanWidgetButtonClicked()
{
	FileManager::members[MemberID].renewPlan();
	ExitRPWButtonClicked();
	ui.DoneMsg->setVisible(true);
}

void MemberLoggedInPage::ExitRPWButtonClicked()
{
	ui.RenewPlanWidget->setVisible(false);
}

void MemberLoggedInPage::RenewPlanWidgetEButtonClicked()
{
	ui.RenewPlanWidgetE->setVisible(false);
}

void MemberLoggedInPage::CancelPlanButtonClicked()
{
	setAllWidgetsVisibleFalse();
	if (FileManager::members[MemberID].getPlanName() == "")
	{
		ui.RenewPlanWidgetE->setVisible(true);
	}
	else
	{
		ui.ConfirmationMsg->setVisible(true);
	}
}

void MemberLoggedInPage::ExitCPW()
{
	ui.ConfirmationMsg->setVisible(false);
}

void MemberLoggedInPage::AddWorkoutButtonClicked()
{
	setAllWidgetsVisibleFalse();
	if (FileManager::members[MemberID].getPlanName() == "")
	{
		ui.RenewPlanWidgetE->setVisible(true);
	}
	else
	{
		ui.AddWorkoutWidget->setGeometry(360, 150, 411, 541);
		ui.ConfirmAddWorkoutButton->setGeometry(140, 470, 141, 50);
		ui.WorkoutTxtBox->setText("");
		ui.AddWorkoutMsgE->setVisible(false);
		ui.AddWorkoutWidget->setVisible(true);
	}
}

void MemberLoggedInPage::ConfirmAddWorkoutButtonClicked()
{
	QString wn = ui.WorkoutTxtBox->text();
	string won = wn.toStdString();
	if (won != "")
	{
		FileManager::members[MemberID].addWorkout(ReadData::getWorkout(stoi(won)));
		if (!Visited)
		{
			FileManager::members[MemberID].setVisits(FileManager::members[MemberID].getVisits() + 1);
			Visited = true;
		}
		ExitAWWButtonClicked();
		ui.DoneMsg->setVisible(true);
	}
	else
	{
		ui.AddWorkoutWidget->setGeometry(360, 150, 411, 590);
		ui.ConfirmAddWorkoutButton->setGeometry(140, 520, 141, 50);
		ui.AddWorkoutMsgE->setVisible(true);
	}
}

void MemberLoggedInPage::ExitAWWButtonClicked()
{
	ui.AddWorkoutWidget->setVisible(false);
}

void MemberLoggedInPage::ViewPastWorkoutsButtonClicked()
{
	ui.PastWorkoutsInfo->clear();
	deque<string> workoutsToDisplay = FileManager::members[MemberID].getPastWorkouts();

	for (int i = 1; i <= workoutsToDisplay.size(); i++)
	{
		QString s = QString::fromStdString(workoutsToDisplay[i - 1]);
		string num = to_string(i) + "- ";
		QString n = QString::fromStdString(num);
		ui.PastWorkoutsInfo->append(n + s);
		ui.PastWorkoutsInfo->append("");
	}

	setAllWidgetsVisibleFalse();
	ui.ViewPastWorkoutsWidget->setVisible(true);
}

void MemberLoggedInPage::ExitVPWWButtonClicked()
{
	ui.ViewPastWorkoutsWidget->setVisible(false);
}



void MemberLoggedInPage::ConfirmationMsgSButtonClicked()
{
	FileManager::members[MemberID].cancelPlan();
	ExitCPW();
}

void MemberLoggedInPage::ConfirmationMsgBButtonClicked()
{
	ExitCPW();

}


//Class Widget


void MemberLoggedInPage::BookClassButtonClicked()
{

	ui.BookClassWidget->setGeometry(820, 190, 420, 600);
	ui.VCSTButton->setGeometry(120, 520, 201, 50);
	ui.ClassMsgE->setVisible(false);
	ui.ClassNameTxtBox->clear();
	ui.ClassPriceTxtBox->clear();
	ui.CNTxtBox->clear();

	for (int i = 1; i <= 10; i++)
	{
		QString c = QString::number(i);
		string cn = FileManager::classes[i].getClassName();
		QString className = QString::fromStdString(cn);

		int p = FileManager::classes[i].getClassPrice();
		QString price = QString::number(p);

		ui.ClassNameTxtBox->append(c + "- " + className);
		ui.ClassPriceTxtBox->append(price);

		if (i != 10)
		{
			ui.ClassNameTxtBox->append("");
			ui.ClassPriceTxtBox->append("");
		}
	}

	ui.BookClassWidget->setVisible(true);
}

void MemberLoggedInPage::VCSTButtonClicked()
{
	int n;
	QString cn = ui.CNTxtBox->text();
	string classNumber = cn.toStdString();

	if (classNumber != "")
	{
		n = stoi(classNumber);
		if (n > 10 || n < 1)
		{
			ui.BookClassWidget->setGeometry(820, 190, 420, 640);
			ui.VCSTButton->setGeometry(120, 570, 201, 50);
			ui.ClassMsgE->setVisible(true);
		}
		else
		{

			if (!FileManager::AlreadyInClass(MemberID, n))
			{
				ui.BookClassWidget->setVisible(false);
				ui.ClassTimeTxtBox->clear();
				ui.ClassDayTxtBox->clear();

				classSessions = FileManager::getSessions(FileManager::classes[n].getClassName());

				for (int i = 1; i <= classSessions.size(); i++)
				{
					QString counter = QString::number(i);
					string csd = classSessions[i - 1].getClassDay();
					QString classDay = QString::fromStdString(csd);

					string cst = classSessions[i - 1].getClassTime();
					QString classTime = QString::fromStdString(cst);

					ui.ClassDayTxtBox->append(counter + "- " + classDay);
					ui.ClassTimeTxtBox->append(classTime);
					if (i != classSessions.size())
					{
						ui.ClassDayTxtBox->append("");
						ui.ClassTimeTxtBox->append("");
					}
				}
				ui.CSNTxtBox->clear();
				ui.BookClassTimeWidget->setVisible(true);
			}
			else
			{
				ui.ClassMsgE->setText("You are already in this class");
				ui.BookClassWidget->setGeometry(820, 190, 420, 640);
				ui.VCSTButton->setGeometry(120, 570, 201, 50);
				ui.ClassMsgE->setVisible(true);
			}
		}
	}
	else
	{
		ui.BookClassWidget->setGeometry(820, 190, 420, 640);
		ui.VCSTButton->setGeometry(120, 570, 201, 50);
		ui.ClassMsgE->setVisible(true);
	}

}

void MemberLoggedInPage::ExitBCButtonClicked()
{
	ui.BookClassWidget->setVisible(false);
}

void MemberLoggedInPage::VCSTConfirmButtonClicked()
{
	ui.BookClassTimeWidget->setGeometry(610, 210, 331, 461);
	ui.VCSTConfirmButton->setGeometry(90, 390, 171, 50);
	ui.ClassTimeMsgE->setVisible(false);

	QString csn = ui.CSNTxtBox->text();
	if (csn != "")
	{
		classSessionNumber = csn.toInt();
		if (classSessionNumber > classSessions.size() || classSessionNumber < 1)
		{
			ui.BookClassTimeWidget->setGeometry(610, 210, 331, 500);
			ui.VCSTConfirmButton->setGeometry(90, 430, 171, 50);
			ui.ClassTimeMsgE->setVisible(true);
		}
		else
		{
			int flag = Receptionist::addToClass(classSessions[classSessionNumber - 1].getClassId(), MemberID);
			if (flag == 1)
			{
				ui.BookClassTimeWidget->setVisible(false);
				ui.DoneMsgLabel->setText("Done!");
				ui.DoneMsgLabel->setStyleSheet("background: none; color: rgba(152, 251, 152, 0.7)");
				ui.DoneMsg->setVisible(true);
			}
			else
			{
				setAllWidgetsVisibleFalse();
				ui.WLConfirmationMsg->setVisible(true);
			}
		}
	}
	else
	{
		ui.BookClassTimeWidget->setGeometry(610, 210, 331, 500);
		ui.VCSTConfirmButton->setGeometry(90, 430, 171, 50);
		ui.ClassTimeMsgE->setVisible(true);
	}


}

void MemberLoggedInPage::ExitBCTButtonClicked()
{
	ui.BookClassTimeWidget->setVisible(false);
}

void MemberLoggedInPage::UnbookClassButtonClicked()
{
	setAllWidgetsVisibleFalse();
	ui.UnbookClassMsgE->setVisible(false);
	ui.ClassToCancelTxtBox->clear();
	ui.UnbookClassWidget->setGeometry(830,330,371,451);
	ui.ConfirmUnbookButton->setGeometry(120,390,141,50);
	ui.UnbookClassWidget->setVisible(true);
}

void MemberLoggedInPage::ConfirmUnbookButtonClicked()
{
	if (ui.ClassToCancelTxtBox->text() == "")
	{
		ui.UnbookClassMsgE->setText("Please choose a Class");
		ui.UnbookClassMsgE->setVisible(true);
		ui.UnbookClassWidget->setGeometry(830,330,371,490);
		ui.ConfirmUnbookButton->setGeometry(120,430,141,50);
	}
	else
	{
		QString cn = ui.ClassToCancelTxtBox->text();
		int CN = cn.toInt();
		if (FileManager::AlreadyInClass(MemberID,CN))
		{
		Receptionist::removeFromClass(CN, MemberID);
		Receptionist::addFirstInWaiting(CN);
		ui.UnbookClassWidget->setVisible(false);
		ui.UnbookClassMsgE->setVisible(false);
		ui.DoneMsgLabel->setText("Done!");
		ui.DoneMsgLabel->setStyleSheet("background: none; color: rgba(152, 251, 152, 0.7)");
		ui.DoneMsg->setVisible(true);
		}
		else
		{
			ui.UnbookClassMsgE->setText("You are not assigned to this class");
			ui.UnbookClassMsgE->setVisible(true);
			ui.UnbookClassWidget->setGeometry(830, 330, 371, 490);
			ui.ConfirmUnbookButton->setGeometry(120, 430, 141, 50);
		}
	}
}

void MemberLoggedInPage::ExitUBCButtonClicked()
{
	ui.UnbookClassWidget->setVisible(false);
}

void MemberLoggedInPage::WLConfirmationMsgBClicked()
{
	ui.WLConfirmationMsg->setVisible(false);
}

void MemberLoggedInPage::WLConfirmationMsgOClicked()
{
	Receptionist::addToWaiting(classSessions[classSessionNumber - 1].getClassId(), MemberID);
	ui.DoneMsgLabel->setText("Joined Waiting List.");
	ui.DoneMsgLabel->setStyleSheet("background: none; color: rgba(152, 251, 152, 0.7)");
	ui.DoneMsg->setVisible(true);
}


//Padel Widget
void MemberLoggedInPage::ShowCourtsButtonClicked()
{
	setAllWidgetsVisibleFalse();
	ui.CourtsWidget->setVisible(true);
}

void MemberLoggedInPage::ExitCWButtonClicked()
{
	ui.CourtsWidget->setVisible(false);
}

void MemberLoggedInPage::CheckButtonClicked()
{
	ui.ErrorMsgP->setVisible(false);
	ui.AvailableMsgP->setVisible(false);

	if (ui.DayTxtBox->text() == "" ||
		ui.MonthTxtBox->text() == "" ||
		ui.YearTxtBox->text() == "" ||
		ui.SlotTxtBox->text() == ""||
		ui.CourtNumberTxtBox->text() == "" ||
		ui.CourtNumberTxtBox->text().toInt() < 1 ||
		ui.CourtNumberTxtBox->text().toInt() > 20)
	{
		ui.ErrorMsgP->setText("Invalid inputs");
		ui.ErrorMsgP->setVisible(true);
		ui.AvailableMsgP->setVisible(false);
		ui.CheckButton->setGeometry(60, 390, 201, 50);
		ui.BookCourtButton->setGeometry(60, 460, 201, 50);
	}
	else
	{
		QString d = ui.DayTxtBox->text();
		int day = d.toInt();

		d = ui.MonthTxtBox->text();
		int month = d.toInt();

		d = ui.YearTxtBox->text();
		int year = d.toInt();

		Date slotDate(day,month,year);

		d = ui.SlotTxtBox->text();
		int hour = d.toInt();

		d = ui.CourtNumberTxtBox->text();
		int id = d.toInt();

		Slot s(id, hour, slotDate);

		bool Valid = (Date::getTodaysDate() == slotDate) and !(Date::isHourInPast(hour));


		if (!(Date::isFutureDate(slotDate)) && !Valid || hour < 0 || hour > 23 || day < 1 || day > 31 || month < 1 || month > 12)
		{
			ui.ErrorMsgP->setText("Invalid Date");
			ui.ErrorMsgP->setVisible(true);
			ui.AvailableMsgP->setVisible(false);
			ui.CheckButton->setGeometry(60, 390, 201, 50);
			ui.BookCourtButton->setGeometry(60, 460, 201, 50);
		}
		else if (BookingSystem::isSlotAvailable(s))
		{
			ui.AvailableMsgP->setVisible(true);
			ui.ErrorMsgP->setVisible(false);
			ui.CheckButton->setGeometry(60, 390, 201, 50);
			ui.BookCourtButton->setGeometry(60, 460, 201, 50);
		}
		else
		{
			s = BookingSystem::searchNext(slotDate, hour, FileManager::courts[id].getLocation());

			day = s.getDate().getDay();
			d = QString::number(day);
			ui.DayLabel->setText("  Day : " + d);

			month = s.getDate().getMonth();
			d = QString::number(month);
			ui.MonthLabel->setText("  Month : " + d);

			year = s.getDate().getYear();
			d = QString::number(year);
			ui.YearLabel->setText("  Year : " + d);

			hour = s.getHour();
			d = QString::number(hour);
			ui.HourLabel->setText("  Hour : " + d);

			slotMember = s;
			ui.NextAvailableSlotMsg->setVisible(true);
		}

	}
}

void MemberLoggedInPage::BookCourtButtonClicked()
{
	ui.ErrorMsgP->setVisible(false);

	QString d = ui.DayTxtBox->text();
	int day = d.toInt();

	d = ui.MonthTxtBox->text();
	int month = d.toInt();

	d = ui.YearTxtBox->text();
	int year = d.toInt();

	Date slotDate(day, month, year);

	d = ui.SlotTxtBox->text();
	int hour = d.toInt();

	d = ui.CourtNumberTxtBox->text();
	int id = d.toInt();

	Slot s(id, hour, slotDate);

	bool Valid = (Date::getTodaysDate() == slotDate) and !(Date::isHourInPast(hour));


	if (!(Date::isFutureDate(slotDate)) && !Valid || hour < 0 || hour > 23 || day < 1 || day > 31 || month < 1 || month > 12)
	{
		ui.ErrorMsgP->setText("Invalid Date");
		ui.ErrorMsgP->setVisible(true);
		ui.AvailableMsgP->setVisible(false);
		ui.CheckButton->setGeometry(60, 390, 201, 50);
		ui.BookCourtButton->setGeometry(60, 460, 201, 50);
	}
	else if (!(ui.DayTxtBox->text() == "" ||
		ui.MonthTxtBox->text() == "" ||
		ui.YearTxtBox->text() == "" ||
		ui.SlotTxtBox->text() == ""||
		ui.CourtNumberTxtBox->text() == ""))
	{
		if (!BookingSystem::isSlotAvailable(s))
		{
			ui.ErrorMsgP->setText("Not Available");
			ui.ErrorMsgP->setVisible(true);
			ui.AvailableMsgP->setVisible(false);
			ui.CheckButton->setGeometry(60, 390, 201, 50);
			ui.BookCourtButton->setGeometry(60, 460, 201, 50);
		}
		else
		{
		BookingSystem::makeBooking(s, MemberID);
		int p = FileManager::courts[id].getBookingPrice();
		QString price = QString::number(p);
		ui.DoneMsgLabel->setText("Slot Price is : " + price);
		ui.DoneMsg->setVisible(true);
		ui.DayTxtBox->clear();
		ui.MonthTxtBox->clear();
		ui.YearTxtBox->clear();
		ui.SlotTxtBox->clear();
		ui.CourtNumberTxtBox->clear();
		ui.CheckButton->setGeometry(60, 350, 201, 50);
		ui.BookCourtButton->setGeometry(60, 440, 201, 50);
		ui.AvailableMsgP->setVisible(false);
		}
	}
	else
	{
		ui.ErrorMsgP->setText("Please fill all fields");
		ui.ErrorMsgP->setVisible(true);
		ui.AvailableMsgP->setVisible(false);
		ui.CheckButton->setGeometry(60, 390, 201, 50);
		ui.BookCourtButton->setGeometry(60, 460, 201, 50);
	}
}

void MemberLoggedInPage::CancelBookingButtonClicked()
{
	setAllWidgetsVisibleFalse();
	ui.CancelBookingWidget->setGeometry(590, 210, 371, 361);
	ui.ConfirmCancelBookingButton->setGeometry(120, 300, 141, 50);
	ui.CancelBookingMsgE->setVisible(false);
	ui.CancelBookingWidget->setVisible(true);
	ui.BookingToCancelTxtBox->setText("");

	set<Slot>CurrentMemberSlots = FileManager::members[MemberID].getSlots();
	int count = 1;
	ui.CancelBookingTextBox->setText("");
	for (auto it = CurrentMemberSlots.begin(); it != CurrentMemberSlots.end(); it++)
	{
		QString n = QString::number(count);
		int day = (*it).getDate().getDay();
		QString d = QString::number(day);

		int month = (*it).getDate().getMonth();
		QString m = QString::number(month);

		int year = (*it).getDate().getYear();
		QString y = QString::number(year);

		int hour = (*it).getHour();
		QString h = QString::number(hour);

		string location = FileManager::courts[(*it).getCourtID()].getLocation();
		QString l = QString::fromStdString(location);
		ui.CancelBookingTextBox->append(n + "- Location : " + l + " Date : (" + d + '/' + m + '/' + y + ") Hour : " + h);
		ui.CancelBookingTextBox->append("");
		count++;
	}
}

void MemberLoggedInPage::ConfirmCancelBookingButtonClicked()
{
	QString s = ui.BookingToCancelTxtBox->text();
	int index = s.toInt();
	set<Slot> currentMemberSlots = FileManager::members[MemberID].getSlots();
	if (ui.BookingToCancelTxtBox->text() != "" && index >= 1 && index <= currentMemberSlots.size())
	{
		auto it = currentMemberSlots.begin();
		advance(it, index - 1);
		if (BookingSystem::cancelBooking(MemberID, *it))
		{
			ExitCBWButtonClicked();
			ui.DoneMsgLabel->setText("Done!");
			ui.DoneMsg->setVisible(true);
		}
		else
		{
			ui.CancelBookingMsgE->setText("Sorry, Too late to cancel!");
			ui.CancelBookingWidget->setGeometry(590, 210, 371, 420);
			ui.ConfirmCancelBookingButton->setGeometry(120, 350, 141, 50);
			ui.CancelBookingMsgE->setVisible(true);
		}
	}
	else
	{
		ui.CancelBookingMsgE->setText("Not Valid");
		ui.CancelBookingWidget->setGeometry(590, 210, 371, 420);
		ui.ConfirmCancelBookingButton->setGeometry(120, 350, 141, 50);
		ui.CancelBookingMsgE->setVisible(true);
	}
}

void MemberLoggedInPage::ExitCBWButtonClicked()
{
	ui.CancelBookingWidget->setVisible(false);
}

void MemberLoggedInPage::NextAvailableSlotBClicked()
{
	ui.NextAvailableSlotMsg->setVisible(false);
}

void MemberLoggedInPage::NextAvailableSlotSClicked()
{
	BookingSystem::makeBooking(slotMember, MemberID);
	ui.NextAvailableSlotMsg->setVisible(false);
	ui.DoneMsg->setVisible(true);
}


//Profile Widget
void MemberLoggedInPage::ProfileButtonClicked()
{
	setAllWidgetsVisibleFalse();
	ui.ProfileWidget->setVisible(true);
	QString Fname = QString::fromStdString(FileManager::members[MemberID].getFname());
	ui.NameLabel->setText("Hello, " + Fname);
	ui.IDLabel->setText("ID : " + QString::number(MemberID));
	if (FileManager::members[MemberID].getPlanName() == "")
	{
		ui.PlanLabel->setText("Plan : Not Subscribed Yet.");
	}
	else
	{
		ui.PlanLabel->setText(QString::fromStdString(FileManager::members[MemberID].getPlanName()));
	}
	if (FileManager::members[MemberID].getVipStatus())
	{
		ui.VIPMLabel->setStyleSheet("color: rgba( 253, 208, 23,0.7); background-color: rgba(0, 0, 0, 0.0);");
		ui.VIPMLabel->setText("VIP Member!");
		ui.ProfileWidget->setGeometry(60, 40, 381, 411);
		ui.VIPWidget->setVisible(false);
		ui.ProfileWidget->setGeometry(60, 40, 381, 221);
	}
	else
	{
		ui.ProfileWidget->setGeometry(60,40,381,411);
		ui.VIPWidget->setVisible(true);
		ui.VIPMLabel->setStyleSheet("background: none; color: rgba(135, 206, 235, 0.8)");
		ui.VIPMLabel->setText("Not a VIP member");
	}
}

void MemberLoggedInPage::ExitPWButtonClicked()
{
	ui.ProfileWidget->setVisible(false);
}

void MemberLoggedInPage::VIPButtonClicked()
{
	ui.VIPConfirmWidget->setVisible(true);
}

void MemberLoggedInPage::VIPConfirmButtonClicked()
{
	FileManager::members[MemberID].setVipStatus(true);
	FileManager::members[MemberID].setTotalPaid(FileManager::members[MemberID].getTotalPaid() + ReadData::getVipPrice());
	ui.VIPConfirmWidget->setVisible(false);
	ui.VIPWidget->setVisible(false);
	ui.VIPMLabel->setStyleSheet("background: none; color: rgba( 253, 208, 23,0.7);");
	ui.VIPMLabel->setText("VIP Member!");
	ui.ProfileWidget->setGeometry(60,40,381,221);

}

void MemberLoggedInPage::NotificationButtonClicked()
{
	setAllWidgetsVisibleFalse();
	ui.NotificationTxtEdit->clear();
	vector<string> notHistory = FileManager::members[MemberID].getInbox();


	for (int i = 0; i < notHistory.size(); i++)
	{
		QString notificationMsg = QString::fromStdString(notHistory[i]);
		ui.NotificationTxtEdit->append(notificationMsg);
		ui.NotificationTxtEdit->append("");
		ui.NotificationTxtEdit->append("");
	}

	ui.NotificationWidget->setVisible(true);
	ui.NotificationButtonDot->setVisible(false);
}

void MemberLoggedInPage::NotificationButtonDotClicked()
{
	NotificationButtonClicked();
	ui.NotificationButtonDot->setVisible(false);
}

void MemberLoggedInPage::HaveNotification()
{
	if (FileManager::members[MemberID].getInbox().size())
	{
		ui.NotificationButtonDot->setVisible(true);
	}
}

void MemberLoggedInPage::ExitNWButtonClicked()
{
	ui.NotificationWidget->setVisible(false);
}



void MemberLoggedInPage::ExitButtonClicked()
{
	FileManager::clearInbox(MemberID);
	FileManager::Save();
	QApplication::exit(0);
}

MemberLoggedInPage::~MemberLoggedInPage()
{}
