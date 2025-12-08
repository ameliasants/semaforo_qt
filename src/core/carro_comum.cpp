#include "carro_comum.h"

CarroComum::CarroComum(double posX, double vel)
    : Veiculo(posX, vel, 0) {}

std::string CarroComum::tipo() const {
    return "Carro Comum";
}
