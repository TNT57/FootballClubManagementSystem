#ifndef ADDPLAYER_H
#define ADDPLAYER_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class AddPlayer;
}

class AddPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit AddPlayer(QWidget *parent = nullptr);
    bool validateInput();
    friend class TestAddPlayer;
    ~AddPlayer();

private slots:
    void on_confirmButton_clicked();

    void on_positionComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::AddPlayer *ui;
};

#endif // ADDPLAYER_H
