#ifndef GESTOR_CONFIGURACAO_H
#define GESTOR_CONFIGURACAO_H

#include <string>
#include <exception>
#include <chrono>

class ErroConfiguracao : public std::exception {
private:
    std::string mensagem_;
public:
    explicit ErroConfiguracao(const std::string& mensagem);
    const char* what() const noexcept override;
};

class GestorConfiguracao {
private:
    static GestorConfiguracao* instancia_;
    GestorConfiguracao();

    int tempoVerdeNormal_;
    int tempoVerdeEscolar_;

public:
    static GestorConfiguracao& obterInstancia();
    ~GestorConfiguracao();

    void carregarConfiguracao(const std::string& caminhoFicheiro);

    bool estaEmHorarioEscolar() const;
    int tempoVerdeAtual() const;
};

#endif
