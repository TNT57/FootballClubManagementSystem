#ifndef CHOOSEOPPONENTXI_H
#define CHOOSEOPPONENTXI_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class ChooseOpponentXI;
}

class ChooseOpponentXI : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseOpponentXI(QWidget *parent = nullptr);
    ~ChooseOpponentXI();

    void loadPlayers(QString opponentName);
    void set_opponentName(QString opponentName);

private slots:
    void on_confirmButton_clicked();

private:
    Ui::ChooseOpponentXI *ui;
    QString opponentName = "RealMadrid"; // just init to avoid "Failed to load players"
};

#endif // CHOOSEOPPONENTXI_H
