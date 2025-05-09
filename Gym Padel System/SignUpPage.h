#pragma once

#include <QMainWindow>
#include "ui_SignUpPage.h"
#include "MemberLoggedInPage.h"

class SignUpPage : public QMainWindow
{
	Q_OBJECT

public:
	SignUpPage(QWidget* parent = nullptr);
	~SignUpPage();
	long long MemberID;

private:
	Ui::SignUpPageClass ui;
	MemberLoggedInPage* memberPage;

private slots:
	void SignUpButtonClicked();
	void ExitButtonClicked();
};
