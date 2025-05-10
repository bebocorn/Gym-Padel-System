#include "ReceptionistPage.h"

ReceptionistPage::ReceptionistPage(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.IMLabel->setVisible(false);
	ui.tableWidget->setVisible(true);
	ui.tableWidget->setRowHeight(0, 60);

	//Connect Buttons
	connect(ui.ExitButton, &QPushButton::clicked, this, &ReceptionistPage::ExitButtonClicked);
	connect(ui.SearchButton, &QPushButton::clicked, this, &ReceptionistPage::SearchButtonClicked);
}

void ReceptionistPage::SearchButtonClicked()
{
	long long id;
	if (ui.SMTextBox->text() != "")
	{
		id = ui.SMTextBox->text().toLongLong();
		if (FileManager::members.find(id) != FileManager::members.end())
		{
			ui.IMLabel->setVisible(false);

			QString fn = QString::fromStdString(FileManager::members[id].getFname());
			QTableWidgetItem* FirstName = new QTableWidgetItem(fn);

			QString mn = QString::fromStdString(FileManager::members[id].getMname());
			QTableWidgetItem* MiddleName = new QTableWidgetItem(mn);

			QString ln = QString::fromStdString(FileManager::members[id].getLname());
			QTableWidgetItem* LastName = new QTableWidgetItem(ln);

			QString v = QString::number(FileManager::members[id].getVisits());
			QTableWidgetItem* Visits = new QTableWidgetItem(v);

			QString qsID = QString::number(FileManager::members[id].getID());
			QTableWidgetItem* ID = new QTableWidgetItem(qsID);

			QString d = QString::number(FileManager::members[id].getDateOfBirth().getDay());
			QTableWidgetItem* day = new QTableWidgetItem(d);

			QString m = QString::number(FileManager::members[id].getDateOfBirth().getMonth());
			QTableWidgetItem* month = new QTableWidgetItem(m);

			QString y = QString::number(FileManager::members[id].getDateOfBirth().getYear());
			QTableWidgetItem* year = new QTableWidgetItem(y);

			QString ed = QString::number(FileManager::members[id].getEndDate().getDay());
			QTableWidgetItem* endDay = new QTableWidgetItem(ed);

			QString em = QString::number(FileManager::members[id].getEndDate().getMonth());
			QTableWidgetItem* endMonth = new QTableWidgetItem(em);

			QString ey = QString::number(FileManager::members[id].getEndDate().getYear());
			QTableWidgetItem* endYear = new QTableWidgetItem(ey);

			QString p = QString::fromStdString(FileManager::members[id].getPlanName());
			QTableWidgetItem* Plan = new QTableWidgetItem(p);

			ui.tableWidget->setItem(0, 0, FirstName);
			ui.tableWidget->setItem(0, 1, MiddleName);
			ui.tableWidget->setItem(0, 2, LastName);
			ui.tableWidget->setItem(0, 3, Visits);
			ui.tableWidget->setItem(0, 4, ID);
			ui.tableWidget->setItem(0, 5, day);
			ui.tableWidget->setItem(0, 6, month);
			ui.tableWidget->setItem(0, 7, year);
			ui.tableWidget->setItem(0, 8, endDay);
			ui.tableWidget->setItem(0, 9, endMonth);
			ui.tableWidget->setItem(0, 10, endYear);
			ui.tableWidget->setItem(0, 11, Plan);

			for (int i = 0; i <= 11; i++)
			{
				ui.tableWidget->item(0, i)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
				ui.tableWidget->item(0, i)->setFlags(Qt::ItemIsEditable);
			}
		}
		else
		{
			ui.IMLabel->setVisible(true);
			for (int i = 0; i < 12; i++) {
				
				QTableWidgetItem* item = ui.tableWidget->item(0, i);
				if (item) {
					delete item;
					ui.tableWidget->setItem(0, i, nullptr);
				}
				
			}
		}
		
	}
	else
	{
		ui.IMLabel->setVisible(true);
		for (int i = 0; i < 12; i++) {

			QTableWidgetItem* item = ui.tableWidget->item(0, i);
			if (item) {
				delete item;
				ui.tableWidget->setItem(0, i, nullptr);
			}

		}
	}
}

void ReceptionistPage::ExitButtonClicked()
{
	QApplication::exit(0);
}

ReceptionistPage::~ReceptionistPage()
{
}
