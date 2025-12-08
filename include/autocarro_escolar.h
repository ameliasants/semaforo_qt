#ifndef AUTOCARRO_ESCOLAR_H
#define AUTOCARRO_ESCOLAR_H

#include "veiculo.h"

class AutocarroEscolar : public Veiculo {
public:
    AutocarroEscolar(double posX = 0.0, double vel = 10.0);
    std::string tipo() const override;
};

#endif // AUTOCARRO_ESCOLAR_H
