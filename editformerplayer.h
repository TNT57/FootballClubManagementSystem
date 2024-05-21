#ifndef EDITFORMERPLAYER_H
#define EDITFORMERPLAYER_H

#include <QWidget>

namespace Ui {
class EditFormerPlayer;
}

class EditFormerPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit EditFormerPlayer(QWidget *parent = nullptr);
    ~EditFormerPlayer();

private:
    Ui::EditFormerPlayer *ui;
};

#endif // EDITFORMERPLAYER_H
