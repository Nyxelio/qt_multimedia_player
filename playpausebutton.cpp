#include "playpausebutton.h"
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtCore>
#include <QPalette>
#include <QRadialGradient>

PlayPauseButton::PlayPauseButton(QWidget *parent) : QPushButton(parent) {
    setFixedSize(100, 100);
    isActive = false;
    insideButton = false;
}

void PlayPauseButton::paintEvent(QPaintEvent *) {

    static const QPointF pointsForPlay[3] = {
        QPointF(-15.0, -20.0),
        QPointF(22.0, 0.0),
        QPointF(-15.0, 20.0)
    };

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

    painter.drawEllipse(QRectF(-40, -40, 80, 80));

    painter.setBrush(QBrush(QColor(200, 200, 200)));

    pen.setWidth(1);
    painter.setPen(pen);

    if (!isActive) {
        painter.drawPolygon(pointsForPlay, 3);
    } else {
        painter.drawRect(QRect(-15, -20, 10, 40));
        painter.drawRect(QRect(5, -20, 10, 40));
    }
}

void PlayPauseButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 50, 2) + qPow(e->y() - 50, 2)) < 40) {
        insideButton = true;
    }
}

void PlayPauseButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 50, 2) + qPow(e->y() - 50, 2)) < 40)) {
        emit(clicked(true));
        isActive = !isActive;

        update();
    }
    insideButton = false;
}
