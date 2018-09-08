TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/utf16toutf8converter.cpp

DISTFILES += \
    Notes

HEADERS += \
    src/utf16toutf8converter.h
