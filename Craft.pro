TEMPLATE = app
CONFIG += console C++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS +=

SOURCES += \
    main.cpp \
    core/application.cpp \
    world.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    core/application.h \
    core/global.hpp \
    world.h \
    components/component.hpp \
    system/system.hpp


