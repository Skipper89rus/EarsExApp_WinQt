#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T21:55:25
#
#-------------------------------------------------

QT += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EarsExApp
TEMPLATE = app

SOURCES = \
    Main/Main.cpp \
    GUI/MainWindow.cpp \
    GUI/SettingsDialog.cpp \
    SoundStreams/DesktopSoundStream.cpp

HEADERS = \
    GUI/MainWindow.h \
    GUI/SettingsDialog.h \
    Common/SoundSampleBuffer.h \
    SoundStreams/ISoundStream.h \
    SoundStreams/DesktopSoundStream.h \
    SoundStreams/SoundStreamBuffer.h \
    SoundStreams/SoundStreamProcessor.h \
    SoundStreams/ISoundSampleProcessor.h \
    SoundStreamProcessor/ISoundStreamProcessorsManager.h \
    SoundStreamProcessor/SoundStreamProcessorsManager.h \
    SoundStreamProcessor/ISoundStreamProcessor.h \
    SoundStreamProcessor/SoundStreamProcessor.h \
    SoundStreamProcessor/DesktopSoundStreamProcessors/DesktopSoundStreamProcessorBase.h \
    SoundStreamProcessor/DesktopSoundStreamProcessors/DesktopSoundStreamProcessorTest.h \
    SoundStreamProcessors/DesktopSoundStreamProcessors/DesktopSoundStreamProcessorBase.h \
    SoundStreamProcessors/ISoundStreamProcessor.h \
    SoundStreamProcessors/SoundStreamProcessorsManager.h \
    SoundStreamProcessors/DesktopSoundStreamProcessors/DesktopSoundStreamProcessorTest.h

FORMS   = GUI/MainWindow.ui
