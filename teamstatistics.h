#ifndef TEAMSTATISTICS_H
#define TEAMSTATISTICS_H

#include <QWidget>

namespace Ui {
class TeamStatistics;
}

class TeamStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit TeamStatistics(QWidget *parent = nullptr);
    ~TeamStatistics();

private:
    Ui::TeamStatistics *ui;
};

#endif // TEAMSTATISTICS_H
