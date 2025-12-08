#ifndef SEMAFORO_CONTEXTO_H
#define SEMAFORO_CONTEXTO_H

#include "estado_semaforo.h"
#include <memory>
#include <string>

class SemaforoContexto {
private:
    std::unique_ptr<EstadoSemaforo> estadoAtual_;
    double tempoNoEstado_;
    bool horarioEscolar_;

public:
    SemaforoContexto();

    void definirEstado(std::unique_ptr<EstadoSemaforo> novoEstado);
    EstadoSemaforo& estadoAtual() const { return *estadoAtual_; }

    void atualizar(double deltaTempo);
    bool permitePassagem() const { return estadoAtual_ && estadoAtual_->permitePassagem(); }
    std::string estadoAtualNome() const { return estadoAtual_ ? estadoAtual_->nome() : "DESCONHECIDO"; }

    void definirHorarioEscolar(bool ativo) { horarioEscolar_ = ativo; }
    bool estaEmHorarioEscolar() const { return horarioEscolar_; }

    double tempoNoEstado() const { return tempoNoEstado_; }
    void incrementarTempoNoEstado(double delta) { tempoNoEstado_ += delta; }
    void reiniciarTempoNoEstado() { tempoNoEstado_ = 0.0; }
};

#endif
