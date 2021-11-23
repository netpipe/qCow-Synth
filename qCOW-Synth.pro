#-------------------------------------------------
#
# Project created by QtCreator 2020-06-22T14:59:11
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qCOW-Synth
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += fluidlite/include
CONFIG += c++11

SOURCES += \
    fluidlite/fluid_chan.c \
    fluidlite/fluid_chorus.c \
    fluidlite/fluid_conv.c \
    fluidlite/fluid_defsfont.c \
    fluidlite/fluid_dsp_float.c \
    fluidlite/fluid_gen.c \
    fluidlite/fluid_hash.c \
    fluidlite/fluid_init.c \
    fluidlite/fluid_list.c \
    fluidlite/fluid_mod.c \
    fluidlite/fluid_ramsfont.c \
    fluidlite/fluid_rev.c \
    fluidlite/fluid_settings.c \
    fluidlite/fluid_synth.c \
    fluidlite/fluid_sys.c \
    fluidlite/fluid_tuning.c \
    fluidlite/fluid_voice.c \
    fluidlite/stb/stb_vorbis.c \
        main.cpp \
        mainwindow.cpp \
    sfxthread.cpp

HEADERS += \
    fluidlite/fluid_chan.h \
    fluidlite/fluid_chorus.h \
    fluidlite/fluid_config.h \
    fluidlite/fluid_conv.h \
    fluidlite/fluid_defsfont.h \
    fluidlite/fluid_gen.h \
    fluidlite/fluid_hash.h \
    fluidlite/fluid_list.h \
    fluidlite/fluid_midi.h \
    fluidlite/fluid_mod.h \
    fluidlite/fluid_phase.h \
    fluidlite/fluid_ramsfont.h \
    fluidlite/fluid_rev.h \
    fluidlite/fluid_settings.h \
    fluidlite/fluid_sfont.h \
    fluidlite/fluid_synth.h \
    fluidlite/fluid_sys.h \
    fluidlite/fluid_tuning.h \
    fluidlite/fluid_voice.h \
    fluidlite/fluidsynth_priv.h \
    fluidlite/include/fluidlite.h \
    fluidlite/include/fluidsynth/gen.h \
    fluidlite/include/fluidsynth/log.h \
    fluidlite/include/fluidsynth/misc.h \
    fluidlite/include/fluidsynth/mod.h \
    fluidlite/include/fluidsynth/ramsfont.h \
    fluidlite/include/fluidsynth/settings.h \
    fluidlite/include/fluidsynth/sfont.h \
    fluidlite/include/fluidsynth/synth.h \
    fluidlite/include/fluidsynth/types.h \
    fluidlite/include/fluidsynth/version.h \
    fluidlite/include/fluidsynth/voice.h \
        mainwindow.h \
    sfxthread.h \
    sfxplayer.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fluidlite/LICENSE \
    fluidlite/README.md \
    fluidlite/main.cbp \
    fluidlite/soundfont.sf2
