QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account_tnr.cpp \
    bankaccount_tnr.cpp \
    form.cpp \
    main.cpp \
    lab09_tnr.cpp \
    signalemitter.cpp \
    socialaccount_tnr.cpp \
    vipaccount_tnr.cpp

HEADERS += \
    Account_TNR.h \
    bankaccount_tnr.h \
    form.h \
    lab09_tnr.h \
    signalemitter.h \
    socialaccount_tnr.h \
    vipaccount_tnr.h

FORMS += \
    form.ui \
    lab09_tnr.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
