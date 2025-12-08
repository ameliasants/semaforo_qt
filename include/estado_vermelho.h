#ifndef ESTADO_VERMELHO_H
#define ESTADO_VERMELHO_H

#include "estado_semaforo.h"

class EstadoVermelho : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override;
    void sair(SemaforoContexto& contexto) override;
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "VERMELHO"; }
    bool permitePassagem() const override { return false; }
};

#endif
