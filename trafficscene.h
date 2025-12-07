
#ifndef TRAFFICSCENE_H
#define TRAFFICSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include "traffic_light.h"

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
    TrafficLight *trafficLight_;
};

#endif
