# -------------------------------------------------
# Project created by QtCreator 2013-07-30T18:35:05
# -------------------------------------------------
QT += multimedia widgets core
CONFIG += console
LIBS += -lasound
TARGET = MIDI_PLAYER
TEMPLATE = app
SOURCES += midi_player.cpp \
    main.cpp \
    player.cpp \
    file_parser.cpp
HEADERS += midi_player.h
FORMS += midi_player.ui
DEFINES += QT_NO_DEBUG_OUTPUT
