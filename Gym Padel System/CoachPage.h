#pragma once

#include <QMainWindow>
#include "ui_CoachPage.h"
#include "Coach.h"
#include "FileManager.h"

class CoachPage : public QMainWindow
{
	Q_OBJECT

public:
	CoachPage(long long cid, QWidget* parent = nullptr);
	~CoachPage();

private:
	Ui::CoachPageClass ui;
	long long CoachID;

private slots:

	void ExitButtonClicked();
};

