#include "dateselected.h"
#include "ui_dateselected.h"

DateSelected::DateSelected(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DateSelected)
{
    ui->setupUi(this);
}

DateSelected::~DateSelected()
{
    delete ui;
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
    }

    else {
        // Clear the labels if there is no match on the selected date
        ui->dateLabel->clear();
        ui->timeLabel->clear();
        ui->opponentTeamNameLabel->clear();
        ui->locationLabel->clear();
        QMessageBox::information(this, "There is no match today", "There is no match today");
    }
}
