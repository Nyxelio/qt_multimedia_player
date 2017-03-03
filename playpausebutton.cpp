#include "playpausebutton.h"
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtDebug>
#include <QtCore>

PlayPauseButton::PlayPauseButton()
{
    setFixedSize(100, 100);
}

void PlayPauseButton::paintEvent(QPaintEvent *) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(QPointF(width() / 2, height() / 2));

    QPen pen(QColor(200, 200, 200));
    pen.setWidth(5);
    painter.setPen(pen);
    painter.setBrush(QBrush(QColor(255, 0, 0)));

    painter.drawEllipse(QRectF(-40, -40, 80, 80));

    static const QPointF points[3] = {
        QPointF(-15.0, -20.0),
        QPointF(22.0, 0.0),
        QPointF(-15.0, 20.0)
    };

    painter.setBrush(QBrush(QColor(200, 200, 200)));
    painter.drawPolygon(points, 3);

}

void PlayPauseButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 50, 2) + qPow(e->y() - 50, 2)) < 40) {
        insideButton = true;
    }
}

void PlayPauseButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 50, 2) + qPow(e->y() - 50, 2)) < 40)) {
        emit(clicked(true));
    }
    insideButton = false;
}
