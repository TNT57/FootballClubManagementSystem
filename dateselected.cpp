#include "dateselected.h"
#include "ui_dateselected.h"

DateSelected::DateSelected(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DateSelected)
{
    ui->setupUi(this);
    ptrStartingList = new StartingList();
    //ptrOurStartingXI = new OurStartingXI();
    //ptrOpponentStartingXI = new OpponentStartingXI();
}

DateSelected::~DateSelected()
{
    delete ui;
    delete ptrStartingList;
    //delete ptrOurStartingXI;
    //delete ptrOpponentStartingXI;
}

void DateSelected::fetchMatchData(const QDate &date)
{
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("SELECT * FROM MatchRecord WHERE Date = :Date");
    query.bindValue(":Date", date.toString("dd/MM/yyyy"));
    if (query.exec() && query.next()) {
        ui->dateLabel->setText("Date: " + query.value("Date").toString());
        ui->timeLabel->setText("Time: " + query.value("Time").toString());
        ui->opponentTeamNameLabel->setText("Opponent Team Name: "
                                           + query.value("OpponentName").toString());
        ui->locationLabel->setText("Location: " + query.value("Location").toString());
        ui -> showStartingListButton -> show();  // Make the button visible
    }

    else {
        // Clear the labels if there is no match on the selected date
        ui->dateLabel->clear();
        ui->timeLabel->clear();
        ui->opponentTeamNameLabel->clear();
        ui->locationLabel->clear();
        ui -> showStartingListButton -> hide();
        QMessageBox::information(this, "There is no match today", "There is no match today");
    }
}

void DateSelected::on_showStartingListButton_clicked()
{
    //ptrOurStartingXI -> setWindowTitle("Starting XI");
    //ptrOurStartingXI -> show();

    ptrStartingList -> setWindowTitle("Starting XI");
    ptrStartingList -> show();
}

