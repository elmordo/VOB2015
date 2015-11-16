TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    PublicRule.cpp \
    EatRule.cpp \
    GameItem.cpp \
    IRule.cpp \
    KVZ.cpp \
    stdafx.cpp \
    WinRule.cpp \
    World.cpp \
    MoveObj.cpp \
    MoveFerry.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    PublicRule.hpp \
    EatRule.h \
    GameItem.h \
    IRule.h \
    stdafx.h \
    WinRule.h \
    World.h \
    MoveObj.hpp \
    MoveFerry.hpp

