#ifndef ADDFORMERPLAYER_H
#define ADDFORMERPLAYER_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class AddFormerPlayer;
}

class AddFormerPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit AddFormerPlayer(QWidget *parent = nullptr);
    void populateFormerPlayers();
    ~AddFormerPlayer();

private slots:
    void on_confirmButton_clicked();
    void on_playerNameComboBox_activated();

private:
    Ui::AddFormerPlayer *ui;
};

#endif // ADDFORMERPLAYER_H
