#ifndef ESTADO_SEMAFORO_H
#define ESTADO_SEMAFORO_H

#include <string>

class SemaforoContexto;

class EstadoSemaforo {
public:
    virtual ~EstadoSemaforo() = default;
    virtual void entrar(SemaforoContexto& contexto) = 0;
    virtual void sair(SemaforoContexto& contexto) = 0;
    virtual void atualizar(SemaforoContexto& contexto, double deltaTempo) = 0;
    virtual std::string nome() const = 0;
    virtual bool permitePassagem() const = 0;
};

#endif
