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
    ../teamstatistics.cpp\
    ../simulatematch.cpp\
    tst_editplayer.cpp \
    tst_editstaff.cpp \
    tst_removeplayer.cpp \
    tst_removestaff.cpp \
    tst_simulatematch.cpp \
    tst_teamstatistics.cpp

HEADERS += \
    tst_addplayer.h \
    tst_addstaff.h\
    ../addstaff.h\
    ../addplayer.h\
    ../removeplayer.h\
    ../removestaff.h\
    ../editstaff.h\
    ../editplayer.h\
    ../teamstatistics.h\
    ../simulatematch.h\
    tst_editplayer.h \
    tst_editstaff.h \
    tst_removeplayer.h \
    tst_removestaff.h \
    tst_simulatematch.h \
    tst_teamstatistics.h
