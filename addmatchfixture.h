#ifndef ADDMATCHFIXTURE_H
#define ADDMATCHFIXTURE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>

namespace Ui {
class AddMatchFixture;
}

class AddMatchFixture : public QWidget
{
    Q_OBJECT

public:
    explicit AddMatchFixture(QWidget *parent = nullptr);
    ~AddMatchFixture();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::AddMatchFixture *ui;
};

#endif // ADDMATCHFIXTURE_H
