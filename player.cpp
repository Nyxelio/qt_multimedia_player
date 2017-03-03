#include "player.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QFileDialog>
#include <QStringList>

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
    QObject::connect(m_chooseFileBtn, &QPushButton::clicked, this, &Player::chooseFile);
}

void Player::chooseFile() {

    QStringList list_filename = QFileDialog::getOpenFileNames(this, "Open multimedia file", QDir::homePath(),
                                                    "Videos files (*.mp4 *.mpg *.gif);; Audio files (*.waw *.mp3 *.flac)");

}
