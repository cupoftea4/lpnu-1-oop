QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bankaccount_tnr.cpp \
    form.cpp \
    main.cpp \
    lab08_tnr.cpp \
    socialaccount_tnr.cpp \
    vipaccount_tnr.cpp

HEADERS += \
    bankaccount_tnr.h \
    form.h \
    lab08_tnr.h \
    socialaccount_tnr.h \
    vipaccount_tnr.h

FORMS += \
    form.ui \
    lab08_tnr.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
