#include "player.h"
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
//    setAttribute(Qt::WA_TranslucentBackground);
//    setWindowFlags(Qt::FramelessWindowHint);
    //m_vContainer = new QVBoxLayout(this);
    m_mediaPlayer = new QMediaPlayer(this);
    m_btnContainer = new QHBoxLayout(this);
    m_startPauseBtn = new QPushButton("start");
    m_stopBtn = new QPushButton("stop");
    m_nextBtn = new QPushButton();
    m_prevBtn = new QPushButton();
    m_chooseFileBtn = new QPushButton();
    m_reduceBtn = new QPushButton();
    m_exitBtn = new QPushButton();

    m_videoDisplay = new QVideoWidget();


    //TODO REMEMBER TO ADD videoWidget
    //layout->addWidget(m_videoDisplay);

   //output
   m_mediaPlayer->setVideoOutput(m_videoDisplay);

   //TODO TO SHOW VIDEO
   m_videoDisplay->show();

   m_btnContainer->addWidget(m_startPauseBtn);
   m_btnContainer->addWidget(m_stopBtn);

}

void Player::handle()
{
    connect(m_startPauseBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::play);
    connect(m_stopBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::stop);
    connect(m_nextBtn.data(), &QPushButton::clicked, this, &Player::nextClick);
    connect(m_prevBtn.data(), &QPushButton::clicked, this, &Player::previousClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::openFileClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::chooseFile);
    connect(m_reduceBtn.data(), &QPushButton::clicked, this, &Player::reduceClick);
    connect(m_exitBtn.data(), &QPushButton::clicked, this, &Player::closeClick);

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
    QObject::connect(m_chooseFileBtn, &QPushButton::clicked, this, &Player::chooseFile);
}

void Player::chooseFile() {

//    QString filename = QFileDialog::getSaveFileName(this, "Save file", m_file_opened->fileName(),
//                                                    "Text files (*.txt);; C++ files (*.cpp, *.hpp, *.h)" );

}
