#ifndef REDUCEBUTTON_H
#define REDUCEBUTTON_H

#include <QPushButton>

class ReduceButton : public QPushButton
{
    Q_OBJECT
public:
    ReduceButton(QWidget *parent = Q_NULLPTR);

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // REDUCEBUTTON_H
