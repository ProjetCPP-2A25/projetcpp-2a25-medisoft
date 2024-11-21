QT       += multimedia multimediawidgets core gui sql printsupport
QT       += widgets concurrent
QT       += charts
TARGET = Atelier_Connexion
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    commandes.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp

HEADERS += \
    commandes.h \
    mainwindow.h \
    connection.h

FORMS += \
    mainwindow.ui

# Ajouter QZXing
include(C:/Users/Administrator/Documents/Atelier_Connexion - Copie/QZXing/src/QZXing.pri)



# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
