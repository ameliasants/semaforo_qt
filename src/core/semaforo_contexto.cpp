#include "semaforo_contexto.h"
#include "estado_vermelho.h"      // definição completa
#include <memory>

SemaforoContexto::SemaforoContexto()
    : estadoAtual_(nullptr),
    tempoNoEstado_(0.0),
    horarioEscolar_(false) {
    definirEstado(std::make_unique<EstadoVermelho>());
}

void SemaforoContexto::definirEstado(std::unique_ptr<EstadoSemaforo> novoEstado) {
    if (estadoAtual_) {
        estadoAtual_->sair(*this);
    }
    estadoAtual_ = std::move(novoEstado);
    if (estadoAtual_) {
        estadoAtual_->entrar(*this);
    }
}

void SemaforoContexto::atualizar(double deltaTempo) {
    if (estadoAtual_) {
        estadoAtual_->atualizar(*this, deltaTempo);
    }
}
