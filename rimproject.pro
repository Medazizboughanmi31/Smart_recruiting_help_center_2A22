QT       += core gui sql printsupport
QT += printsupport  serialport charts network
QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    entreprise.cpp \
    excel.cpp \
    mailsmtp.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    src/src/emailaddress.cpp \
    src/src/mimeattachment.cpp \
    src/src/mimecontentformatter.cpp \
    src/src/mimefile.cpp \
    src/src/mimehtml.cpp \
    src/src/mimeinlinefile.cpp \
    src/src/mimemessage.cpp \
    src/src/mimemultipart.cpp \
    src/src/mimepart.cpp \
    src/src/mimetext.cpp \
    src/src/quotedprintable.cpp \
    src/src/smtpclient.cpp

HEADERS += \
    arduino.h \
    connection.h \
    entreprise.h \
    excel.h \
    mailsmtp.h \
    mainwindow.h \
    notification.h \
    src/src/SmtpMime \
    src/src/emailaddress.h \
    src/src/mimeattachment.h \
    src/src/mimecontentformatter.h \
    src/src/mimefile.h \
    src/src/mimehtml.h \
    src/src/mimeinlinefile.h \
    src/src/mimemessage.h \
    src/src/mimemultipart.h \
    src/src/mimepart.h \
    src/src/mimetext.h \
    src/src/quotedprintable.h \
    src/src/smtpclient.h \
    src/src/smtpexports.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
