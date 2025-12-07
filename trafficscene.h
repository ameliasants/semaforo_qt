#ifndef TRAFFICSCENE_H
#define TRAFFICSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPen>
#include <QBrush>
#include "traffic_light.h"
#include "car.h"

class TrafficScene : public QGraphicsScene {
    Q_OBJECT

public:
    TrafficScene(QObject *parent = nullptr);
    void drawRoad();
    void drawTrafficLight();
    void drawPedestrianCrossing();
    void addCar(int x, int y);

private slots:
    void updateScene();

private:
    QTimer *timer_;
    TrafficLight trafficLightModel_;
    Car carModel_;

    QGraphicsRectItem *carItem_;
    QGraphicsRectItem *postItem_;
    QGraphicsEllipseItem *lightItem_;
    int elapsedMs_;

    void updateTrafficLightColor();
};

#endif
