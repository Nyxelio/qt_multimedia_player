#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPointer>
#include "playpausebutton.h"
#include "stopbutton.h"
#include "previousbutton.h"
#include "nextbutton.h"
#include "openfilebutton.h"
#include "closebutton.h"
#include "reducebutton.h"
#include "fullscreenbutton.h"

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
    QPointer<FullScreenButton> m_fullscreenBtn;
    QPointer<ReduceButton> m_reduceBtn;
    QPointer<CloseButton> m_exitBtn;
    QPointer<OpenFileButton> m_chooseFileBtn;
    QPointer<PreviousButton> m_prevBtn;
    QPointer<NextButton> m_nextBtn;
    QPointer<StopButton> m_stopBtn;
    QPointer<PlayPauseButton> m_startPauseBtn;
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
    void stopClick();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // PLAYER_H
