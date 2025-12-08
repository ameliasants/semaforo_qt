#ifndef ESTADO_VERDE_H
#define ESTADO_VERDE_H

#include "estado_semaforo.h"

class EstadoVerde : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override;
    void sair(SemaforoContexto& contexto) override;
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "VERDE"; }
    bool permitePassagem() const override { return true; }
};

#endif
