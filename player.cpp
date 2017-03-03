#include "player.h"
#include "playpausebutton.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QFileDialog>
#include <QVideoWidget>
#include <QHBoxLayout>

Player::Player(QWidget *parent)
    : QWidget(parent)
{
    init();
    handle();
}


void Player::init()
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(500, 500);
    //m_vContainer = new QVBoxLayout(this);
    //m_mediaPlayer = new QMediaPlayer(this);
    m_btnContainer = new QHBoxLayout(this);
    m_startPauseBtn = new PlayPauseButton(this);
    m_startPauseBtn->move(QPoint(0, 400));
    m_stopBtn = new QPushButton("stop");
    m_nextBtn = new QPushButton();
    m_prevBtn = new QPushButton();
    m_chooseFileBtn = new QPushButton();
    m_reduceBtn = new QPushButton();
    m_exitBtn = new QPushButton();

    m_videoDisplay = new QVideoWidget();

    m_fullscreenStatus = false;

    //TODO REMEMBER TO ADD videoWidget
    //layout->addWidget(m_videoDisplay);

   //output
   //m_mediaPlayer->setVideoOutput(m_videoDisplay);

   //TODO TO SHOW VIDEO
   m_videoDisplay->show();

   //m_btnContainer->addWidget(m_startPauseBtn);
   m_btnContainer->addWidget(m_stopBtn);

}

void Player::handle()
{
    //connect(m_startPauseBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::play);
    //connect(m_stopBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::stop);
    connect(m_nextBtn.data(), &QPushButton::clicked, this, &Player::nextClick);
    connect(m_prevBtn.data(), &QPushButton::clicked, this, &Player::previousClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::openFileClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::chooseFile);
    connect(m_reduceBtn.data(), &QPushButton::clicked, this, &Player::reduceClick);
    connect(m_exitBtn.data(), &QPushButton::clicked, this, &Player::closeClick);

    connect(m_fullscreenBtn.data(), &QPushButton::clicked, this, &Player::toggleFullscreen);
}
void Player::nextClick()
{

}

void Player::previousClick()
{

}

void Player::openFileClick()
{

}

void Player::reduceClick()
{

}

void Player::closeClick()
{

}

Player::~Player()
{
}

void Player::chooseFile() {

//    QString filename = QFileDialog::getSaveFileName(this, "Save file", m_file_opened->fileName(),
//                                                    "Text files (*.txt);; C++ files (*.cpp, *.hpp, *.h)" );

}

void Player::toggleFullscreen() {
    m_fullscreenStatus = !m_fullscreenStatus;
    m_videoDisplay->setFullScreen(m_fullscreenStatus);
}
