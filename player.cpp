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
//    setAttribute(Qt::WA_TranslucentBackground);
//    setWindowFlags(Qt::FramelessWindowHint);
    m_mediaPlayer = new QMediaPlayer;
    m_startPauseBtn = new QPushButton();
    m_stopBtn = new QPushButton();
    m_nextBtn = new QPushButton();
    m_prevBtn = new QPushButton();
    m_chooseFileBtn = new QPushButton();
    m_reduceBtn = new QPushButton();
    m_exitBtn = new QPushButton();




}

void Player::handle()
{

}
