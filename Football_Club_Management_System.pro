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
    editplayer.cpp \
    editstaff.cpp \
    main.cpp \
    matchfixture.cpp \
    removematchfixture.cpp \
    removeplayer.cpp \
    removestaff.cpp \
    teamstatistics.cpp \
    teamlist.cpp \
    staff.cpp \
    player.cpp \
    people.cpp \
    navigator.cpp \
    addplayer.cpp\
    addstaff.cpp

HEADERS += \
    addmatchfixture.h \
    dateselected.h \
    editplayer.h \
    editstaff.h \
    matchfixture.h \
    removematchfixture.h \
    removeplayer.h \
    removestaff.h \
    teamstatistics.h \
    teamlist.h \
    staff.h \
    player.h \
    people.h \
    navigator.h \
    addplayer.h \
    addstaff.h

FORMS += \
    addmatchfixture.ui \
    dateselected.ui \
    editplayer.ui \
    editstaff.ui \
    matchfixture.ui \
    removematchfixture.ui \
    removeplayer.ui \
    removestaff.ui \
    teamstatistics.ui \
    teamlist.ui \
    people.ui \
    navigator.ui \
    addplayer.ui \
    addstaff.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
