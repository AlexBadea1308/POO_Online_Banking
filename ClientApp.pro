QT       += core gui network
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acont.cpp \
    admin.cpp \
    admin_window.cpp \
    ahandler.cpp \
    apersoana.cpp \
    app_bank_window.cpp \
    atranzactie.cpp \
    card.cpp \
    changefieldhandler.cpp \
    changepasswordhandler.cpp \
    client.cpp \
    cont_admin.cpp \
    cont_utilizator.cpp \
    depunere.cpp \
    depunerehandler.cpp \
    detailscardhandler.cpp \
    factoryhandler.cpp \
    factorytranzactie.cpp \
    gestionarecardhandler.cpp \
    historytranzaction.cpp \
    icont.cpp \
    ihandler.cpp \
    ipersoana.cpp \
    itranzactie.cpp \
    loginhandler.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    myexceptions.cpp \
    plata_pos_handler.cpp \
    pos_transfer.cpp \
    retragere.cpp \
    retragerehandler.cpp \
    sconnect_to_server.cpp \
    sconnect_to_server.cpp \
    sconnect_to_server_admin.cpp \
    security_questions_window.cpp \
    signup_window.cpp \
    signuphandler.cpp \
    transfer.cpp \
    transfer_handler.cpp \
    transfermultibank.cpp \
    verifysecurityhandler.cpp

HEADERS += \
    acont.h \
    admin.h \
    admin_window.h \
    ahandler.h \
    apersoana.h \
    app_bank_window.h \
    atranzactie.h \
    card.h \
    changefieldhandler.h \
    changepasswordhandler.h \
    client.h \
    cont_admin.h \
    cont_utilizator.h \
    depunere.h \
    depunerehandler.h \
    detailscardhandler.h \
    factoryhandler.h \
    factorytranzactie.h \
    gestionarecardhandler.h \
    historytranzaction.h \
    icont.h \
    ihandler.h \
    ipersoana.h \
    itranzactie.h \
    loginhandler.h \
    loginwindow.h \
    mainwindow.h \
    myexceptions.h \
    plata_pos_handler.h \
    pos_transfer.h \
    retragere.h \
    retragerehandler.h \
    sconnect_to_server.h \
    sconnect_to_server.h \
    sconnect_to_server_admin.h \
    security_questions_window.h \
    signup_window.h \
    signuphandler.h \
    transfer.h \
    transfer_handler.h \
    transfermultibank.h \
    verifysecurityhandler.h

FORMS += \
    admin_window.ui \
    app_bank_window.ui \
    loginwindow.ui \
    mainwindow.ui \
    security_questions_window.ui \
    signup_window.ui


LIBS += -L<C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\x64\Debug\Protocol.lib> -lProtocolCom

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/release/ -lProtocolCom
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/debug/ -lProtocolCom
else:unix: LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/ -lProtocolCom

INCLUDEPATH += C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\ProtocolCom
INCLUDEPATH += C:\Users\Alex\Documents\json-develop\json-develop
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include\nlohmann


win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/libProtocolCom.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/libProtocolCom.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/ProtocolCom.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/ProtocolCom.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/libProtocolCom.a


RESOURCES += \
    Resources.qrc

DISTFILES += \
    ProtocolCom.lib \
    ProtocolCom.lib


HEADERS += \
    loginwindow.h \
    sconnect_to_server.h \
    security_questions_window.h \
    signup_window.h

FORMS += \
    loginwindow.ui \
    security_questions_window.ui \
    signup_window.ui


LIBS += -L<C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\x64\Debug\Protocol.lib> -lProtocolCom

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/release/ -lProtocolCom
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/debug/ -lProtocolCom
else:unix: LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/ -lProtocolCom

INCLUDEPATH += C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\ProtocolCom
INCLUDEPATH += C:\Users\Alex\Documents\json-develop\json-develop
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include\nlohmann

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/libProtocolCom.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/libProtocolCom.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/ProtocolCom.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/ProtocolCom.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/libProtocolCom.a


RESOURCES += \
    Resources.qrc

DISTFILES +=


SOURCES += \
    loginwindow.cpp \
    main.cpp \
    sconnect_to_server.cpp \
    security_questions_window.cpp \
    signup_window.cpp

HEADERS += \
    loginwindow.h \
    sconnect_to_server.h \
    sconnect_to_server.h \
    security_questions_window.h \
    signup_window.h

FORMS += \
    loginwindow.ui \
    security_questions_window.ui \
    signup_window.ui


LIBS += -L<C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\x64\Debug\Protocol.lib> -lProtocolCom

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/release/ -lProtocolCom
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/debug/ -lProtocolCom
else:unix: LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/ -lProtocolCom

INCLUDEPATH += C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\ProtocolCom
INCLUDEPATH += C:\Users\Alex\Documents\json-develop\json-develop
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include\nlohmann

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/libProtocolCom.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/libProtocolCom.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/ProtocolCom.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/ProtocolCom.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/libProtocolCom.a


RESOURCES += \
    Resources.qrc

DISTFILES +=


HEADERS += \
    loginwindow.h \
    sconnect_to_server.h \
    security_questions_window.h \
    signup_window.h

FORMS += \
    loginwindow.ui \
    security_questions_window.ui \
    signup_window.ui


LIBS += -L<C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\x64\Debug\Protocol.lib> -lProtocolCom

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/release/ -lProtocolCom
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/debug/ -lProtocolCom
else:unix: LIBS += -L$$PWD/../ProtocolCom/ProtocolCom/x64/ -lProtocolCom

INCLUDEPATH += C:\Users\Alex\Documents\ProtocolCom\ProtocolCom\ProtocolCom
INCLUDEPATH += C:\Users\Alex\Documents\json-develop\json-develop
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include
INCLUDEPATH +=C:\Users\Alex\Documents\json-develop\json-develop\include\nlohmann

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/libProtocolCom.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/libProtocolCom.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/release/ProtocolCom.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/debug/ProtocolCom.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ProtocolCom/ProtocolCom/x64/libProtocolCom.a


RESOURCES += \
    Resources.qrc

DISTFILES +=
