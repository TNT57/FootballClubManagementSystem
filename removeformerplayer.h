#ifndef REMOVEFORMERPLAYER_H
#define REMOVEFORMERPLAYER_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class RemoveFormerPlayer;
}

class RemoveFormerPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveFormerPlayer(QWidget *parent = nullptr);
    void populateFormerPlayers();
    ~RemoveFormerPlayer();

private slots:
    void on_confirmButton_clicked();
    void on_playerNameComboBox_activated();

private:
    Ui::RemoveFormerPlayer *ui;
};

#endif // REMOVEFORMERPLAYER_H
