#include "LoginPage.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include<iostream>
#include<map>
#include<vector>
#include "FileManager.h"
#include"Subscription.h"
#include "BookingSystem.h"

using namespace std;


int main(int argc, char *argv[])
{
	FileManager::Load();
	FileManager::itsFirstDay();
	FileManager::handleSubscriptions();
	BookingSystem::checkSlotTimePassed();
	BookingSystem::setBookedSlots(FileManager::getBookedSlots());
	Receptionist::sendRenewalNoti();

    QApplication GymPadelSystem(argc, argv);
	LoginPage MainWindow;
    MainWindow.showFullScreen();


    return GymPadelSystem.exec();
}