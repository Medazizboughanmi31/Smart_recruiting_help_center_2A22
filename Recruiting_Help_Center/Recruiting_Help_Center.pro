QT       += core gui sql printsupport charts multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

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
    abonne.cpp \
    centre.cpp \
    choixagent.cpp \
    connexion.cpp \
    entreprise.cpp \
    entretien.cpp \
    gestion.cpp \
    historique.cpp \
    loggingin.cpp \
    mail.cpp \
    mailsmtp.cpp \
    main.cpp \
    mainwindow.cpp \
    offre.cpp \
    publication.cpp \
    reclamation.cpp \
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
    src/src/smtpclient.cpp \
    windowabonnes.cpp \
    windowcentres.cpp \
    windowentreprises.cpp \
    windowentretiens.cpp \
    windowoffres.cpp \
    windowpublications.cpp

HEADERS += \
    abonne.h \
    centre.h \
    choixagent.h \
    connexion.h \
    entreprise.h \
    entretien.h \
    gestion.h \
    historique.h \
    loggingin.h \
    mail.h \
    mailsmtp.h \
    mainwindow.h \
    offre.h \
    publication.h \
    reclamation.h \
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
    src/src/smtpexports.h \
    windowabonnes.h \
    windowcentres.h \
    windowentreprises.h \
    windowentretiens.h \
    windowoffres.h \
    windowpublications.h

FORMS += \
    choixagent.ui \
    gestion.ui \
    loggingin.ui \
    mainwindow.ui \
    windowabonnes.ui \
    windowcentres.ui \
    windowentreprises.ui \
    windowentretiens.ui \
    windowoffres.ui \
    windowpublications.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc \
    sound.qrc

DISTFILES += \
    localisation.qml
