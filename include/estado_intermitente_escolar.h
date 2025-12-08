#ifndef ESTADO_INTERMITENTE_ESCOLAR_H
#define ESTADO_INTERMITENTE_ESCOLAR_H

#include "estado_semaforo.h"

class EstadoIntermitenteEscolar : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override;
    void sair(SemaforoContexto& contexto) override;
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "INTERMITENTE_ESCOLAR"; }
    bool permitePassagem() const override { return true; }
};

#endif
