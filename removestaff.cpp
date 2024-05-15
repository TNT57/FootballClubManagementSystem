#include "removestaff.h"
#include "ui_removestaff.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>    // Include this header for Debug message
#include <QSqlError> // Include this header for QSqlError

//Constructor with parameter
RemoveStaff::RemoveStaff(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveStaff)
{
    ui->setupUi(this);
    populateStaff();
}

//Default Destructor
RemoveStaff::~RemoveStaff()
{
    qDebug() << "~RemoveStaff";
    delete ui;
}

void RemoveStaff::populateStaff() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("/Users/tom/Project-Cpp-OOP/PlayerManagement.db");
    db.setDatabaseName("E:\\Workspace\\FootballClubManagementSystem\\PlayerManagement.db");

    //Check if database is open
    if (db.open()){
        QSqlQuery query("Select StaffID, Name FROM Staff");
        while (query.next()) {
            int staffID = query.value(0).toInt(); // Convert to int
            QString staffName = query.value(1).toString(); // Get the staff's name
            QString staffInfo = QString::number(staffID) + " - " + staffName; // Concatenate shirt number and name
            ui->staffNameComboBox->addItem(staffInfo); //Combine the string to the combo box
        }

    } else {
        qDebug() << "Database connection failed: ";
    }

}

void RemoveStaff::on_staffRemoveConfirmButton_clicked()
{
    QString staffInfo = ui->staffNameComboBox->currentText();
    QStringList infoParts = staffInfo.split(" - "); //Split the string into 2: staffID and Name
    if (infoParts.size() > 1) {
        int staffID = infoParts.at(0).toInt(); //StaffID is the first part of that string
        QSqlQuery query;
        query.prepare("DELETE FROM Staff WHERE StaffID = :staffID");
        query.bindValue(":staffID", staffID);

        //Pop up message for situations
        if (query.exec()){
            QMessageBox::information(this, "Success", "Staff removed successfully");
            ui->staffNameComboBox->removeItem(ui->staffNameComboBox->currentIndex());
        } else {
            QMessageBox::critical(this, "Error", "Could not remove staff " + query.lastError().text());        }
    }
    else {
        QMessageBox::critical(this, "Error", "Invalid selection.");
    }
}




void RemoveStaff::on_staffNameComboBox_activated()
{
    //Leave blank for now
}

