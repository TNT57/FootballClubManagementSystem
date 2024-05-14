#ifndef REMOVEPLAYER_H
#define REMOVEPLAYER_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>



namespace Ui {
class RemovePlayer;
}

class RemovePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit RemovePlayer(QWidget *parent = nullptr);
    ~RemovePlayer();

private slots:
    void on_confirmButton_clicked();

    void on_playerNameComboBox_activated();

private:
    Ui::RemovePlayer *ui;
    void populatePlayers();
};

#endif // REMOVEPLAYER_H
