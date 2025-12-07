#include "traffic_light.h"

TrafficLight::TrafficLight(TrafficLightState state)
    : state_(state) {}

TrafficLightState TrafficLight::getState() const {
    return state_;
}

void TrafficLight::setState(TrafficLightState state) {
    state_ = state;
}

void TrafficLight::changeState() {
    switch (state_) {
    case TrafficLightState::RED:
        state_ = TrafficLightState::GREEN;
        break;
    case TrafficLightState::GREEN:
        state_ = TrafficLightState::YELLOW;
        break;
    case TrafficLightState::YELLOW:
        state_ = TrafficLightState::RED;
        break;
    }
}
