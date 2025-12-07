#include "trafficscene.h"
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

TrafficScene::TrafficScene(QObject *parent)
    : QGraphicsScene(parent),
    trafficLightModel_(TrafficLightState::GREEN),
    carModel_(0.0, 120.0, 2.0),
    carItem_(nullptr),
    postItem_(nullptr),
    lightItem_(nullptr),
    elapsedMs_(0)
{
    setSceneRect(0, 0, 800, 400);
    setBackgroundBrush(QBrush(Qt::white));

    drawRoad();
    drawPedestrianCrossing();
    drawTrafficLight();
    addCar(static_cast<int>(carModel_.x()), static_cast<int>(carModel_.y()));

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &TrafficScene::updateScene);
    timer_->start(50); // Atualiza a cada 50ms
}

void TrafficScene::drawRoad() {
    // Rua cinza
    addRect(0, 100, 800, 100, QPen(), QBrush(Qt::gray));

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

    for (int i = 0; i < 15; ++i) {
        addRect(i * 50, 140, 40, 20, whitePen, QBrush(Qt::white));
    }
}

void TrafficScene::drawTrafficLight() {
    // Corpo do semáforo
    postItem_ = addRect(700, 50, 20, 130, QPen(), QBrush(Qt::black));

    // Luz do semáforo (inicialmente verde)
    lightItem_ = addEllipse(705, 60, 10, 10, QPen(), QBrush(Qt::green));
}

void TrafficScene::addCar(int x, int y) {
    carItem_ = addRect(x, y, 40, 30, QPen(), QBrush(Qt::red));
}

void TrafficScene::updateTrafficLightColor() {
    if (!lightItem_) return;

    switch (trafficLightModel_.getState()) {
    case TrafficLightState::GREEN:
        lightItem_->setBrush(Qt::green);
        break;
    case TrafficLightState::YELLOW:
        lightItem_->setBrush(Qt::yellow);
        break;
    case TrafficLightState::RED:
        lightItem_->setBrush(Qt::red);
        break;
    }
}

void TrafficScene::updateScene() {
    // 1) Atualizar tempo acumulado
    elapsedMs_ += 50; // mesmo valor do timer

    static bool alreadyPassed = false;

    // 2) Definir ciclo do semáforo: 4s verde, 1s amarelo, 4s vermelho
    int cycleMs = 9000;          // 4 + 1 + 4 segundos
    int t = elapsedMs_ % cycleMs;

    TrafficLightState newState;
    if (t < 4000) {              // 0–3999 ms
        newState = TrafficLightState::GREEN;
    } else if (t < 5000) {       // 4000–4999 ms
        newState = TrafficLightState::YELLOW;
    } else {                     // 5000–8999 ms
        newState = TrafficLightState::RED;
    }

    if (newState != trafficLightModel_.getState()) {
        trafficLightModel_.setState(newState);
        updateTrafficLightColor();
    }

    // 3) Atualizar posição do carro respeitando o semáforo
    double stopX = 620.0;              // ajuste fino depois visualmente
    double carCenterX = carModel_.x() + 20.0; // centro do carro (largura 40)

    bool mustStop =
        (trafficLightModel_.getState() == TrafficLightState::RED ||
         trafficLightModel_.getState() == TrafficLightState::YELLOW) &&
        (carCenterX >= stopX);

    if (!mustStop) {
        carModel_.updatePosition();
    }

    if (carItem_) {
        carItem_->setX(carModel_.x());
    }

    update();
}
