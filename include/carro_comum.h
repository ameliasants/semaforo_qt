#ifndef CARRO_COMUM_H
#define CARRO_COMUM_H

#include "veiculo.h"

class CarroComum : public Veiculo {
public:
    CarroComum(double posX = 0.0, double vel = 15.0);
    std::string tipo() const override;
};

#endif // CARRO_COMUM_H
