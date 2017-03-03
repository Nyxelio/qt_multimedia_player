#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <QPushButton>

class CloseButton : public QPushButton
{
    Q_OBJECT
public:
    CloseButton(QWidget *parent = Q_NULLPTR);

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // CLOSEBUTTON_H
