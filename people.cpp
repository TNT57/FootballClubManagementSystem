#include "people.h"
#include "ui_people.h"
#include <QLabel>


People::People(QWidget *parent): QWidget(parent), ui(new Ui::People) {
    ui -> setupUi(this);
    // pointers to other features
    ptrPlayer = new Player();
    ptrStaff = new Staff();
    ptrTransferList = new TransferList();

    // Add icon to playerButton
    QIcon playerIcon("D:\\University of Adelaide\\COMP SCI 1102\\FootballClubManagementSystem\\images\\meowPlayer-removebg-preview.png");
    // QIcon playerIcon("E:\\Workspace\\FootballClubManagementSystem\\images\\meowPlayer-removebg-preview.png"); // Replace with your icon path

    ui -> playerButton -> setIcon(playerIcon);
    ui -> playerButton -> setIconSize(QSize(50, 50)); // Set the desired icon size
    ui -> playerButton -> setStyleSheet("QPushButton {"
                                        "background-color: rgba(255, 255, 255, 0.25);"
                                        "color: black;"
                                        "border-radius: 15px;"
                                        "}"
                                        "QToolTip {"
                                        "background-color: white;"
                                        "color: black;"
                                        "}");

    // Add icon to staffButton
    // Replace with your icon path
    QIcon staffIcon("D:\\University of Adelaide\\COMP SCI 1102\\FootballClubManagementSystem\\images\\sportStaffImg.png");
    // QIcon staffIcon("E:\\Workspace\\FootballClubManagementSystem\\images\\sportStaffImg.png");

    ui -> staffButton -> setIcon(staffIcon);
    ui -> staffButton -> setIconSize(QSize(50, 50)); // Set the desired icon size
    ui -> staffButton -> setStyleSheet("QPushButton {"
                                       "background-color: rgba(255, 255, 255, 0.25);"
                                       "color: black;"
                                       "border-radius: 15px;"
                                       "}"
                                       "QToolTip {"
                                       "background-color: white;"
                                       "color: black;"
                                       "}");


    //Change the title word color to white
    ui -> label -> setStyleSheet("QLabel { color : white; }");

    //Change background image to blurred
    QPixmap backgroundImg("D:\\University of Adelaide\\COMP SCI 1102\\FootballClubManagementSystem\\images\\imageBlur.png");
    // QPixmap backgroundImg("E:\\Workspace\\FootballClubManagementSystem\\images\\imageBlur.png");

    int w = ui -> backgroundImg -> width();
    int h = ui -> backgroundImg -> height();
    ui -> backgroundImg -> setPixmap(backgroundImg.scaled(w,h,Qt::KeepAspectRatioByExpanding));

    //Change button shape and opacity
    ui -> transferListButton -> setStyleSheet("QPushButton {"
                                              "background-color: rgba(255, 255, 255, 0.25);"
                                              "color: black;"
                                              "border-radius: 15px;"
                                              "}"
                                              "QToolTip {"
                                              "background-color: white;"
                                              "color: black;"
                                              "}");


    // Set the tooltip for the label
    ui -> infoLabel -> setToolTip("Player: show the statistics of all the players.\n"
                                  "Staff: see all the information of staff in the team.\n"
                                  "Transferlist: see the players on the team's transfer list.");

    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "}");
}

People::~People() {
    delete ui;
    delete ptrPlayer;
    delete ptrStaff;
    delete ptrTransferList;
}

//open player table feature
void People::on_playerButton_clicked() {
    ptrPlayer -> setWindowTitle("Player");
    ptrPlayer -> show();
}

//open staff table feature
void People::on_staffButton_clicked() {
    ptrStaff -> setWindowTitle("Staff");
    ptrStaff -> show();
}

//open transfer list feature
void People::on_transferListButton_clicked() {
    ptrTransferList -> setWindowTitle("Transfer List");
    ptrTransferList -> show();
}

