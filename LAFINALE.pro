QT       += core gui sql printsupport  serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arduinoo
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4):

QT += widgets multimedia



TARGET = test_son

TEMPLATE = app
QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
TARGET = project
TEMPLATE = app

CONFIG += c++11
QT       += core gui sql multimediawidgets

QT       += core gui multimedia

QT       += core gui printsupport

QT       +=  network

QT       += core gui widgets texttospeech
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
TARGET = project
TEMPLATE = app

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    capture.cpp \
    class_services.cpp \
    classe_personnel.cpp \
    connexion.cpp \
    dialog.cpp \
    dialog2.cpp \
    dialog3.cpp \
    entretien.cpp \
    fournisseur.cpp \
    fournisseur1.cpp \
    image.cpp \
    main.cpp \
    mainwindow.cpp \
    materiels.cpp \
    notification.cpp \
    patient.cpp \
    rendezvous.cpp \
    ressource.cpp \
    scanner.cpp \
    stat_ressource.cpp \
    stock.cpp

HEADERS += \
    admin.h \
    capture.h \
    class_services.h \
    classe_personnel.h \
    connexion.h \
    dialog.h \
    dialog2.h \
    dialog3.h \
    entretien.h \
    fournisseur.h \
    fournisseur1.h \
    image.h \
    mainwindow.h \
    materiels.h \
    notification.h \
    patient.h \
    rendezvous.h \
    ressource.h \
    scanner.h \
    stat_ressource.h \
    stock.h

FORMS += \
    capture.ui \
    dialog.ui \
    dialog2.ui \
    dialog3.ui \
    image.ui \
    mainwindow.ui \
    stat_ressource.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img.png
