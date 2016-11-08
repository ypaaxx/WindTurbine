TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c99 -lm

SOURCES += main.cpp \
    airfoil.cpp \
    section.cpp

HEADERS += \
    airfoil.h \
    section.h

