QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

TARGET = TrafficControl
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    trafficscene.cpp \
    car.cpp \
    traffic_light.cpp \
    road.cpp

HEADERS += \
    mainwindow.h \
    trafficscene.h \
    car.h \
    traffic_light.h \
    road.h
