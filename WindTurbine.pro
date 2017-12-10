TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS +=  -std=c++17 -lm

LIBS +=

SOURCES += main.cpp \
    airfoil.cpp \
    air.cpp \
    airfoildata.cpp \
    mymath.cpp \
    rotor.cpp \


HEADERS += \
    airfoil.h \
    air.h \
    airfoildata.h \
    mymath.h \
    rotor.h


