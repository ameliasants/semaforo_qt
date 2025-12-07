#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

enum class TrafficLightState {
    RED,
    YELLOW,
    GREEN
};

class TrafficLight {
private:
    TrafficLightState state_;

public:
    TrafficLight(TrafficLightState state = TrafficLightState::RED);

    TrafficLightState getState() const;
    void setState(TrafficLightState state);
    void changeState();      // RED -> GREEN -> YELLOW -> RED
};

#endif
