#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPointer>

class QPushButton;
class QMediaPlayer;
class QVideoWidget;
class QVBoxLayout;
class QHBoxLayout;

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
    void init();
    void handle();

private :
    QPointer<QVBoxLayout> m_vContainer;
    QPointer<QHBoxLayout> m_btnContainer;
    QPointer<QMediaPlayer> m_mediaPlayer;
    QPointer<QPushButton> m_startPauseBtn, m_stopBtn, m_nextBtn, m_prevBtn, m_chooseFileBtn, m_reduceBtn, m_exitBtn;
    QPointer<QVideoWidget> m_videoDisplay;

private slots:
    void nextClick();
    void previousClick();
    void openFileClick();
    void reduceClick();
    void closeClick();

protected slots:
    void chooseFile();
};

#endif // PLAYER_H
