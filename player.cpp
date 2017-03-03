#include "player.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QFileDialog>
#include <QStringList>
#include <QVideoWidget>
#include <QMediaPlaylist>
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
    m_mediaPlayer = new QMediaPlayer(this);
    m_vContainer = new QVBoxLayout(this);
    m_videoPlaylistContainer = new QHBoxLayout();
    m_btnContainer = new QHBoxLayout();
    m_startPauseBtn = new QPushButton("start");
    m_stopBtn = new QPushButton("stop");
    m_nextBtn = new QPushButton();
    m_prevBtn = new QPushButton();
    m_chooseFileBtn = new QPushButton("Open files");
    m_reduceBtn = new QPushButton();
    m_exitBtn = new QPushButton();

    m_playlist = new QMediaPlaylist;

    m_videoDisplay = new QVideoWidget();

    m_fullscreenStatus = false;

    // Add playlist component
    m_mediaPlayer->setPlaylist(m_playlist);

    //TODO REMEMBER TO ADD videoWidget
    m_videoPlaylistContainer->addWidget(m_videoDisplay);

   //output
   m_mediaPlayer->setVideoOutput(m_videoDisplay);

   //TODO TO SHOW VIDEO
   m_videoDisplay->show();

   m_btnContainer->addWidget(m_startPauseBtn);
   m_btnContainer->addWidget(m_stopBtn);
   m_btnContainer->addWidget(m_chooseFileBtn);


   m_vContainer->addLayout(m_videoPlaylistContainer);
   m_vContainer->addLayout(m_btnContainer);
}

void Player::handle()
{
    connect(m_startPauseBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::play);
    connect(m_stopBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::stop);
    connect(m_nextBtn.data(), &QPushButton::clicked, this, &Player::nextClick);
    connect(m_prevBtn.data(), &QPushButton::clicked, this, &Player::previousClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::openFileClick);
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
    QStringList list_filename = QFileDialog::getOpenFileNames(this, "Open multimedia file", QDir::homePath(),
                                                    "Videos files (*.avi *.mp4 *.mpg *.gif);; Audio files (*.waw *.mp3 *.flac)");
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

void Player::loadPlaylist(QStringList list)
{
    foreach (QString str, list) {
        m_playlist->addMedia(QUrl(str));
        m_playlist->setCurrentIndex(1);
    }
}

void Player::toggleFullscreen() {
    m_fullscreenStatus = !m_fullscreenStatus;
    m_videoDisplay->setFullScreen(m_fullscreenStatus);
}
