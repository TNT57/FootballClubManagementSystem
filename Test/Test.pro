QT += testlib core gui widgets sql


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    maintest.cpp \
    tst_addstaff.cpp\
    ../addstaff.cpp\

HEADERS += \
    tst_addstaff.h\
    ../addstaff.h\
