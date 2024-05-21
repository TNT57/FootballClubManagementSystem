#include "people.h"
#include "ui_people.h"
#include <QLabel>


People::People(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::People)
{
    ui->setupUi(this);
    ptrPlayer = new Player();
    ptrStaff = new Staff();

    // Add icon to playerButton
    QIcon playerIcon("C:\\Users\\trung\\Downloads\\meowPlayer-removebg-preview.png"); // Replace with your icon path
    ui->playerButton->setIcon(playerIcon);
    ui->playerButton->setIconSize(QSize(50, 50)); // Set the desired icon size
    ui->playerButton->setStyleSheet("QPushButton {"
                                   "background-color: rgba(255, 255, 255, 0.25);"
                                   "color: black;"
                                   "border-radius: 15px;"
                                   "}"
                                   "QToolTip {"
                                   "background-color: white;"
                                   "color: black;"
                                   "}");


    // Add icon to staffButton
    QIcon staffIcon("C:\\Users\\trung\\Downloads\\sportStaffImg.png"); // Replace with your icon path
    ui->staffButton->setIcon(staffIcon);
    ui->staffButton->setIconSize(QSize(50, 50)); // Set the desired icon size
    ui->staffButton->setStyleSheet("QPushButton {"
                                    "background-color: rgba(255, 255, 255, 0.25);"
                                    "color: black;"
                                   "border-radius: 15px;"
                                    "}"
                                    "QToolTip {"
                                    "background-color: white;"
                                    "color: black;"
                                    "}");


    //Change the title word color to white
    ui->label->setStyleSheet("QLabel { color : white; }");

    //Change background image to blurred
    QPixmap backgroundImg("C:\\Users\\trung\\Downloads\\imageBlur.png");
    int w = ui->backgroundImg->width();
    int h = ui->backgroundImg->height();
    ui->backgroundImg->setPixmap(backgroundImg.scaled(w,h,Qt::KeepAspectRatioByExpanding));

    //Change button shape and opacity


}

People::~People()
{
    delete ui;
    delete ptrPlayer;
    delete ptrStaff;
}

void People::on_playerButton_clicked()
{
    ptrPlayer -> setWindowTitle("Player");
    ptrPlayer -> show();
}

void People::on_staffButton_clicked()
{
    ptrStaff -> setWindowTitle("Staff");
    ptrStaff -> show();
}

