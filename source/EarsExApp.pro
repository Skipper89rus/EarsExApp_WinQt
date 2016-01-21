#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T21:55:25
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EarsExApp
TEMPLATE = app


SOURCES += main/main.cpp \
           main/mainwindow.cpp \
    soundstreams/soundstreams.cpp \
    soundstreams/soundstreamsmanager.cpp

HEADERS += main/mainwindow.h \
    soundstreams/isoundstream.h \
    soundstreams/soundstreams.h \
    soundstreams/soundstreamsmanager.h

FORMS   += main/mainwindow.ui
