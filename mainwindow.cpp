#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    setWindowTitle("Traffic Control System");
    setGeometry(100, 100, 1000, 500);

    scene_ = new TrafficScene(this);
    view_ = new QGraphicsView(scene_, this);

    setCentralWidget(view_);
}

MainWindow::~MainWindow() {
}
