#include "ManagerPage.h"

ManagerPage::ManagerPage(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	vector<long long> MemberIDs = Manager::getMostActive();
	for (int i = 0; i <= 4; i++)
	{
		QString fn = QString::fromStdString(FileManager::members[MemberIDs[i]].getFname());
		QTableWidgetItem* FirstName = new QTableWidgetItem(fn);

		QString mn = QString::fromStdString(FileManager::members[MemberIDs[i]].getMname());
		QTableWidgetItem* MiddleName = new QTableWidgetItem(mn);

		QString ln = QString::fromStdString(FileManager::members[MemberIDs[i]].getLname());
		QTableWidgetItem* LastName = new QTableWidgetItem(ln);

		QString v = QString::number(FileManager::members[MemberIDs[i]].getVisits());
		QTableWidgetItem* Visits = new QTableWidgetItem(v);

		QString id = QString::number(FileManager::members[MemberIDs[i]].getID());
		QTableWidgetItem* ID = new QTableWidgetItem(id);

		ui.tableWidget->setItem(i, 0, FirstName);
		ui.tableWidget->setItem(i, 1, MiddleName);
		ui.tableWidget->setItem(i, 2, LastName);
		ui.tableWidget->setItem(i, 3, Visits);
		ui.tableWidget->setItem(i, 4, ID);

	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			ui.tableWidget->item(i, j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.tableWidget->item(i, j)->setFlags(Qt::ItemIsEditable);
		}
	}
		
	ui.TRtextBox->setText(QString::number(Manager::getTotalRevenue()));

	

	//Connect Buttons
	connect(ui.ExitButton, &QPushButton::clicked, this, &ManagerPage::ExitButtonClicked);
}
void ManagerPage::ExitButtonClicked()
{
	QApplication::exit(0);
}

ManagerPage::~ManagerPage()
{
}
