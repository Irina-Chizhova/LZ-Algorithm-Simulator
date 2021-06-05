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
    sourse/codeword.cpp \
    sourse/codewordlz78.cpp \
    sourse/codewordlzw.cpp \
    sourse/datadict.cpp \
    sourse/dictionary.cpp \
    sourse/lz78.cpp \
    sourse/lz78decoding.cpp \
    sourse/lzw.cpp \
    sourse/lzwdecoding.cpp \
    sourse/main.cpp \
    sourse/mainwindow.cpp \
    sourse/question.cpp

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
