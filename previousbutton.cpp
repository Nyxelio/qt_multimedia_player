#include "previousbutton.h"
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtCore>

PreviousButton::PreviousButton(QWidget *parent) : QPushButton(parent) {
    setFixedSize(50, 50);
    insideButton = false;
}

void PreviousButton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(QPointF(width() / 2, height() / 2));

    QRadialGradient radialGradient(QPointF(0, 0), 60);
    radialGradient.setColorAt(0, QColor(55,121,251));
    radialGradient.setColorAt(1, QColor(189,224,254));

    QPen pen(QColor(200, 200, 200));
    pen.setWidth(5);
    painter.setPen(pen);
    painter.setBrush(radialGradient);

    static const QPointF pointsForPrevOne[3] = {
        QPointF(9.5, -10.0),
        QPointF(-5.5, 0.0),
        QPointF(9.5, 10.0)
    };

    static const QPointF pointsForPrevTwo[3] = {
        QPointF(2.0, -10.0),
        QPointF(-13.0, 0.0),
        QPointF(2.0, 10.0)
    };

    painter.drawEllipse(QRectF(-20, -20, 40, 40));

    pen.setWidth(1);
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(200, 200, 200)));

    painter.drawPolygon(pointsForPrevOne, 3);
    painter.drawPolygon(pointsForPrevTwo, 3);
}

void PreviousButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 25, 2) + qPow(e->y() - 25, 2)) < 20) {
        insideButton = true;
    }
}

void PreviousButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 25, 2) + qPow(e->y() - 25, 2)) < 20)) {
        emit(clicked(true));
        update();
    }
    insideButton = false;
}
