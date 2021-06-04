#-------------------------------------------------
#
# Project created by QtCreator 2021-02-09T14:27:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lzw.cpp \
    lz77.cpp \
    lz78.cpp \
    lzwdecoding.cpp \
    lz77decoding.cpp \
    lz78decoding.cpp \
    question.cpp \
    codeword.cpp \
    datadict.cpp

HEADERS  += mainwindow.h \
    algorithm.h \
    lzw.h \
    lz77.h \
    lz78.h \
    lzwdecoding.h \
    lz77decoding.h \
    lz78decoding.h \
    codeword.h \
    algorithmdecoding.h \
    algorithmencoding.h \
    1deff.h \
    question.h \
    statedata.h \
    statelzw.h \
    datadict.h

FORMS    += mainwindow.ui \
    question.ui \
    jointdemonstrationwindow.ui

DISTFILES +=
