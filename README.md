# TrafficControl – Zonas Escolares

Sistema de gerenciamento de tráfego em zonas escolares, com foco na segurança de estudantes.  
O projeto simula o comportamento de semáforos próximos a escolas, dando prioridade aos alunos em horários de entrada e saída e em situações de embarque/desembarque em autocarros escolares.

## Objetivos do Projeto

- Detecção de autocarro escolar para permitir paradas seguras.
- Sensores de presença em semáforos priorizando crianças.
- Ajuste automático dos tempos de semáforo conforme horários escolares (entrada/saída).
- Controle via terminal, exibindo o estado do semáforo e indicando quando há prioridade para estudantes.

Quando for horário escolar ou houver estudantes atravessando, o sistema mantém o semáforo vermelho para os veículos, garantindo a travessia segura dos alunos mesmo que o ciclo normal estivesse em verde.

## Principais Classes

- **`Semaforo` (`Semaforo.h` / `Semaforo.cpp`)**  
  Responsável por representar o semáforo veicular, delegando o comportamento de mudança de cor aos estados concretos. Expõe operações para atualizar o semáforo ao longo do tempo e consultar se os veículos podem passar.

- **`EstadoSemaforo` (`estado_semaforo.h` / `estado_semaforo.cpp`)**  
  Classe base abstrata que modela o padrão *State*. Cada estado concreto (verde, amarelo, vermelho, intermitente escolar, etc.) implementa a lógica de transição e a permissão de passagem.

- **`GestorConfiguracao` ou `Configuracao` (`configuracao.h` / `configuracao.cpp`)**  
  Centraliza as configurações do sistema, como tempos de verde normal e verde em horário escolar, além da lógica para determinar se o horário atual é de entrada/saída de alunos. Permite, no futuro, carregar essas informações de ficheiros de configuração (por exemplo, `config.json`).

- **`Veiculo` (`veiculo.h` / `veiculo.cpp`)**  
  Classe base para os veículos que circulam na rua (por exemplo, `AutocarroEscolar`, `CarroComum`). Armazena posição, velocidade e prioridade, permitindo simular movimento e utilizar filas de prioridade para favorecer veículos ligados aos estudantes.

## Entrada e Saída pelo Terminal

O sistema é executado em modo console, sem interface gráfica, permitindo:

- Exibir se o momento atual é ou não horário escolar.
- Mostrar o estado atual do semáforo (vermelho, amarelo, verde, intermitente escolar).
- Indicar se os veículos podem ou não passar.
- Evidenciar quando a prioridade está ativa para alunos (por exemplo, mantendo o vermelho enquanto haja estudantes atravessando em horário escolar).

## Estrutura de Pastas

Para manter boas práticas de organização e modularização, os arquivos estão separados da seguinte forma:

- `include/`  
  Contém todos os arquivos de cabeçalho (`.h`), como:
  - `Semaforo.h`
  - `estado_semaforo.h`
  - `configuracao.h` (ou `gestor_configuracao.h`)
  - `veiculo.h`
  - Demais estados concretos e tipos de veículos

- `src/core/`  
  Contém as implementações das classes de domínio (`.cpp`), como:
  - `Semaforo.cpp`
  - `estado_semaforo.cpp` e estados concretos (verde, amarelo, vermelho, intermitente escolar)
  - `configuracao.cpp` / `gestor_configuracao.cpp`
  - `veiculo.cpp` e subclasses de veículos

- `src/ui/`  
  Contém o `main.cpp` utilizado para testes via terminal, responsável por instanciar o semáforo, os veículos e orquestrar a simulação.

## Funcionamento em Alto Nível

1. O `main` inicializa o sistema, carregando (ou usando padrão) as configurações de tempo e de horário escolar.
2. O `GestorConfiguracao` informa se o momento atual é horário escolar e qual tempo de verde deve ser usado.
3. O `Semaforo` delega ao `EstadoSemaforo` atual a lógica de transição entre estados (verde → amarelo → vermelho → modos especiais).
4. Os `Veiculo`s são atualizados ao longo do tempo, podendo ser priorizados conforme seu tipo (por exemplo, autocarro escolar) e condições de segurança dos alunos.
5. Todas as informações relevantes (estado do semáforo, prioridade ativa, horário escolar) são exibidas no terminal.


