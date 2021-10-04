#ifndef LINES_H
#define LINES_H

#pragma once

#include <QWidget>

class Lines : public QWidget {

  public:
    Lines(QWidget *parent = 0);
    bool draw = true;
    double x2 = 1.5 / 700 * 1300, y2 = 1.5, x1 = -1.5 / 700 * 1300, y1 = -1.5;
    double prev_x2 = 1.5 / 700 * 1300, prev_y2 = 1.5, prev_x1 = -1.5 / 700 * 1300, prev_y1 = -1.5;
    int pix_x1 = 0, pix_y1 = 0, pix_x2 = 1300, pix_y2 = 700;
    int prev_x = 1300, prev_y = 700;
    bool time = false;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void redrow(QMouseEvent *event, bool second);
    void drawPic(QPainter *qp, double x1, double y1, double x2, double y2);
};

class ComplexNum {
public:
    ComplexNum() {
        a_ = 0;
        b_ = 0;
    }
    ComplexNum(double a, double b) {
        a_ = a;
        b_ = b;
    }
    ~ComplexNum() {

    };
    double get_a(){
        return a_;
    }
    double get_b() {
        return b_;
    }
    void set_a(double a){
        a_ = a;
    }
    void set_b(double b) {
        b_ = b;
    }
    double get_length_quadro() {
        return a_ * a_ + b_ * b_;
    }
    ComplexNum operator+(const ComplexNum &Complex) {
        ComplexNum z(a_ + Complex.a_, b_ + Complex.b_);
        return z;
    };
    ComplexNum operator*(const ComplexNum &Complex) {
        ComplexNum z(a_ * Complex.a_ - b_ * Complex.b_, a_ * Complex.b_ + b_ * Complex.a_);
        return z;
    };
private:
    double a_, b_;
};


#endif // LINES_H
