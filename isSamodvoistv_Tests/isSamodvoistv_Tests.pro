QT += testlib sql network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_mytestsclass.cpp \
    ../server/funcs.cpp \
    ../server/singleton.cpp \
    ../server/tcpserver.cpp

HEADERS += \
    ../server/funcs.h \
    ../server/singleton.h \
    ../server/tcpserver.h
