TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread -lSDL2 -lGL -lGLU

SOURCES += \
    main.cpp \
    core/application.cpp \
    world.cpp \
    system/rendersystem.cpp \
    core/screen.cpp \
    screens/gamescreen.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    core/application.h \
    core/global.hpp \
    world.h \
    components/component.hpp \
    system/system.hpp \
    system/rendersystem.h \
    core/screen.h \
    screens/gamescreen.h


