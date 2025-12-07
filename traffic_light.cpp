#include "traffic_light.h"

//traffic_light::traffic_light() {}
TrafficLight::TrafficLight(TrafficLightState state)
    : state_(state), duration_(0) {
}


void TrafficLight::setState(TrafficLightState state) {
    state_ = state;
}

void TrafficLight::changeState() {
    // exemplo simples só para compilar
    if (state_ == TrafficLightState::RED)
        state_ = TrafficLightState::GREEN;
    else
        state_ = TrafficLightState::RED;
}

int TrafficLight::getDuration() const {
    return duration_;
}
