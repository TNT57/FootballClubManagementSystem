#include "chooseopponentxi.h"
#include "ui_chooseopponentxi.h"

ChooseOpponentXI::ChooseOpponentXI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseOpponentXI)
{
    ui->setupUi(this);
    loadPlayers(opponentName);

    // Set the tooltip for the label
    ui->infoLabel->setToolTip("Click reload to see the most updated statistic of the team!");

    // Set the size of the label to be a square
    ui->infoLabel->setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui->infoLabel->setStyleSheet("QLabel {"
                                 "border: 1px solid black;"
                                 "border-radius: 15px;" // Half of width/height
                                 "}");
}

ChooseOpponentXI::~ChooseOpponentXI()
{
    delete ui;
}

void ChooseOpponentXI::set_opponentName(QString opponentName) {
    this -> opponentName = opponentName;
    loadPlayers(opponentName);
}

void ChooseOpponentXI::loadPlayers(QString opponentName) {
    ui -> listWidget -> clear();
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);

    QString queryString = QString("SELECT ShirtNumber, Position, Name, Selected FROM %1").arg(opponentName);
    query.prepare(queryString);

    if (query.exec()) {
        while (query.next()) {
            QString playerInfo = QString("%1 - %2 - %3")
                                     .arg(query.value("ShirtNumber").toString())
                                     .arg(query.value("Position").toString())
                                     .arg(query.value("Name").toString());

            QListWidgetItem *item = new QListWidgetItem(playerInfo, ui->listWidget);
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);

            if (query.value("Selected") == 1) {
                item->setCheckState(Qt::Checked);
            } else {
                item->setCheckState(Qt::Unchecked);
            }
        }
    }

    else {
        QMessageBox::critical(this, "Error", "Failed to load players");
    }
}

void ChooseOpponentXI::on_confirmButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);

    // Set all players to unselected
    QString queryString = QString("UPDATE %1 SET Selected = 0").arg(opponentName);
    query.prepare(queryString);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to update player selection");
        return;
    }

    queryString = QString("UPDATE %1 SET Selected = 1 WHERE ShirtNumber = :ShirtNumber").arg(opponentName);
    query.prepare(queryString);
    bool success = true;

    for (int i = 0; i < ui -> listWidget -> count(); i++) {
        QListWidgetItem *item = ui -> listWidget -> item(i);

        if (item -> checkState() == Qt::Checked) {
            QString shirtNumber = item -> text().split(" - ").first();
            query.bindValue(":ShirtNumber", shirtNumber);

            if (!query.exec()) {
                success = false;
                QMessageBox::critical(this, "Error", "Failed to update player selection");
                break; // avoid display multiple error messages - break when error happens
            }
        }
    }

    if (success) {
        QMessageBox::information(this, "Update Successfully", "Players are successfully selected");
    }
}

