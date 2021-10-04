#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <cmath>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

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
    ~ComplexNum();
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
private:
    double a_, b_;
};
