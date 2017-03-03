#include "player.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QFileDialog>
#include <QStringList>
#include <QVideoWidget>
#include <QHBoxLayout>
#include <QSlider>

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
    m_chooseFileBtn = new QPushButton("Open files");
    m_reduceBtn = new QPushButton("Reduce window");
    m_exitBtn = new QPushButton("Close Window");

    m_videoDisplay = new QVideoWidget();

    m_fullscreenStatus = false;

    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setRange(0,0);
    //TODO REMEMBER TO ADD videoWidget
    //layout->addWidget(m_videoDisplay);

   //output
   m_mediaPlayer->setVideoOutput(m_videoDisplay);

   //TODO TO SHOW VIDEO
   m_videoDisplay->show();

   m_btnContainer->addWidget(m_startPauseBtn);
   m_btnContainer->addWidget(m_stopBtn);
   m_btnContainer->addWidget(m_chooseFileBtn);
   m_btnContainer->addWidget(m_exitBtn);
   m_btnContainer->addWidget(m_reduceBtn);

   //TODO REMEMBER TO ADD slider
   m_btnContainer->addWidget(m_slider);

}

void Player::handle()
{
    connect(m_startPauseBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::play);
    connect(m_stopBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::stop);
    connect(m_nextBtn.data(), &QPushButton::clicked, this, &Player::nextClick);
    connect(m_prevBtn.data(), &QPushButton::clicked, this, &Player::previousClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::openFileClick);
    connect(m_reduceBtn.data(), &QPushButton::clicked, this, &Player::lower);
    connect(m_exitBtn.data(), &QPushButton::clicked, this, &Player::close);

    connect(m_fullscreenBtn.data(), &QPushButton::clicked, this, &Player::toggleFullscreen);

    connect(m_slider, &QSlider::sliderMoved, this, &Player::setPosition);
    connect(m_slider, &QSlider::sliderMoved, this, &Player::setPosition);

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &Player::positionChanged);
    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, &Player::durationChanged);

}
void Player::nextClick()
{

}

void Player::previousClick()
{

}

void Player::openFileClick()
{
    QStringList list_filename = QFileDialog::getOpenFileNames(this, "Open multimedia file", QDir::homePath(),
                                                    "Videos files (*.mp4 *.mpg *.gif);; Audio files (*.waw *.mp3 *.flac)");
}

Player::~Player()
{
}

void Player::toggleFullscreen() {
    m_fullscreenStatus = !m_fullscreenStatus;
    m_videoDisplay->setFullScreen(m_fullscreenStatus);
}

void Player::setPosition(int position){
    m_mediaPlayer->setPosition(position);
}

void Player::positionChanged(int position)
{
    m_slider->setValue(position);
}

void Player::durationChanged(int duration)
{
    m_slider->setRange(0, duration);
}
