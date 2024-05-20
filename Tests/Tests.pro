QT += testlib core gui widgets sql


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    maintests.cpp \
    tst_addplayer.cpp \
    tst_addstaff.cpp\
    ../addstaff.cpp\
    ../addplayer.cpp\
    ../removeplayer.cpp\
    ../removestaff.cpp\
    ../editstaff.cpp\
    ../editplayer.cpp\
    tst_editplayer.cpp \
    tst_editstaff.cpp \
    tst_removeplayer.cpp \
    tst_removestaff.cpp

HEADERS += \
    tst_addplayer.h \
    tst_addstaff.h\
    ../addstaff.h\
    ../addplayer.h\
    ../removeplayer.h\
    ../removestaff.h\
    ../editstaff.h\
    ../editplayer.h\
    tst_editplayer.h \
    tst_editstaff.h \
    tst_removeplayer.h \
    tst_removestaff.h
