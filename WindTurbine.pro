TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c++11 -lm

SOURCES += main.cpp \
    airfoil.cpp \
    section.cpp \
    air.cpp \
    airfoildata.cpp \
    sectiondata.cpp

HEADERS += \
    airfoil.h \
    section.h \
    air.h \
    airfoildata.h \
    sectiondata.h

