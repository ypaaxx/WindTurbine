TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS +=  -std=c++11 -lm

LIBS +=

SOURCES += main.cpp \
    airfoil.cpp \
    air.cpp \
    airfoildata.cpp \
    mymath.cpp \
    rotor.cpp \
    section.cpp \
    sectiondata.cpp \


HEADERS += \
    airfoil.h \
    air.h \
    airfoildata.h \
    mymath.h \
    rotor.h \
    sectiondata.h \
    section.h


