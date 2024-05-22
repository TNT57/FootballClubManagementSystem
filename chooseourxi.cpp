#include "chooseourxi.h"
#include "ui_chooseourxi.h"

ChooseOurXI::ChooseOurXI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseOurXI)
{
    ui->setupUi(this);
    loadPlayers();
}

ChooseOurXI::~ChooseOurXI()
{
    delete ui;
}

void ChooseOurXI::loadPlayers() {
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("SELECT ShirtNumber, Position, Name, Selected FROM Player");

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

void ChooseOurXI::on_confirmButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);

    // Set all players to unselected
    query.prepare("UPDATE Player SET Selected = 0");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to update player selection");
        return;
    }

    query.prepare("UPDATE Player SET Selected = 1 WHERE ShirtNumber = :ShirtNumber");
    bool success = true;

    for (int i = 0; i < ui -> listWidget -> count(); i++) {
        QListWidgetItem *item = ui -> listWidget -> item(i);

        if (item -> checkState() == Qt::Checked) {
            QString shirtNumber = item -> text().split(" - ").first();
            query.bindValue(":ShirtNumber", shirtNumber);

            if (!query.exec()) {
                success = false;
                QMessageBox::critical(this, "Error", "Failed to update player selection");
                return; // avoid display multiple error messages - break when error happens
            }
        }
    }

    if (success) {
        QMessageBox::information(this, "Update Successfully", "Players are successfully selected\n"
                                                              "Please reload the table");
    }
}
