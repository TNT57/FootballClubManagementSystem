#include "matchfixture.h"
#include "ui_matchfixture.h"
#include <QPushButton>
#include <QVBoxLayout>


MatchFixture::MatchFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MatchFixture)
{
    ui->setupUi(this);

    // Set up info button
    // Set the text of the button to "i"
    ui->label_2->setText("i");
    // Set the tooltip for the label
    ui->label_2->setToolTip("Click on the day to see the match detail!");

    // Set the size of the label to be a square
    ui->label_2->setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui->label_2->setStyleSheet("QLabel {"
                               "border: 1px solid black;"
                               "border-radius: 15px;" // Half of width/height
                               "}");


    // Set green for current date
    QTextCharFormat currentDateFormat;
    currentDateFormat.setBackground(Qt::green);
    QDate currentDate = QDate::currentDate();
    ui -> calendarMatchFixture -> setDateTextFormat(currentDate, currentDateFormat);


    // Fetch all dates from the database that have a match
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("SELECT Date FROM MatchRecord");

    if(query.exec()){
        QTextCharFormat hasMatchFormat;
        hasMatchFormat.setBackground(Qt::red);
        while(query.next()){
            QDate date = QDate::fromString(query.value(0).toString(), "dd/MM/yyyy");
            ui->calendarMatchFixture->setDateTextFormat(date, hasMatchFormat);
        }
    }
}

MatchFixture::~MatchFixture()
{
    delete ui;
    delete ptrDateSelected;
    delete ptrAddMatchFixture;
    delete ptrRemoveMatchFixture;
    delete ptrEditMatchFixture;
}

void MatchFixture::on_addMatchFixtureButton_clicked()
{
    ptrAddMatchFixture = new AddMatchFixture();
    ptrAddMatchFixture -> setWindowTitle("Add Match Fixture");
    ptrAddMatchFixture -> show();
}

void MatchFixture::on_removeMatchFixtureButton_clicked()
{
    ptrRemoveMatchFixture = new RemoveMatchFixture();
    ptrRemoveMatchFixture -> setWindowTitle("Remove Match Fixture");
    ptrRemoveMatchFixture -> show();
}

void MatchFixture::on_calendarMatchFixture_clicked(const QDate &date)
{
    ptrDateSelected = new DateSelected();
    ptrDateSelected -> setWindowTitle("Match Day");
    ptrDateSelected -> show();
    ptrDateSelected -> fetchMatchData(date);

}

void MatchFixture::on_reloadMatchFixture_clicked()
{
    // Clear all date formats
    ui->calendarMatchFixture->setDateTextFormat(QDate(), QTextCharFormat());

    // Set green for current date
    QTextCharFormat currentDateFormat;
    currentDateFormat.setBackground(Qt::green);
    QDate currentDate = QDate::currentDate();
    ui->calendarMatchFixture->setDateTextFormat(currentDate, currentDateFormat);

    // Fetch all dates from the database that have a match
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("SELECT Date FROM MatchRecord");

    if(query.exec()){
        QTextCharFormat hasMatchFormat;
        hasMatchFormat.setBackground(Qt::red);
        while(query.next()){
            QDate date = QDate::fromString(query.value(0).toString(), "dd/MM/yyyy");
            ui->calendarMatchFixture->setDateTextFormat(date, hasMatchFormat);
        }
    }
}

void MatchFixture::on_editMatchFixtureButton_clicked()
{
    ptrEditMatchFixture = new EditMatchFixture();
    ptrEditMatchFixture -> setWindowTitle("Edit Match Fixture");
    ptrEditMatchFixture -> show();
}

