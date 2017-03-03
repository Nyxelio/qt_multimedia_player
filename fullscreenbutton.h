#ifndef FULLSCREENBUTTON_H
#define FULLSCREENBUTTON_H

#include <QPushButton>

class FullScreenButton : public QPushButton
{
    Q_OBJECT
public:
    FullScreenButton(QWidget *parent = Q_NULLPTR);

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // FULLSCREENBUTTON_H
