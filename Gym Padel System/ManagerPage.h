#pragma once

#include <QMainWindow>
#include "ui_ManagerPage.h"
#include "Manager.h"

class ManagerPage : public QMainWindow
{
	Q_OBJECT

public:
	ManagerPage(QWidget* parent = nullptr);
	~ManagerPage();

private:
	Ui::ManagerPageClass ui;

private slots:

	void ExitButtonClicked();
};
