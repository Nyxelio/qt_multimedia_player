#include "player.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QFileDialog>

#include <QVideoWidget>

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

    m_videoDisplay = new QVideoWidget();


    //TODO REMEMBER TO ADD videoWidget
    //layout->addWidget(m_videoDisplay);

   //output
   m_mediaPlayer->setVideoOutput(m_videoDisplay);

   //TODO TO SHOW VIDEO
   m_videoDisplay->show();

}

void Player::handle()
{
    QObject::connect(m_chooseFileBtn, &QPushButton::clicked, this, &Player::chooseFile);
}

void Player::chooseFile() {

//    QString filename = QFileDialog::getSaveFileName(this, "Save file", m_file_opened->fileName(),
//                                                    "Text files (*.txt);; C++ files (*.cpp, *.hpp, *.h)" );

//    QString filename = QFileDialog::getOpenFileName(this, tr("Open multimedia file", "/home", tr("")))
}
