#include "matchfixture.h"
#include "ui_matchfixture.h"

MatchFixture::MatchFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MatchFixture)
{
    ui->setupUi(this);
    ptrDateSelected = new DateSelected();
    ptrAddMatchFixture = new AddMatchFixture();
    ptrRemoveMatchFixture = new RemoveMatchFixture();

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
}

void MatchFixture::on_addMatchFixtureButton_clicked()
{
    ptrAddMatchFixture -> setWindowTitle("Add Match Fixture");
    ptrAddMatchFixture -> show();
}

void MatchFixture::on_removeMatchFixtureButton_clicked()
{
    ptrRemoveMatchFixture -> setWindowTitle("Remove Match Fixture");
    ptrRemoveMatchFixture -> show();
}

void MatchFixture::on_calendarMatchFixture_clicked(const QDate &date)
{
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
