#include <QPainter>
#include "lines.h"
#include <math.h>
#include <utility>
#include <algorithm>
#include <QMouseEvent>
#include <QDebug>

Lines::Lines(QWidget *parent)
    : QWidget(parent)
{

}

void Lines::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter qp(this);
    //QPen pen(Qt::black, 1, Qt::SolidLine);
    //qp.setPen(pen);
    //qp.drawPoint(50,50);
    drawPic(&qp, x1, y1, x2, y2);
}

void Lines::drawPic(QPainter *qp, double x1, double y1, double x2, double y2) {
    QPen pen(Qt::black, 1, Qt::SolidLine);
    qp->setPen(pen);
    if ((x2 - x1)/(y2 - y1) >= 1300/700) {
        for (int i = 0; i < 1300; ++i) {
            for (int j = 0; j < (y2 - y1) * 1300 / (x2 - x1); ++j) {
                double cur_x = x1 + (x2 - x1) / 1300 * i;
                double cur_y = y1 + (y2 - y1) / ((y2 - y1) * 1300 / (x2 - x1)) * j;
                ComplexNum c(cur_x, cur_y);
                ComplexNum z(0,0);
                bool did = false;
                for (int r_ = 1; r_ <= 255; ++r_) {
                    z = z * z + c;
                    if (z.get_length_quadro() >= 4) {
                        QPen pen(QColor(-r_ + 238,-r_ + 130,-r_ + 238), 1, Qt::SolidLine);
                        qp->setPen(pen);
                        qp->drawLine(i,j,i,j);
                        did = true;
                        break;
                    }
                }
                if (!did) {
                    QPen pen(Qt::black, 1, Qt::SolidLine);
                    qp->setPen(pen);
                    qp->drawLine(i,j,i,j);
                }
            }
        }
    } else {
        for (int i = 0; i < (700 / (y2 - y1) * (x2 - x1)); ++i) {
            for (int j = 0; j < 700; ++j) {
                double cur_x = x1 + (x2 - x1) / (700 / (y2 - y1) * (x2 - x1)) * i;
                double cur_y = y1 + (y2 - y1) / 700 * j;
                ComplexNum c(cur_x, cur_y);
                ComplexNum z(0,0);
                bool did = false;
                for (int r_ = 1; r_ <= 255; ++r_) {
                    z = z * z + c;
                    if (z.get_length_quadro() >= 4) {
                        QPen pen(QColor(-r_ + 238,-r_ + 130,-r_+ 238), 1, Qt::SolidLine);
                        qp->setPen(pen);
                        qp->drawLine(i,j,i,j);
                        did = true;
                        break;
                    }
                }
                if (!did) {
                    QPen pen(Qt::black, 1, Qt::SolidLine);
                    qp->setPen(pen);
                    qp->drawLine(i,j,i,j);
                }
            }
        }
    }
    prev_x1 = x1;
    prev_x2 = x2;
    prev_y1 = y1;
    prev_y2 = y2;
    if ((x2 - x1)/(y2 - y1) >= 1300/700) {
        prev_x = 1300;
        prev_y = (y2 - y1) / (x2 - x1) * 1300;
    } else {
        prev_y = 700;
        prev_x = (x2 - x1) / (y2 - y1) * 700;
    }
}

void Lines::redrow(QMouseEvent *event, bool second) {
    if (!second) {
        pix_x2 = event->x();
        pix_y2 = event->y();
    } else {
        pix_x1 = event->x();
        pix_y1 = event->y();

        x1 = prev_x1 + (prev_x2 - prev_x1) / prev_x * pix_x2;
        x2 = prev_x1 + (prev_x2 - prev_x1) / prev_x * pix_x1;
        y1 = prev_y1 + (prev_y2 - prev_y1) / prev_y * pix_y2;
        y2 = prev_y1 + (prev_y2 - prev_y1) / prev_y * pix_y1;

        if ((x2 - x1)/(y2 - y1) >= 1300/700) {
            resize(1300, (y2 - y1) * 1300 / (x2 - x1));
        } else {
            resize(700 / (y2 - y1) * (x2 - x1), 700);
        }
    }
}

void Lines::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    redrow(event, time);
    time = !time;
}
