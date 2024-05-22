#include "navigator.h"
#include "ui_navigator.h"
#include <QDebug>

Navigator::Navigator(QWidget *parent): QMainWindow(parent), ui(new Ui::Navigator) {
    ui -> setupUi(this);

    // initialise database
    database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    //database.setDatabaseName("C:\\Users\\trung\\Downloads\\PlayerManagement.db");
    database.setDatabaseName("D:\\University of Adelaide\\COMP SCI 1102\\PlayerManagement.db");
    //database.setDatabaseName("/Users/tom/PlayerManagement.db");

    // check the database is working or not
    if(!database.open()) {
        qDebug() << "Error: Unable to open database";
    }

    else {
        qDebug() << "Database open successfully";
    }

    //initializd pointer to other features
    ptrPeople = new People();
    ptrMatchFixture = new MatchFixture();
    ptrTeamStatistics = new TeamStatistics();

    //Set up background image for navigator
    QPixmap navigatorBackgroundImage("E:\\Workspace\\FootballClubManagementSystem\\images\\wallpaperflare.com_wallpaper.jpg");
    int w = ui -> navigatorBackgroundImg -> width();
    int h = ui -> navigatorBackgroundImg -> height();
    ui -> navigatorBackgroundImg -> setPixmap(navigatorBackgroundImage.scaled(w,h,Qt::KeepAspectRatioByExpanding));


    // Change the button color to light blue with a stylesheet
    ui -> peopleButton -> setStyleSheet("QPushButton {"
                                        "    background-color: rgba(255, 255, 255, 0.15);"
                                        "    color: black;" // Set text color to white for better readability #f94449
                                        "    border-style: outset;"
                                        "    border-width: 2px;"
                                        "    border-radius: 15px;"
                                        "    border-color: beige;"
                                        "    font: bold 14px;"
                                        "    padding: 6px;"
                                        "}");

    ui -> matchButton -> setStyleSheet("QPushButton {"
                                       "    background-color: rgba(255, 255, 255, 0.15);"
                                       "    color: black;"
                                       "    border-style: outset;"
                                       "    border-width: 2px;"
                                       "    border-radius: 15px;"
                                       "    border-color: beige;"
                                       "    font: bold 14px;"
                                       "    padding: 6px;"
                                       "}");

    ui -> teamButton -> setStyleSheet("QPushButton {"
                                      "    background-color: rgba(255, 255, 255, 0.15);"
                                      "    color: black;"
                                      "    border-style: outset;"
                                      "    border-width: 2px;"
                                      "    border-radius: 15px;"
                                      "    border-color: beige;"
                                      "    font: bold 14px;"
                                      "    padding: 6px;"
                                      "}");

    ui -> label -> setStyleSheet("QPushButton {"
                                 "    background-color: gray;"
                                 "    color: gray;"
                                 "    border-style: outset;"
                                 "    border-width: 2px;"
                                 "    border-radius: 10px;"
                                 "    border-color: beige;"
                                 "    font: bold 14px;"
                                 "    padding: 6px;"
                                 "}");

    //Change words color to white
    ui -> label -> setStyleSheet("QLabel {"
                                 "color: white;"
                                 "}");

    ui -> label_2 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    // Set the tooltip for the label
    ui -> infoLabel -> setToolTip("'i' label support info: \n"
                                  "Welcome to our project Football Club Mangement System! \nA system that stores a club's team members including players and staves"
                                  " where you can add delete and even edit people's information.\n"
                                  "Another interesting thing of this program is that you can do Match Simulation to get results by managing players.\n"
                                  "So dive right in and explore the program.\n"
                                  "Remember there would always be support through this 'i' label.");

    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "color: black;"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "border-color: beige;"
                                     "}");
}

Navigator::~Navigator() {
    //delete the pointers
    delete ui;
    delete ptrPeople;
    delete ptrMatchFixture;
    delete ptrTeamStatistics;
    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());
}

// open people management feature ui
void Navigator::on_peopleButton_clicked() {
    ptrPeople -> setWindowTitle("People");
    ptrPeople -> show();
}

// opent the match fixture feature ui
void Navigator::on_matchButton_clicked() {
    ptrMatchFixture -> setWindowTitle("Match Fixture");
    ptrMatchFixture -> show();
}

// open the team statistic ui
void Navigator::on_teamButton_clicked() {
    ptrTeamStatistics -> setWindowTitle("Team Statistics");
    ptrTeamStatistics -> show();
}

