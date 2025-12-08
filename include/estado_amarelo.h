#ifndef ESTADO_AMARELO_H
#define ESTADO_AMARELO_H

#include "estado_semaforo.h"

class EstadoAmarelo : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override;
    void sair(SemaforoContexto& contexto) override;
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "AMARELO"; }
    bool permitePassagem() const override { return true; }
};

#endif
