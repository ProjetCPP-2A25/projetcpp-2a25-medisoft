#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql  printsupport charts network \
    quick

CONFIG += c++11

include(C:/Users/micro/OneDrive - ESPRIT/Bureau/projetcpp-2a25-medisoft-GestionCommandes/QZXing/src/QZXing.pri)

#QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    MAILER.cpp \
    SMS.cpp \
    commandes.cpp \
    employes.cpp \
    fournisseur.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    email.cpp \
    patient.cpp \
    produitai.cpp \
    produits.cpp \
    serialcommunication.cpp \
    ventilateur.cpp

HEADERS += \
    MAILER.h \
    SMS.h \
    commandes.h \
    employes.h \
    fournisseur.h \
        mainwindow.h \
    connection.h \
    email.h \
    patient.h \
    produitai.h \
    produits.h \
    serialcommunication.h \
    ventilateur.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    aidoc.qrc \
    ajouter.qrc \
    back.qrc \
    entrer.qrc \
    femme.qrc \
    firstpageee.qrc \
    logg.qrc \
    logo.qrc \
    maiil.qrc \
    map.qrc \
    mdp.qrc \
    notiff.qrc \
    pdf.qrc \
    premierepage.qrc \
    rech.qrc \
    ref.qrc \
    reveni.qrc \
    stat.qrc \
    welcome.qrc

DISTFILES += \
    qml.qml
