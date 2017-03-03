#ifndef OPENFILEBUTTON_H
#define OPENFILEBUTTON_H

#include <QPushButton>

class OpenFileButton : public QPushButton
{
    Q_OBJECT
public:
    OpenFileButton(QWidget *parent = Q_NULLPTR);

private:
    bool insideButton;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent * e) override;
};

#endif // OPENFILEBUTTON_H
