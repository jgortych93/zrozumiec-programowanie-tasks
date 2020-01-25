TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/debugger.cpp \
        src/main.cpp

DISTFILES += \
    README.MD

HEADERS += \
    src/debugger.hpp \
    src/registry_read_instructions.hpp
    src/registry_read_instructions.hpp
