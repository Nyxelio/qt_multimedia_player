#ifndef STOPBUTTON_H
#define STOPBUTTON_H

#include <QPushButton>

class StopButton : public QPushButton
{
    Q_OBJECT
public:
    StopButton(QWidget *parent = Q_NULLPTR);

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // STOPBUTTON_H
