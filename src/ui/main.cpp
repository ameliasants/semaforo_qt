
/*#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("TrafficControl - placeholder");
    w.resize(320, 200);
    w.show();
    return app.exec();
}
*/

#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include "fabrica_veiculos.h"
#include "autocarro_escolar.h"
#include "carro_comum.h"
#include "semaforo_contexto.h"
#include "gestor_configuracao.h"
#include "estado_verde.h"
#include "estado_amarelo.h"
#include "estado_vermelho.h"
#include "estado_intermitente_escolar.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    std::cout << "===== TESTE CORE: VEICULOS E SEMAFORO =====\n";

    // -------------------------------------------------
    // 1) TESTE DA FACTORY
    // -------------------------------------------------
    std::unique_ptr<Veiculo> vEscolar = FabricaVeiculos::criar("escolar", 0.0);
    std::unique_ptr<Veiculo> vPais    = FabricaVeiculos::criar("pais", 0.0);  // vira CarroComum

    std::cout << "\n[Factory] Veiculos criados:\n";
    std::cout << " - Tipo: " << vEscolar->tipo()
              << " | prioridade = " << vEscolar->prioridade() << '\n';
    std::cout << " - Tipo: " << vPais->tipo()
              << " | prioridade = " << vPais->prioridade() << '\n';

    qDebug() << "[Factory] Prioridade escolar < pais ?"
             << ( (*vEscolar) < (*vPais) );

    // -------------------------------------------------
    // 2) TESTE DE POLIMORFISMO (mover/atualizar)
    // -------------------------------------------------
    std::cout << "\n[Teste Polimorfismo] Movimento dos veiculos:\n";
    double deltaTempo = 1.0; // 1 segundo

    vEscolar->atualizar(deltaTempo);
    vPais->atualizar(deltaTempo);

    std::cout << " - " << vEscolar->tipo()
              << " nova posicaoX = " << vEscolar->posicaoX() << " m\n";
    std::cout << " - " << vPais->tipo()
              << " nova posicaoX = " << vPais->posicaoX() << " m\n";

    // -------------------------------------------------
    // 3) TESTE DO SEMAFORO (STATE)
    // -------------------------------------------------
    std::cout << "\n[Teste Semaforo] Transicoes de estado:\n";

    // Opcional: carregar config (vai lançar ErroConfiguracao se não achar ficheiro)
    try {
        GestorConfiguracao::obterInstancia().carregarConfiguracao("config.json");
        std::cout << "Config.json carregado.\n";
    } catch (const ErroConfiguracao& e) {
        std::cout << "Falha ao carregar configuracao: " << e.what()
        << " (seguindo com valores default)\n";
    }

    SemaforoContexto semaforo;

    double passoTempo = 1.0; // 1 segundo por iteracao
    for (int i = 0; i < 10; ++i) {
        std::cout << "Iteracao " << i
                  << " | Estado = " << semaforo.estadoAtualNome()
                  << " | pode_passar = " << (semaforo.permitePassagem() ? "SIM" : "NAO")
                  << std::endl;

        qDebug() << "[Semaforo] iteracao" << i
                 << "estado =" << QString::fromStdString(semaforo.estadoAtualNome());

        semaforo.atualizar(passoTempo);

        // Pequena pausa para facilitar leitura no console
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout << "\n===== FIM DO TESTE CORE =====\n";
    std::cout << "Pressione ENTER para sair...\n";
    std::cin.get();
    // Não precisamos manter loop de eventos; podemos terminar já.
    return 0;
}
