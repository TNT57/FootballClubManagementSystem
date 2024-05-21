#include "simulatematch.h"
#include "ui_simulatematch.h"

SimulateMatch::SimulateMatch(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SimulateMatch)
{
    ui->setupUi(this);
}

SimulateMatch::~SimulateMatch()
{
    delete ui;
}

QString SimulateMatch::get_opponentName() {
    return opponentName;
}

void SimulateMatch::set_opponentName(QString opponentName) {
    this -> opponentName = opponentName;
}

bool SimulateMatch::checkNumPlayers() {
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);

    // Check if there are exactly 11 players selected in each team
    query.prepare("SELECT COUNT(*) FROM Player WHERE Selected = 1");

    if (query.exec() && query.next() && query.value(0).toInt() == 11) {
        QString queryString = QString("SELECT COUNT(*) FROM %1 WHERE Selected = 1").arg(opponentName);
        query.prepare(queryString);

        if (query.exec() && query.next() && query.value(0).toInt() == 11) {
            // Can simulate match
            return true;
        }

        else {
            QMessageBox::critical(this, "Failed to simulate match", "Both teams require exactly 11 players to simulate match");
            return false;
        }
    }

    else {
        QMessageBox::critical(this, "Failed to simulate match", "Both teams require exactly 11 players to simulate match");
        return false;
    }
}

void SimulateMatch::simulate() {
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    double ourGoals = 0;
    double opponentGoals = 0;

    query.prepare("SELECT Position, Apps, Goals, SavePer90 FROM Player WHERE Selected = 1");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to simulate match");
        return;
    }

    while (query.next()) {
        QString position = query.value(0).toString();
        double apps = query.value(1).toDouble();
        double goals = query.value(2).toDouble();
        double savePer90 = query.value(3).toDouble();

        ourGoals += goals/apps;

        if (position == "GK") {
            opponentGoals -= savePer90/5;
        }
    }

    QString queryString = QString("SELECT Position, Apps, Goals, SavePer90 FROM %1 WHERE Selected = 1").arg(opponentName);
    query.prepare(queryString);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to simulate match");
        return;
    }

    while (query.next()) {
        QString position = query.value(0).toString();
        double apps = query.value(1).toDouble();
        double goals = query.value(2).toDouble();
        double savePer90 = query.value(3).toDouble();

        opponentGoals += goals/apps;

        if (position == "GK") {
            ourGoals -= savePer90/5;
        }
    }

    qDebug() << "Our Goals: " << ourGoals;
    qDebug() << "Opponent Goals: " << opponentGoals;

    // round goals to int
    int roundedOurGoals = qRound(ourGoals);
    int roundedOpponentGoals = qRound(opponentGoals);

    qDebug() << "Our Goals (rounded): " << roundedOurGoals;
    qDebug() << "Opponent Goals (rounded): " << roundedOpponentGoals;

    // goals cannot be negative
    roundedOurGoals = qMax(0, roundedOurGoals);
    roundedOpponentGoals = qMax(0, roundedOpponentGoals);

    qDebug() << "Our Goals (final): " << roundedOurGoals;
    qDebug() << "Opponent Goals (final): " << roundedOpponentGoals;


    ui -> ourGoals -> setText(QString::number(roundedOurGoals));
    ui -> opponentGoals -> setText(QString::number(roundedOpponentGoals));
    ui -> ourTeamLabel -> setText("Our Team");
    ui -> opponentTeamLabel -> setText(opponentName);
}
