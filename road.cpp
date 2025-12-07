#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <string>

enum class TrafficLightState {
    RED,
    YELLOW,
    GREEN
};

class TrafficLight {
private:
    TrafficLightState state_;
    int duration_;

public:
    TrafficLight(TrafficLightState state = TrafficLightState::RED);

    TrafficLightState getState() const;
    void setState(TrafficLightState state);
    void changeState();
    int getDuration() const;
};

#endif
