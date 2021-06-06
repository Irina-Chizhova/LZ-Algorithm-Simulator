#-------------------------------------------------
#
# Project created by QtCreator 2021-02-09T14:27:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES +=\
    source/codeword.cpp \
    source/codewordlz78.cpp \
    source/codewordlzw.cpp \
    source/datadict.cpp \
    source/dictionary.cpp \
    source/lz78.cpp \
    source/lz78decoding.cpp \
    source/lzw.cpp \
    source/lzwdecoding.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/question.cpp

HEADERS  +=\
    header/algorithm.h \
    header/algorithmdecoding.h \
    header/algorithmencoding.h \
    header/codeword.h \
    header/codewordlz78.h \
    header/codewordlzw.h \
    header/datadict.h \
    header/datadictstuct.h \
    header/dictionary.h \
    header/lz78.h \
    header/lz78decoding.h \
    header/lzw.h \
    header/lzwdecoding.h \
    header/mainwindow.h \
    header/question.h \
    header/statedata.h \
    header/statelzw.h \
    header/algorithm.h

FORMS    +=\
    forms/jointdemonstrationwindow.ui \
    forms/mainwindow.ui \
    forms/question.ui

DISTFILES += \
    config.txt \
    COPYING
