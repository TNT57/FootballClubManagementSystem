QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmatchfixture.cpp \
    dateselected.cpp \
    main.cpp \
    matchfixture.cpp \
    navigator.cpp \
    people.cpp \
    removematchfixture.cpp \
    staff.cpp \
    player.cpp \
    teamstatistics.cpp

HEADERS += \
    addmatchfixture.h \
    dateselected.h \
    matchfixture.h \
    navigator.h \
    people.h \
    removematchfixture.h \
    staff.h \
    player.h \
    teamstatistics.h

FORMS += \
    addmatchfixture.ui \
    dateselected.ui \
    matchfixture.ui \
    navigator.ui \
    people.ui \
    removematchfixture.ui \
    staff.ui \
    player.ui \
    teamstatistics.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
