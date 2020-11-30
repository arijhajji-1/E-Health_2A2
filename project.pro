QT       += core gui sql

QT       += core gui printsupport

QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
TARGET = project
TEMPLATE = app

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    ressource.cpp \
    scanner.cpp \
    stati.cpp

HEADERS += \
    connexion.h \
    mainwindow.h \
    ressource.h \
    scanner.h \
    stati.h

FORMS += \
    mainwindow.ui \
    stati.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    resources/click.mp3 \
    resources/template.png
