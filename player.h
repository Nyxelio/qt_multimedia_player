#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
};

#endif // PLAYER_H
