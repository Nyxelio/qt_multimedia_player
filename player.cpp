#include "player.h"

Player::Player(QWidget *parent)
    : QWidget(parent)
{
    init();
    handle();
}

Player::~Player()
{

}

void Player::init()
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
}

void Player::handle()
{

}
