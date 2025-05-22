#pragma once

#include <QMainWindow>
#include "ui_LoginPage.h"
#include <QTimer>
#include "SignUpPage.h"
#include "MemberLoggedInPage.h"
#include "ManagerPage.h"
#include "ReceptionistPage.h"
#include "CoachPage.h"

class LoginPage : public QMainWindow
{
	Q_OBJECT

public:
	LoginPage(QWidget *parent = nullptr);
	~LoginPage();

private:
	Ui::LoginPageClass ui;
	SignUpPage* signUpPage;
	MemberLoggedInPage* memberPage;
	ManagerPage* managerPage;
	ReceptionistPage* receptionistPage;
	CoachPage* coachPage;
	long long AccountID;

private slots:
	void LoginButtonClicked();
	void SignUpButtonClicked();
	void ExitButtonClicked();
};
