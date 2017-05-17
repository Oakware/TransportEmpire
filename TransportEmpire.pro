QT += core websockets testlib
QT -= gui

CONFIG += c++11
CONFIG += warn_off

TARGET = TransportEmpire
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    Model/Bus.cpp \
    Model/BusTypeInfo.cpp \
    Model/City.cpp \
    Model/Path.cpp \
    Model/Race.cpp \
    Model/RaceStatistics.cpp \
    Model/Route.cpp \
    Model/RouteStatistics.cpp \
    Model/ScheduledRace.cpp \
    Server/serverclient.cpp \
    Server/webserver.cpp \
    Server/reply.cpp \
    Server/request.cpp \
    Server/router.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Model/Bus.h \
    Model/BusTypeInfo.h \
    Model/City.h \
    Model/Money.h \
    Model/Path.h \
    Model/Race.h \
    Model/RaceStatistics.h \
    Model/Route.h \
    Model/RouteStatistics.h \
    Model/ScheduledRace.h \
    Test/TestSuite.h \
    Server/serverclient.hpp \
    Server/webserver.hpp \
    Server/controller.h \
    Server/reply.h \
    Server/request.h \
    Server/router.h \
    Server/testcontroller.hpp

