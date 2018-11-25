#-------------------------------------------------
#
# Project created by QtCreator 2017-11-13T16:12:20
#
#-------------------------------------------------

QT       += core

QT       -= gui

CONFIG += c++11

TARGET = hawman
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    bintreenode.cpp \
    bintreeend.cpp \
    bintree.cpp \
    bitfile.cpp

HEADERS += \
    bintreenode.h \
    bintreeend.h \
    bintree.h \
    bitfile.h

SUBDIRS += hawman.pro

DISTFILES +=
