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
    connexion.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp \
    ressource.cpp \
    scanner.cpp \
    stat_ressource.cpp \
    capture.cpp \
    image.cpp

HEADERS += \
    connexion.h \
    fournisseur.h \
    mainwindow.h \
    ressource.h \
    scanner.h \
    stat_ressource.h \
    capture.h \
    image.h

FORMS += \
    mainwindow.ui \
    stat_ressource.ui \
    capture.ui \
    image.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image_oumaima.qrc

DISTFILES += \
    resources/click.mp3 \
    resources/template.png
