TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ./src/main.cpp \
    ./src/hexbytearray.cpp

DISTFILES += \
    assumptions \
    Input/Input

HEADERS += \
    ./src/hexbytearray.h
