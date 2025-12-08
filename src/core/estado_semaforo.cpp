#include "estado_semaforo.h"
#include "semaforo_contexto.h"
#include "gestor_configuracao.h"
#include <memory>

class EstadoVerde : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override {
        contexto.reiniciarTempoNoEstado();
        contexto.definirHorarioEscolar(GestorConfiguracao::obterInstancia().estaEmHorarioEscolar());
    }
    void sair(SemaforoContexto&) override {}
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "VERDE"; }
    bool permitePassagem() const override { return true; }
};

class EstadoAmarelo : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override { contexto.reiniciarTempoNoEstado(); }
    void sair(SemaforoContexto&) override {}
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "AMARELO"; }
    bool permitePassagem() const override { return true; }
};

class EstadoVermelho : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override { contexto.reiniciarTempoNoEstado(); }
    void sair(SemaforoContexto&) override {}
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "VERMELHO"; }
    bool permitePassagem() const override { return false; }
};

class EstadoIntermitenteEscolar : public EstadoSemaforo {
public:
    void entrar(SemaforoContexto& contexto) override { contexto.reiniciarTempoNoEstado(); }
    void sair(SemaforoContexto&) override {}
    void atualizar(SemaforoContexto& contexto, double deltaTempo) override;
    std::string nome() const override { return "INTERMITENTE_ESCOLAR"; }
    bool permitePassagem() const override { return true; }
};

// Lógicas simplificadas de transição

void EstadoVerde::atualizar(SemaforoContexto& contexto, double deltaTempo) {
    contexto.incrementarTempoNoEstado(deltaTempo);
    int limite = GestorConfiguracao::obterInstancia().tempoVerdeAtual();
    if (contexto.tempoNoEstado() > limite) {
        contexto.definirEstado(std::make_unique<EstadoAmarelo>());
    }
}

void EstadoAmarelo::atualizar(SemaforoContexto& contexto, double deltaTempo) {
    contexto.incrementarTempoNoEstado(deltaTempo);
    if (contexto.tempoNoEstado() > 3.0) { // 3 segundos, por exemplo
        contexto.definirEstado(std::make_unique<EstadoVermelho>());
    }
}

void EstadoVermelho::atualizar(SemaforoContexto& contexto, double deltaTempo) {
    contexto.incrementarTempoNoEstado(deltaTempo);
    if (contexto.tempoNoEstado() > 10.0) {
        if (contexto.estaEmHorarioEscolar()) {
            contexto.definirEstado(std::make_unique<EstadoIntermitenteEscolar>());
        } else {
            contexto.definirEstado(std::make_unique<EstadoVerde>());
        }
    }
}

void EstadoIntermitenteEscolar::atualizar(SemaforoContexto& contexto, double deltaTempo) {
    contexto.incrementarTempoNoEstado(deltaTempo);
    if (!GestorConfiguracao::obterInstancia().estaEmHorarioEscolar()) {
        contexto.definirEstado(std::make_unique<EstadoVerde>());
    }
}
