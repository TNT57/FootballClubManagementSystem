#ifndef EDITMATCHFIXTURE_H
#define EDITMATCHFIXTURE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class EditMatchFixture;
}

class EditMatchFixture : public QWidget
{
    Q_OBJECT

public:
    explicit EditMatchFixture(QWidget *parent = nullptr);
    void populateDate();
    void populateOpponentName();
    ~EditMatchFixture();

private slots:
    void on_confirmButton_clicked();

    void on_matchDayComboBox_currentTextChanged(const QString &date);

private:
    Ui::EditMatchFixture *ui;
};

#endif // EDITMATCHFIXTURE_H
