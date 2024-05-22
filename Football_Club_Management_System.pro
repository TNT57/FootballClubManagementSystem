QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmatchfixture.cpp \
    addtransferlist.cpp \
    chooseopponentxi.cpp \
    chooseourxi.cpp \
    dateselected.cpp \
    editmatchfixture.cpp \
    editplayer.cpp \
    editstaff.cpp \
    edittransferlist.cpp \
    main.cpp \
    matchfixture.cpp \
    opponentstartingxi.cpp \
    ourstartingxi.cpp \
    removematchfixture.cpp \
    removeplayer.cpp \
    removestaff.cpp \
    removetransferlist.cpp \
    simulatematch.cpp \
    startinglist.cpp \
    teamstatistics.cpp \
    teamlist.cpp \
    staff.cpp \
    player.cpp \
    people.cpp \
    navigator.cpp \
    addplayer.cpp\
    addstaff.cpp \
    transferlist.cpp

HEADERS += \
    addmatchfixture.h \
    addtransferlist.h \
    chooseopponentxi.h \
    chooseourxi.h \
    dateselected.h \
    editmatchfixture.h \
    editplayer.h \
    editstaff.h \
    edittransferlist.h \
    matchfixture.h \
    opponentstartingxi.h \
    ourstartingxi.h \
    removematchfixture.h \
    removeplayer.h \
    removestaff.h \
    removetransferlist.h \
    simulatematch.h \
    startinglist.h \
    teamstatistics.h \
    teamlist.h \
    staff.h \
    player.h \
    people.h \
    navigator.h \
    addplayer.h \
    addstaff.h \
    transferlist.h

FORMS += \
    addmatchfixture.ui \
    addtransferlist.ui \
    chooseopponentxi.ui \
    chooseourxi.ui \
    dateselected.ui \
    editmatchfixture.ui \
    editplayer.ui \
    editstaff.ui \
    edittransferlist.ui \
    matchfixture.ui \
    removematchfixture.ui \
    removeplayer.ui \
    removestaff.ui \
    removetransferlist.ui \
    simulatematch.ui \
    startinglist.ui \
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
