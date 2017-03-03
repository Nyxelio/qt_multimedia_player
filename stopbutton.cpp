#include "stopbutton.h"
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtCore>

StopButton::StopButton(QWidget *parent) : QPushButton(parent) {
    setFixedSize(50, 50);
    insideButton = false;
}

void StopButton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(QPointF(width() / 2, height() / 2));

    QPen pen(QColor(200, 200, 200));
    pen.setWidth(5);
    painter.setPen(pen);
    painter.setBrush(QBrush(QColor(0, 0, 255)));

    painter.drawEllipse(QRectF(-20, -20, 40, 40));

    pen.setWidth(1);
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(200, 200, 200)));

    painter.drawRect(QRect(-8, -8, 16, 16));
}

void StopButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 50, 2) + qPow(e->y() - 50, 2)) < 20) {
        insideButton = true;
    }
}

void StopButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 50, 2) + qPow(e->y() - 50, 2)) < 20)) {
        emit(clicked(true));
        update();
    }
    insideButton = false;
}
