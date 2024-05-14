#ifndef EDITPLAYER_H
#define EDITPLAYER_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class EditPlayer;
}

class EditPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit EditPlayer(QWidget *parent = nullptr);
    void loadPlayer();
    void loadPlayerPosition();
    bool validateInput();
    ~EditPlayer();

private slots:
    void on_shirtNumberComboBox_currentTextChanged(const QString &shirtNumber);

    void on_confirmButton_clicked();

    void on_positionComboBox_currentTextChanged(const QString &position);

private:
    Ui::EditPlayer *ui;
};

#endif // EDITPLAYER_H
