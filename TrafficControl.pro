QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

TARGET = TrafficControl
TEMPLATE = app

INCLUDEPATH += $$PWD/include
DEPENDPATH  += $$PWD/include

SOURCES += \
    src/core/autocarro_escolar.cpp \
    src/core/carro_comum.cpp \
    src/core/estado_semaforo.cpp \
    src/core/fabrica_veiculos.cpp \
    src/core/gestor_configuracao.cpp \
    src/core/semaforo_contexto.cpp \
    src/core/veiculo.cpp \
    src/ui/main.cpp

HEADERS += \
    include/autocarro_escolar.h \
    include/carro_comum.h \
    include/estado_amarelo.h \
    include/estado_intermitente_escolar.h \
    include/estado_semaforo.h \
    include/estado_verde.h \
    include/estado_vermelho.h \
    include/fabrica_veiculos.h \
    include/gestor_configuracao.h \
    include/semaforo_contexto.h \
    include/veiculo.h

DISTFILES += \
    src/core/config.json
