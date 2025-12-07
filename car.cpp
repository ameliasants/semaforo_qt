#include "car.h"

Car::Car(double x, double y, double speed)
    : x_(x), y_(y), speed_(speed) {}

double Car::x() const { return x_; }
double Car::y() const { return y_; }

void Car::setPosition(double x, double y) {
    x_ = x;
    y_ = y;
}

void Car::setSpeed(double speed) {
    speed_ = speed;
}

void Car::updatePosition() {
    x_ += speed_;
}
