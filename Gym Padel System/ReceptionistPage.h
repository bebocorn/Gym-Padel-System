#pragma once

#include <QMainWindow>
#include "ui_ReceptionistPage.h"
#include "FileManager.h"
#include "Receptionist.h"

class ReceptionistPage : public QMainWindow
{
	Q_OBJECT

public:
	ReceptionistPage(QWidget* parent = nullptr);
	~ReceptionistPage();

private:
	Ui::ReceptionistPageClass ui;


private slots:

	void SearchButtonClicked();
	void ExitButtonClicked();
};
