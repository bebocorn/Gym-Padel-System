#include "CoachPage.h"

CoachPage::CoachPage(long long cid, QWidget* parent)
	: QMainWindow(parent)
{
	CoachID = cid;
	ui.setupUi(this);

	Coach coach = FileManager::coachesInfo[CoachID];
	unordered_set<long long> assignedClasses = coach.getAssignedClasses();
	int i = 0;
	for (auto it = assignedClasses.begin(); it != assignedClasses.end(); it++)
	{
		QString cn = QString::fromStdString(coach.getClassName());
		QTableWidgetItem* ClassName = new QTableWidgetItem(cn);

		QString cd = QString::fromStdString(FileManager::classes[*it].getClassDay());
		QTableWidgetItem* ClassDay = new QTableWidgetItem(cd);

		QString ct = QString::fromStdString(FileManager::classes[*it].getClassTime());
		QTableWidgetItem* ClassTime = new QTableWidgetItem(ct);

		ui.tableWidget->setItem(i, 0, ClassName);
		ui.tableWidget->setItem(i, 1, ClassDay);
		ui.tableWidget->setItem(i, 2, ClassTime);
		i++;
	}

	for (int i = 0; i < assignedClasses.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
		ui.tableWidget->item(i, j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tableWidget->item(i, j)->setFlags(Qt::ItemIsEditable);
		}
	}
	
	//Connect Buttons
	connect(ui.ExitButton, &QPushButton::clicked, this, &CoachPage::ExitButtonClicked);
}
void CoachPage::ExitButtonClicked()
{
	QApplication::exit(0);
}
CoachPage::~CoachPage()
{
}
