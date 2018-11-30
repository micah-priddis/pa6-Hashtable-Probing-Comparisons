TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    TestAim1.cpp \
    LinearProbing.cpp \
    QuadraticProbing.cpp \
    SeparateChaining.cpp

SUBDIRS += \
    PA6.pro

DISTFILES += \
    PA6.pro.user \
    OHenry.txt \
    queries.txt

HEADERS += \
    LinearProbing.h \
    QuadraticProbing.h \
    SeparateChaining.h
