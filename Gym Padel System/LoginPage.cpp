#include "LoginPage.h"
#include <string>
#include "FileManager.h"

using namespace std;

LoginPage::LoginPage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.SMLabel->setVisible(false);

	//Connect Buttons
	connect(ui.LoginButton, &QPushButton::clicked, this, &LoginPage::LoginButtonClicked);
	connect(ui.SignUpButton, &QPushButton::clicked, this, &LoginPage::SignUpButtonClicked);
	connect(ui.ExitButton, &QPushButton::clicked, this, &LoginPage::ExitButtonClicked);
}

void LoginPage::LoginButtonClicked()
{
	if (ui.FNTextBox->text() != "" && ui.MNTextBox->text() != "" && ui.LNTextBox->text() != "" && ui.IDTextBox->text() != "")
	{
		QString QFn = ui.FNTextBox->text();
		string fn = QFn.toStdString();

		QString QMn = ui.MNTextBox->text();
		string mn = QMn.toStdString();

		QString QLn = ui.LNTextBox->text();
		string ln = QLn.toStdString();

		QString QID = ui.IDTextBox->text();
		string SId = QID.toStdString();
		long long id = stoll(SId);
		AccountID = id;


		if (FileManager::matchingNameAndId(fn, mn, ln, id))
		{
			ui.SMLabel->setVisible(false);
			Slot s;
			memberPage = new MemberLoggedInPage(s, AccountID);

			memberPage->showFullScreen();
			QTimer::singleShot(2000, this, [this]() {this->close(); });
		}
		else if (FileManager::isStaff(fn, mn, ln, id))
		{
			ui.SMLabel->setVisible(false);

			string role = FileManager::staff[id]->getRole();
			if (role == "Manager")
			{
				managerPage = new ManagerPage;
				managerPage->showFullScreen();
				QTimer::singleShot(2000, this, [this]() {this->close(); });
			}

			else if (role == "Receptionist")
			{
				receptionistPage = new ReceptionistPage;
				receptionistPage->showFullScreen();
				QTimer::singleShot(2000, this, [this]() {this->close(); });
			}
			else
			{
				coachPage = new CoachPage(AccountID);
				coachPage->showFullScreen();
				QTimer::singleShot(2000, this, [this]() {this->close(); });
			}
		}
		else
		{
			ui.SMLabel->setVisible(true);
			ui.LWidget->setGeometry(180, 140, 320, 650);
			ui.LoginButton->setGeometry(100, 490, 120, 50);
			ui.NewHereLabel->setGeometry(100, 550, 121, 20);
			ui.SignUpButton->setGeometry(100, 580, 121, 50);
		}
	}
	else
	{
		ui.SMLabel->setVisible(true);
		ui.LWidget->setGeometry(180, 140, 320, 650);
		ui.LoginButton->setGeometry(100, 490, 120, 50);
		ui.NewHereLabel->setGeometry(100, 550, 121, 20);
		ui.SignUpButton->setGeometry(100, 580, 121, 50);
	}
}

void LoginPage::SignUpButtonClicked()
{
	signUpPage = new SignUpPage;
	signUpPage->showFullScreen();
	QTimer::singleShot(2000, this, [this]() {this->close(); });
}

void LoginPage::ExitButtonClicked()
{
	FileManager::members[AccountID].clearInbox();
	FileManager::Save();
	QApplication::exit(0);
}
LoginPage::~LoginPage()
{
}
