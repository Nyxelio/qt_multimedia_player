#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H

#include <QPushButton>

class NextButton : public QPushButton
{
    Q_OBJECT
public:
    NextButton(QWidget *parent = Q_NULLPTR);

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // NEXTBUTTON_H
