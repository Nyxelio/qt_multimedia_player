#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPointer>

class QPushButton;
class QMediaPlayer;

class QVideoWidget;

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
    void init();
    void handle();

private :
    QPointer<QMediaPlayer> m_mediaPlayer;
    QPointer<QPushButton> m_startPauseBtn, m_stopBtn, m_nextBtn, m_prevBtn, m_chooseFileBtn, m_reduceBtn, m_exitBtn;
    QPointer<QVideoWidget> m_videoDisplay;

protected slots:
    void chooseFile();
};

#endif // PLAYER_H
