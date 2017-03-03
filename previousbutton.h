#ifndef PREVIOUSBUTTON_H
#define PREVIOUSBUTTON_H

#include <QPushButton>

class PreviousButton : public QPushButton
{
    Q_OBJECT
public:
    PreviousButton(QWidget *parent = Q_NULLPTR);

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // PREVIOUSBUTTON_H
