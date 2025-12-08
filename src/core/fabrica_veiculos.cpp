#include "fabrica_veiculos.h"
#include "autocarro_escolar.h"
#include "carro_comum.h"

std::unique_ptr<Veiculo> FabricaVeiculos::criar(const std::string& tipo, double posX) {
    if (tipo == "escolar") {
        return std::make_unique<AutocarroEscolar>(posX);
    } else {
        return std::make_unique<CarroComum>(posX);
    }
}
