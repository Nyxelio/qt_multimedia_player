#include "player.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QFileDialog>
#include <QStringList>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>


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
    m_vContainer = new QVBoxLayout(this);
    m_mediaPlayer = new QMediaPlayer(this);
    m_btnContainer = new QHBoxLayout();
    m_startPauseBtn = new PlayPauseButton();
    //m_startPauseBtn = new PlayPauseButton(this);
    //m_startPauseBtn->move(QPoint(0, 400));
    m_stopBtn = new QPushButton("stop");
    m_nextBtn = new QPushButton(">>");
    m_prevBtn = new QPushButton("<<");
    m_chooseFileBtn = new QPushButton("Open files");
    m_reduceBtn = new QPushButton("Reduce window");
    m_exitBtn = new QPushButton("Close Window");
    m_videoPlaylistContainer = new QVBoxLayout();

    m_playlist = new QMediaPlaylist;

    m_videoDisplay = new QVideoWidget();

    m_fullscreenStatus = false;

    // Add playlist component
    //m_mediaPlayer->setPlaylist(m_playlist);

    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setRange(0,0);
    m_durationPosition = new QLabel();
    m_durationEnd = new QLabel("--:--");

   //TODO REMEMBER TO ADD videoWidget
   m_videoPlaylistContainer->addWidget(m_videoDisplay);
   m_videoPlaylistContainer->addWidget(m_slider);

   //output
   m_mediaPlayer->setVideoOutput(m_videoDisplay);

   m_videoDisplay->show();


   m_btnContainer->addWidget(m_startPauseBtn);
   m_btnContainer->addWidget(m_stopBtn);
   m_btnContainer->addWidget(m_prevBtn);
   m_btnContainer->addWidget(m_nextBtn);
   m_btnContainer->addWidget(m_chooseFileBtn);
   m_btnContainer->addWidget(m_exitBtn);
   m_btnContainer->addWidget(m_reduceBtn);


   m_vContainer->addLayout(m_videoPlaylistContainer);
   m_vContainer->addLayout(m_btnContainer);

}

void Player::handle()
{
    connect(m_startPauseBtn.data(), &QPushButton::clicked, this, &Player::playPauseClick);
    connect(m_stopBtn.data(), &QPushButton::clicked, m_mediaPlayer.data(), &QMediaPlayer::stop);
    connect(m_nextBtn.data(), &QPushButton::clicked, this, &Player::nextClick);
    connect(m_prevBtn.data(), &QPushButton::clicked, this, &Player::previousClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::openFileClick);
    connect(m_reduceBtn.data(), &QPushButton::clicked, this, &Player::lower);
    connect(m_exitBtn.data(), &QPushButton::clicked, this, &Player::close);

    connect(m_fullscreenBtn.data(), &QPushButton::clicked, this, &Player::toggleFullscreen);

    connect(m_slider, &QSlider::sliderMoved, this, &Player::setPosition);

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &Player::positionChanged);
    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, &Player::durationChanged);

}
void Player::nextClick()
{
    m_playlist->setCurrentIndex(m_playlist->currentIndex()+1);
}

void Player::previousClick()
{
    m_playlist->setCurrentIndex(m_playlist->currentIndex()-1);
}

void Player::openFileClick()
{
    QStringList list_filename = QFileDialog::getOpenFileNames(this, "Open multimedia file", QDir::homePath(),
                    "Videos files (*.avi *.mp4 *.mpg *.gif, *.ogv);; Audio files (*.waw *.mp3 *.flac, *.ogg)");

    loadPlaylist(list_filename);
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

void Player::loadPlaylist(QStringList list)
{
    foreach (QString str, list) {
        m_playlist->addMedia(QUrl::fromLocalFile(str));
    }
    m_playlist->setCurrentIndex(1);

    m_mediaPlayer->setPlaylist(m_playlist);
}

void Player::durationChanged(int duration)
{
    m_durationEnd = new QLabel("--:--");
    m_slider->setRange(0, duration);
}

void Player::playPauseClick()
{

    if (m_startPauseBtn->isActive) {
        m_mediaPlayer->pause();
    } else {
        m_mediaPlayer->play();
    }
}
