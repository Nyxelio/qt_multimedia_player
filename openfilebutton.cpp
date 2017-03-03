#include "openfilebutton.h"
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtCore>

OpenFileButton::OpenFileButton(QWidget *parent) : QPushButton(parent) {
    setFixedSize(50, 50);
    insideButton = false;
}

void OpenFileButton::paintEvent(QPaintEvent *) {

    static const QPointF pointsForOpenFile[3] = {
        QPointF(0.0, -12.0),
        QPointF(10.0, -2.0),
        QPointF(-10.0, -2.0)
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

    painter.drawEllipse(QRectF(-20, -20, 40, 40));

    pen.setWidth(1);
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(200, 200, 200)));

    painter.drawPolygon(pointsForOpenFile, 3);
    painter.drawRect(QRect(-10.0, 2.0, 20.0, 8.0));
}

void OpenFileButton::mousePressEvent(QMouseEvent *e) {
    if (qSqrt(qPow(e->x() - 25, 2) + qPow(e->y() - 25, 2)) < 20) {
        insideButton = true;
    }
}

void OpenFileButton::mouseReleaseEvent(QMouseEvent *e) {
    if (insideButton && (qSqrt(qPow(e->x() - 25, 2) + qPow(e->y() - 25, 2)) < 20)) {
        emit(clicked(true));
        update();
    }
    insideButton = false;
}
