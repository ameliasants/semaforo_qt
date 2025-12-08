#include "gestor_configuracao.h"
#include <fstream>
#include <sstream>

GestorConfiguracao* GestorConfiguracao::instancia_ = nullptr;

ErroConfiguracao::ErroConfiguracao(const std::string& mensagem)
    : mensagem_(mensagem) {}

const char* ErroConfiguracao::what() const noexcept {
    return mensagem_.c_str();
}

GestorConfiguracao::GestorConfiguracao()
    : tempoVerdeNormal_(30),
    tempoVerdeEscolar_(45) {}

GestorConfiguracao::~GestorConfiguracao() = default;

GestorConfiguracao& GestorConfiguracao::obterInstancia() {
    if (!instancia_) {
        instancia_ = new GestorConfiguracao();
    }
    return *instancia_;
}

void GestorConfiguracao::carregarConfiguracao(const std::string& caminhoFicheiro) {
    std::ifstream ficheiro(caminhoFicheiro);
    if (!ficheiro.is_open()) {
        throw ErroConfiguracao("Ficheiro config.json não encontrado: " + caminhoFicheiro);
    }

    std::stringstream buffer;
    buffer << ficheiro.rdbuf();
    std::string conteudo = buffer.str();

    if (conteudo.find("\"zona_escolar\"") == std::string::npos) {
        throw ErroConfiguracao("JSON inválido: falta objeto zona_escolar");
    }

    // Parsing real ficará na camada UI com Qt JSON
}

bool GestorConfiguracao::estaEmHorarioEscolar() const {
    // Placeholder: depois será substituído por lógica de horário real
    return true;
}

int GestorConfiguracao::tempoVerdeAtual() const {
    return estaEmHorarioEscolar() ? tempoVerdeEscolar_ : tempoVerdeNormal_;
}
