TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++1z
QMAKE_CXXFLAGS += -std=c++17
QMAKE_LFLAGS += -lstdc++fs

SOURCES += \
        src/main.cpp \
        src/processexplorer.cpp

HEADERS += \
    src/processexplorer.h \
    src/processinfo.h


