QT += core gui
QT += network   # подключаем модуль сети

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialoglogin.cpp \
    dialogregister.cpp \
    dialogresults.cpp \
    dialogtask.cpp \
    main.cpp \
    mainwindow.cpp \
    singleton.cpp

HEADERS += \
    dialoglogin.h \
    dialogregister.h \
    dialogresults.h \
    dialogtask.h \
    mainwindow.h \
    singleton.h

FORMS += \
    dialoglogin.ui \
    dialogregister.ui \
    dialogresults.ui \
    dialogtask.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
