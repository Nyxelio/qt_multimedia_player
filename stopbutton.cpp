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

    QRadialGradient radialGradient(QPointF(0, 0), 60);
    radialGradient.setColorAt(0, QColor(55,121,251));
    radialGradient.setColorAt(1, QColor(189,224,254));

    QPen pen(QColor(200, 200, 200));
    pen.setWidth(5);
    painter.setPen(pen);
    painter.setBrush(radialGradient);

    painter.drawEllipse(QRectF(-20, -20, 40, 40));

    pen.setWidth(1);
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(200, 200, 200)));

    painter.drawRect(QRect(-8, -8, 16, 16));
}

void StopButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 25, 2) + qPow(e->y() - 25, 2)) < 20) {
        insideButton = true;
    }
}

void StopButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 25, 2) + qPow(e->y() - 25, 2)) < 20)) {
        emit(clicked(true));
        update();
    }
    insideButton = false;
}
