#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPointer>
<<<<<<< HEAD
#include <QMediaPlayer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
=======

class QPushButton;
class QMediaPlayer;
>>>>>>> 5a725054572587ec3f4ecd4a2685702a16921f87

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

<<<<<<< HEAD
private slots:
    void nextClick();
    void previousClick();
    void openFileClick();
    void reduceClick();
    void closeClick();
=======
protected slots:
    void chooseFile();
>>>>>>> 5a725054572587ec3f4ecd4a2685702a16921f87
};

#endif // PLAYER_H
