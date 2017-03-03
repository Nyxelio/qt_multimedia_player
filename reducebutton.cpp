#include "reducebutton.h"
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtCore>

ReduceButton::ReduceButton(QWidget *parent) : QPushButton(parent) {
    setFixedSize(30, 30);
    insideButton = false;
}

void ReduceButton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(QPointF(width() / 2, height() / 2));

    QPen pen(QColor(200, 200, 200));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(QBrush(QColor(0, 0, 255)));

    painter.drawEllipse(QRectF(-10, -10, 20, 20));

    pen.setWidth(1);
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(200, 200, 200)));

    painter.drawRect(QRect(-5, 2, 10, 3));
}

void ReduceButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 15, 2) + qPow(e->y() - 15, 2)) < 10) {
        insideButton = true;
    }
}

void ReduceButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 15, 2) + qPow(e->y() - 15, 2)) < 10)) {
        emit(clicked(true));
        update();
    }
    insideButton = false;
}
