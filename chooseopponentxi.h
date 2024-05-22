#ifndef CHOOSEOPPONENTXI_H
#define CHOOSEOPPONENTXI_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
    class ChooseOpponentXI;
}

class ChooseOpponentXI: public QWidget {
    Q_OBJECT

public:
    explicit ChooseOpponentXI(QWidget *parent = nullptr); // constructor
    ~ChooseOpponentXI(); // destructor
    void loadPlayers(QString opponentName); // load opponent players to the UI
    void set_opponentName(QString opponentName); // setter for opponent name

private slots:
    void on_confirmButton_clicked(); // confirm choosing opponent XI

private:
    Ui::ChooseOpponentXI *ui; // pointer to the UI
    QString opponentName = "RealMadrid"; // just init to avoid "Failed to load players"
};

#endif // CHOOSEOPPONENTXI_H
