#include "closebutton.h"
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtCore>

CloseButton::CloseButton(QWidget *parent) : QPushButton(parent) {
    setFixedSize(30, 30);
    insideButton = false;
}

void CloseButton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(QPointF(width() / 2, height() / 2));

    QPen pen(QColor(200, 200, 200));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(QBrush(QColor(255, 0, 0)));

    static const QPointF pointsForCloseOne[4] = {
        QPointF(-5.0, -2.5),
        QPointF(-2.5, -5.0),
        QPointF(5.0, 2.5),
        QPointF(2.5, 5.0)
    };

    static const QPointF pointsForCloseTwo[4] = {
        QPointF(2.5, -5.0),
        QPointF(5.0, -2.5),
        QPointF(-2.5, 5.0),
        QPointF(-5.0, 2.5)
    };

    painter.drawEllipse(QRectF(-10, -10, 20, 20));

    painter.setBrush(QBrush(QColor(200, 200, 200)));

    pen.setWidth(1);
    painter.setPen(pen);

    painter.drawPolygon(pointsForCloseOne, 4);
    painter.drawPolygon(pointsForCloseTwo, 4);
}

void CloseButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 15, 2) + qPow(e->y() - 15, 2)) < 10) {
        insideButton = true;
    }
}

void CloseButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 15, 2) + qPow(e->y() - 15, 2)) < 10)) {
        emit(clicked(true));
        update();
    }
    insideButton = false;
}
