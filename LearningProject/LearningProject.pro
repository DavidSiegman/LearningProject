QT += core
QT -= gui

CONFIG += c++

TARGET = LearningProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    SortingConditions/sortingconditions.cpp

HEADERS += \
    LinkedListClass/linkedlistclass.h \
    LinkedListClass/nodeclass.h \
    SortingConditions/sortingconditions.h \
    DoubleLinkedListClass/doublelinkedlistclass.h \
    DoubleLinkedListClass/dllnodeclass.h
