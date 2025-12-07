#ifndef CAR_H
#define CAR_H

class Car {
private:
    double x_;        // posição na rua
    double y_;
    double speed_;    // pixels por update
public:
    Car(double x = 0.0, double y = 0.0, double speed = 2.0);

    double x() const;
    double y() const;
    void setPosition(double x, double y);
    void setSpeed(double speed);
    void updatePosition();   // move o carro para a direita
};

#endif
