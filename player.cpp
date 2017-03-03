#include "player.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QFileDialog>
#include <QStringList>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QHBoxLayout>
#include <QSlider>
#include <QPainter>
#include <QLabel>
#include <QTime>

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
    m_mediaPlayer = new QMediaPlayer(this);
    m_startPauseBtn = new PlayPauseButton(this);
    m_startPauseBtn->move(QPoint(0, 400));
    m_prevBtn = new PreviousButton(this);
    m_prevBtn->move(QPoint(100, 425));
    m_stopBtn = new StopButton(this);
    m_stopBtn->move(QPoint(150, 425));
    m_nextBtn = new NextButton(this);
    m_nextBtn->move(200, 425);
    m_chooseFileBtn = new OpenFileButton(this);
    m_chooseFileBtn->move(QPoint(250, 425));
    m_reduceBtn = new ReduceButton(this);
    m_reduceBtn->move(QPoint(440, 0));
    m_exitBtn = new CloseButton(this);
    m_exitBtn->move(QPoint(470, 0));

    m_playlist = new QMediaPlaylist;

    m_videoDisplay = new QVideoWidget(this);
    m_videoDisplay->setFixedSize(375, 375);
    m_videoDisplay->move(80, 30);

    m_fullscreenStatus = false;

    // Add playlist component
    m_mediaPlayer->setPlaylist(m_playlist);

    m_slider = new QSlider(this);
    m_slider->setOrientation(Qt::Horizontal);
    m_slider->setFixedSize(275, 25);
    m_slider->move(QPoint(140, 405));
    m_slider->setRange(0,0);
    m_durationPosition = new QLabel(this);
    m_durationPosition->setText("--:--");
    m_durationPosition->setFixedSize(50, 25);
    m_durationPosition->move(QPoint(85, 405));
    m_durationEnd = new QLabel(this);
    m_durationEnd->setText("--:--");
    m_durationEnd->setFixedSize(50, 25);
    m_durationEnd->move(QPoint(435, 405));

   //output
   m_mediaPlayer->setVideoOutput(m_videoDisplay);

   m_videoDisplay->show();
}

void Player::handle()
{
    connect(m_startPauseBtn.data(), &QPushButton::clicked, this, &Player::playPauseClick);
    connect(m_stopBtn.data(), &QPushButton::clicked, this, &Player::stopClick);
    connect(m_nextBtn.data(), &QPushButton::clicked, this, &Player::nextClick);
    connect(m_prevBtn.data(), &QPushButton::clicked, this, &Player::previousClick);
    connect(m_chooseFileBtn.data(), &QPushButton::clicked, this, &Player::openFileClick);
    connect(m_reduceBtn.data(), &QPushButton::clicked, this, &Player::lower);
    connect(m_exitBtn.data(), &QPushButton::clicked, this, &Player::close);

    /*connect(m_fullscreenBtn.data(), &QPushButton::clicked, this, &Player::toggleFullscreen);*/

    connect(m_slider, &QSlider::sliderMoved, this, &Player::setPosition);

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &Player::positionChanged);
    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, &Player::durationChanged);

}
void Player::nextClick()
{
    m_playlist->setCurrentIndex(m_playlist->currentIndex()+1);
}

void Player::stopClick()
{
    m_mediaPlayer->stop();
}

void Player::previousClick()
{
    m_playlist->setCurrentIndex(m_playlist->currentIndex()-1);
}

void Player::openFileClick()
{
    QStringList list_filename = QFileDialog::getOpenFileNames(this, "Open multimedia file", QDir::homePath(),
                                                    tr("&video_files (*.avi *.mp4 *.mpg *.gif);; Audio files (*.waw *.mp3 *.flac)"));
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
    m_durationPosition->setText(QTime::fromMSecsSinceStartOfDay(position).toString("hh:mm:ss"));
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
    m_durationEnd->setText(QTime::fromMSecsSinceStartOfDay(duration).toString("hh:mm:ss"));

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

void Player::paintEvent(QPaintEvent *) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(QColor(255, 255, 255));
    painter.setPen(pen);
    painter.setBrush(QBrush(QColor(255, 255, 255)));

    painter.drawRect(QRect(50, 15, 435, 435));
}
