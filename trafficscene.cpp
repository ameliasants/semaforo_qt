#include "trafficscene.h"
#include <QPainter>
#include <QGraphicsRectItem>


TrafficScene::TrafficScene(QObject *parent)
    : QGraphicsScene(parent), trafficLight_(new TrafficLight()) {

    setSceneRect(0, 0, 800, 400);
    setBackgroundBrush(QBrush(Qt::white));

    drawRoad();
    drawTrafficLight();
    drawPedestrianCrossing();

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &TrafficScene::updateScene);
    timer_->start(50); // Atualiza a cada 50ms
}

void TrafficScene::drawRoad() {

    addRect(0, 100, 800, 100, QPen(), QBrush(Qt::gray)); // sem usar 'road'

    // Desenhar rua cinza
    //QGraphicsRectItem *road = addRect(0, 100, 800, 100, QPen(), QBrush(Qt::gray));

    // Linha branca divisória
    QPen whitePen(Qt::white);
    whitePen.setWidth(2);
    whitePen.setDashPattern({5, 5});
    addLine(0, 150, 800, 150, whitePen);
}

void TrafficScene::drawPedestrianCrossing() {
    // Faixa de pedestre (zebra)
    QPen whitePen(Qt::white);
    whitePen.setWidth(3);

    for (int i = 0; i < 15; i++) {
        addRect(i * 50, 140, 40, 20, whitePen, QBrush(Qt::white));
    }
}

void TrafficScene::drawTrafficLight() {
    // Corpo do semáforo
    QGraphicsRectItem *post = addRect(700, 50, 20, 130, QPen(), QBrush(Qt::black));

    // Luzes do semáforo (inicialmente verde)
    QGraphicsEllipseItem *light = addEllipse(705, 60, 10, 10, QPen(), QBrush(Qt::green));
}
/*
void TrafficScene::addCar(int x, int y) {
   //QGraphicsRectItem *car = addRect(x, y, 40, 30, QPen(), QBrush(Qt::red));
}
*/

void TrafficScene::updateScene() {
    // Atualizar posição dos carros, mudar semáforo, etc.
    update();
}
