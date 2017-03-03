#ifndef PLAYPAUSEBUTTON_H
#define PLAYPAUSEBUTTON_H

#include <QPushButton>

class PlayPauseButton : public QPushButton
{
    Q_OBJECT
public:
    PlayPauseButton();
    PlayPauseButton(QWidget *parent = Q_NULLPTR);
    bool isActive;

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // PLAYPAUSEBUTTON_H
