#include "dateselected.h"
#include "ui_dateselected.h"

DateSelected::DateSelected(QWidget *parent): QWidget(parent), ui(new Ui::DateSelected) {
    ui -> setupUi(this);
    // init ptr
    ptrOurStartingXI = new OurStartingXI();
    ptrOpponentStartingXI = new OpponentStartingXI(get_opponentName());
    ptrSimulateMatch = new SimulateMatch();

    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "}");

}

DateSelected::~DateSelected() {
    delete ui;
    delete ptrOurStartingXI;
    delete ptrOpponentStartingXI;
    delete ptrSimulateMatch;
}

void DateSelected::fetchMatchData(const QDate &date) {
    // set database
    QSqlDatabase database = QSqlDatabase::database("DB1");

    QSqlQuery query(database);

    // set query
    query.prepare("SELECT * FROM MatchRecord WHERE Date = :Date");
    query.bindValue(":Date", date.toString("dd/MM/yyyy"));

    if (query.exec() && query.next()) {
        // fetch data
        ui -> dateLabel -> setText("Date: " + query.value("Date").toString());
        ui -> timeLabel -> setText("Time: " + query.value("Time").toString());

        opponentName = query.value("OpponentName").toString(); // store opponent name
        qDebug() << opponentName;
        ui -> opponentTeamNameLabel -> setText("Opponent Team Name: " +
                                               query.value("OpponentName").toString());

        ui -> locationLabel -> setText("Location: " + query.value("Location").toString());

        // show View Our + Opponent XI
        ui -> viewOurStartingButton -> show();
        ui -> viewOpponentStartingButton -> show();
    }

    else {
        // Clear the labels if there is no match on the selected date
        ui -> dateLabel -> clear();
        ui -> timeLabel -> clear();
        ui -> opponentTeamNameLabel -> clear();
        ui -> locationLabel -> clear();
        ui -> viewOurStartingButton -> hide();
        ui -> viewOpponentStartingButton -> hide();
        ui -> simulateMatchButton -> hide();
        QMessageBox::information(this, "No Match Founded", "There is no match today");
    }
}

QString DateSelected::get_opponentName() {
    return opponentName;
}

// view Our XI UI
void DateSelected::on_viewOurStartingButton_clicked() {
    ptrOurStartingXI -> setWindowTitle("Our Starting XI");
    ptrOurStartingXI -> show();
}

// view Opponent XI UI
void DateSelected::on_viewOpponentStartingButton_clicked() {
    ptrOpponentStartingXI -> set_opponentName(get_opponentName());
    ptrOpponentStartingXI -> setWindowTitle("Opponent Starting XI");
    ptrOpponentStartingXI -> show();
}

// simulate match UI
void DateSelected::on_simulateMatchButton_clicked() {
    ptrSimulateMatch -> set_opponentName(opponentName);
    qDebug() << ptrSimulateMatch -> get_opponentName();

    // if there are EXACTLY 11 players for each team (EXACTLY 1 GK) -> can simulate match
    if (ptrSimulateMatch -> checkNumPlayers()) {
        ptrSimulateMatch -> simulate();
        ptrSimulateMatch -> show();
    }
}

