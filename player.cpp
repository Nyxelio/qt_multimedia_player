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
#include <QApplication>
#include <QDesktopWidget>

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
    m_fullscreenBtn = new FullScreenButton(this);
    m_fullscreenBtn->move(QPoint(410, 0));

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

    connect(m_fullscreenBtn, &QPushButton::clicked, this, &Player::toggleFullscreen);

    connect(m_slider, &QSlider::sliderMoved, this, &Player::setPosition);

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &Player::positionChanged);
    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, &Player::durationChanged);

}
void Player::nextClick()
{
    m_playlist->setCurrentIndex(m_playlist->currentIndex()+1);
    m_mediaPlayer->play();
}

void Player::stopClick()
{
    m_mediaPlayer->stop();
    m_startPauseBtn->isActive = false;
    m_startPauseBtn->update();
}

void Player::previousClick()
{
    int cpt = m_playlist->mediaCount();
    if (m_playlist->currentIndex() != 0) {
        m_playlist->setCurrentIndex(m_playlist->currentIndex()-1);
    } else {
        m_playlist->setCurrentIndex(cpt - 1);
    }
    m_mediaPlayer->play();
}

void Player::openFileClick()
{
    QStringList list_filename = QFileDialog::getOpenFileNames(this, "Open multimedia file", QDir::homePath(),
                                                    tr("Video files (*.avi *.mp4 *.mpg *.gif, *.ogv);; Audio files (*.waw *.mp3 *.flac)"));
    loadPlaylist(list_filename);
}

Player::~Player()
{
}

void Player::toggleFullscreen() {
    m_fullscreenStatus = !m_fullscreenStatus;
    if (m_fullscreenStatus) {
        this->move(0, 0);
        QRect rec = QApplication::desktop()->screenGeometry();
        int height = rec.height();
        int width = rec.width();
        setFixedSize(width, height);
        m_startPauseBtn->move(QPoint(0, height - 130));
        m_prevBtn->move(QPoint(100, height - 105));
        m_stopBtn->move(QPoint(150, height - 105));
        m_nextBtn->move(200, height - 105);
        m_chooseFileBtn->move(QPoint(250, height - 105));
        m_reduceBtn->move(QPoint(width - 60, 0));
        m_exitBtn->move(QPoint(width - 30, 0));
        m_fullscreenBtn->move(QPoint(width - 90, 0));
        m_videoDisplay->setFixedSize(width - 125, height - 165);
        m_videoDisplay->move(80, 30);
        m_slider->setFixedSize(width - 225, 25);
        m_slider->move(QPoint(140, height - 135));
        m_durationPosition->setFixedSize(50, 25);
        m_durationPosition->move(QPoint(85, height - 135));
        m_durationEnd->setFixedSize(50, 25);
        m_durationEnd->move(QPoint(width - 65, height - 135));
    } else {
        setFixedSize(500, 500);
        m_startPauseBtn->move(QPoint(0, 400));
        m_prevBtn->move(QPoint(100, 425));
        m_stopBtn->move(QPoint(150, 425));
        m_nextBtn->move(200, 425);
        m_chooseFileBtn->move(QPoint(250, 425));
        m_reduceBtn->move(QPoint(440, 0));
        m_exitBtn->move(QPoint(470, 0));
        m_fullscreenBtn->move(QPoint(410, 0));
        m_videoDisplay->setFixedSize(375, 375);
        m_videoDisplay->move(80, 30);
        m_slider->setFixedSize(275, 25);
        m_slider->move(QPoint(140, 405));
        m_durationPosition->setFixedSize(50, 25);
        m_durationPosition->move(QPoint(85, 405));
        m_durationEnd->setFixedSize(50, 25);
        m_durationEnd->move(QPoint(435, 405));
    }
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
    m_playlist->clear();

    foreach (QString str, list) {
        m_playlist->addMedia(QUrl::fromLocalFile(str));
    }
    m_playlist->setCurrentIndex(1);

    m_mediaPlayer->setPlaylist(m_playlist);

    if (list.count() > 0) {
        m_startPauseBtn->isActive = false;
        m_startPauseBtn->update();
    }
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

    QPen pen(QColor(79, 82, 94));
    painter.setPen(pen);
    painter.setBrush(QBrush(QColor(79, 82, 94)));


    if (m_fullscreenStatus) {
        QRect rec = QApplication::desktop()->screenGeometry();
        int height = rec.height();
        int width = rec.width();
        painter.drawRect(QRect(50, 15, width - 65, height - 95));
    } else {
        painter.drawRect(QRect(50, 15, 435, 435));
    }
}
