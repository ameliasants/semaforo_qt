#ifndef FABRICA_VEICULOS_H
#define FABRICA_VEICULOS_H

#include "veiculo.h"
#include <memory>

class FabricaVeiculos {
public:
    static std::unique_ptr<Veiculo> criar(const std::string& tipo, double posX);
};

#endif // FABRICA_VEICULOS_H
