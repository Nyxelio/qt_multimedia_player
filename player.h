#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPointer>
#include "playpausebutton.h"

class QPushButton;
class QMediaPlayer;
class QMediaPlaylist;
class QStringList;
class QVideoWidget;
class QVBoxLayout;
class QHBoxLayout;
class QSlider;
class QLabel;

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
    void init();
    void handle();
    void loadPlaylist(QStringList);

private :
    QPointer<QVBoxLayout> m_vContainer, m_videoPlaylistContainer;
    QPointer<QHBoxLayout> m_btnContainer;
    QPointer<QMediaPlayer> m_mediaPlayer;
    QPointer<QMediaPlaylist> m_playlist;
    QPointer<QPushButton> m_stopBtn, m_nextBtn, m_prevBtn, m_chooseFileBtn, m_reduceBtn, m_exitBtn;
    QPointer<PlayPauseButton> m_startPauseBtn;
    QPointer<QPushButton> m_fullscreenBtn;
    QPointer<QVideoWidget> m_videoDisplay;

    QPointer<QSlider> m_slider;
    bool m_fullscreenStatus;
    QPointer<QLabel> m_durationPosition;
    QPointer<QLabel> m_durationEnd;

private slots:
    void nextClick();
    void previousClick();
    void openFileClick();
    void toggleFullscreen();
    void positionChanged(int position);
    void durationChanged(int duration);
    void setPosition(int position);
    void playPauseClick();
};

#endif // PLAYER_H
