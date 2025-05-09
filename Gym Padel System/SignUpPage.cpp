	#include "SignUpPage.h"
	#include "ui_SignUpPage.h"
	#include "ui_LoginPage.h"
	#include <QDialog> 
	#include "Member.h"
	#include"FileManager.h"
	#include <QDebug>

	SignUpPage::SignUpPage(QWidget *parent)
		: QMainWindow(parent)
	{

		ui.setupUi(this);

		ui.SMLabel_E->setVisible(false);

		//Connect Buttons
		connect(ui.SignUpButton ,&QPushButton::clicked, this, &SignUpPage::SignUpButtonClicked);
		connect(ui.ExiButton, &QPushButton::clicked, this, &SignUpPage::ExitButtonClicked);

		
	}

	void SignUpPage::SignUpButtonClicked() 
	{
		Member newMember;

		QString QFn = ui.FNTextBox->text();
		string fn= QFn.toStdString();


		QString QMn = ui.MNTextBox->text();
		string mn = QMn.toStdString();

		QString QLn = ui.LNTextBox->text();
		string ln = QLn.toStdString();

		bool okD, okM, okY;

		QString QD = ui.DTextBox->text();
		int d = QD.toInt(&okD);

		QString QM = ui.MTextBox->text();
		int m = QM.toInt(&okM);

		QString QY = ui.YTextBox->text();
		int y = QY.toInt(&okY);

		if (okD && okM && okY && d <= 31 && d >= 1 && m <= 12 && m >= 1 && y <= 2020 && y >= 1900 && fn != "" && mn != "" && ln != "")
		{
			MemberID = Receptionist::getLastMemberId() + 1;
			FileManager::members[MemberID].setFname(fn);
			FileManager::members[MemberID].setMname(mn);
			FileManager::members[MemberID].setLname(ln);
			FileManager::members[MemberID].setDay(d);
			FileManager::members[MemberID].setMonth(m);
			FileManager::members[MemberID].setYear(y);
			FileManager::members[MemberID].setID(MemberID);

			ui.SMLabel_E->setVisible(false);
			Slot s;

			memberPage = new MemberLoggedInPage(s, MemberID, this);
			memberPage->showFullScreen();
		}
		else
		{
			ui.SMLabel_E->setText("Please Input A Valid Date.");
			ui.SMLabel_E->setVisible(true);
			ui.SignUpButton->setGeometry(100, 590, 120, 50);
			ui.SUWidget->setGeometry(180, 70, 320, 670);
		}

		

	}

	void SignUpPage::ExitButtonClicked()
	{
		FileManager::clearInbox(MemberID);
		FileManager::Save();
		QApplication::exit(0);
	}

	SignUpPage::~SignUpPage()
	{
		delete memberPage;
	}
