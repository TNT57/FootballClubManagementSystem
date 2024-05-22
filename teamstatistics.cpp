#include "teamstatistics.h"
#include "ui_teamstatistics.h"

//Constructor
TeamStatistics::TeamStatistics(QWidget *parent): QWidget(parent), ui(new Ui::TeamStatistics) {
    ui -> setupUi(this);
    loadPlayerStats();

    //Change background image to blurred
    QPixmap backgroundLabel("E:\\Workspace\\FootballClubManagementSystem\\images\\imageBlur.png");
    int w = ui -> backgroundLabel -> width();
    int h = ui -> backgroundLabel -> height();

    ui -> backgroundLabel -> setPixmap(backgroundLabel.scaled(w,h,Qt::KeepAspectRatioByExpanding)); //make image wider but keep the same ratio

    //Change words color to white
    ui -> label -> setStyleSheet("QLabel {"
                                 "color: white;"
                                 "}");

    ui -> label_2 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    ui -> label_3 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    ui -> label_4 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    ui -> label_5 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    ui -> label_6 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    ui -> label_7 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    ui -> label_8 -> setStyleSheet("QLabel {"
                                   "color: white;"
                                   "}");

    ui -> btnReload -> setStyleSheet("QPushButton {"
                                     "color: white;"
                                     "}");

    // Set the tooltip for the label
    ui -> infoLabel -> setToolTip("Click reload to see the most updated statistic of the team!");

    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "}");
}

//Create destructor
TeamStatistics::~TeamStatistics() {
    qDebug() << "~RemovePlayer";
    delete ui;
}

//int teamNumGoals, teamNumAssists, teamNumYellowCards, teamNumRedCards;
//float teamAVGPass, teamAVGTackle, teamAVGDribble;

void TeamStatistics::loadPlayerStats() {
    // set database
    QSqlDatabase db = QSqlDatabase::database("DB1");

    // Check if the database is open
    if (!db.isOpen()) {
        qDebug() << "Error: connection with database failed:" << db.lastError().text();
        return;
    }

    else {
        qDebug() << "Database: connection ok";
    }

    // Insert value for Goals box
    QSqlQuery query(db);

    // Process the results of your query here
    query.prepare("SELECT Goals FROM Player");
    int teamNumGoals = 0; // Initialize the team goals counter

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumGoals += query.value(0).toInt(); // Sum up the goals
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    ui -> goalLabel -> setText(QString::number(teamNumGoals)); //set the text of the goalLabel widget with the total number of goals.

    //Insert value for Assists box
    query.prepare("SELECT Assists FROM Player");
    int teamNumAssists = 0; //initialize variable

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumAssists += query.value(0).toInt(); // Sum up the goals
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    ui -> assistLabel -> setText(QString::number(teamNumAssists)); //set the text of the assistLabel widget with the total number of assists.

    //Insert value for YellowCard box
    query.prepare("SELECT YellowCard FROM Player");
    int teamNumYellowCards = 0; //initialize variable

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumYellowCards += query.value(0).toInt(); // Sum up the number of cards
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    ui -> yellowLabel -> setText(QString::number(teamNumYellowCards)); //set the text of the yellowCardLabel

    //Insert value for YellowCard box
    query.prepare("SELECT RedCard FROM Player");
    int teamNumRedCards = 0; //initialize variable

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumRedCards += query.value(0).toInt(); // Sum up the number of cards
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    ui -> redLabel -> setText(QString::number(teamNumRedCards)); //set the text of the yellowCardLabel

    //Find the amount of players
    query.prepare("SELECT COUNT(Goals) FROM Player");
    int playerAmount = 0; //initialize variable

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            playerAmount = query.value(0).toInt();
            qDebug() << "Amount of player: " << playerAmount;
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    //Insert value for PassCmpPer90 box
    query.prepare("SELECT PassCmpPer90 FROM Player");

    float teamAVGPass = 0.0; //initialize variable
    float teamAVGPassResult = 0.0; //initialize variable

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamAVGPass += query.value(0).toInt(); // Sum up the percentage of pass
            teamAVGPassResult = teamAVGPass/playerAmount;
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    QString formattedPassResult = QString::number(teamAVGPassResult, 'f', 2);
    ui -> passLabel -> setText(formattedPassResult); //set the text of the passLabel

    //Insert value for TacklePer90 box
    query.prepare("SELECT TacklePer90 FROM Player");
    float teamAVGTackle = 0.0; //initialize variable
    float teamAVGTackleResult = 0.0; //initialize variable

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamAVGTackle += query.value(0).toInt(); // Sum up the percentage of pass
            teamAVGTackleResult = teamAVGTackle/playerAmount;
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    // Limit the result to two decimal places
    QString formattedTackleResult = QString::number(teamAVGTackleResult, 'f', 2); //round the value to 2 numbers behind decimal point
    ui -> tackleLabel -> setText(formattedTackleResult); // Set the text of the tackleLabel

    //Insert value for DribblePer90 box
    query.prepare("SELECT DribblePer90 FROM Player");
    float teamAVGDribble = 0.0;
    float teamAVGDribbleResult = 0.0;

    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamAVGDribble += query.value(0).toInt(); // Sum up the percentage of pass
            teamAVGDribbleResult = teamAVGDribble/playerAmount;
        }
    }

    else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }

    QString formattedDribbleResult = QString::number(teamAVGDribbleResult, 'f', 2);
    ui -> dribbleLabel -> setText(formattedDribbleResult); //set the text of the dribbleLabel
}

void TeamStatistics::on_btnReload_clicked() {
    loadPlayerStats();  //load the data again using sql
}
