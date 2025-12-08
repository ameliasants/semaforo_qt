#include "veiculo.h"
#include <iostream>

Veiculo::Veiculo(double posX, double vel, int prio)
    : posicaoX_(posX), velocidade_(vel), prioridade_(prio) {}

void Veiculo::atualizar(double deltaTempo) {
    posicaoX_ += velocidade_ * deltaTempo;
}

bool Veiculo::operator<(const Veiculo& outro) const {
    return prioridade_ < outro.prioridade_;
}
