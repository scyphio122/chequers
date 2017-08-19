#-------------------------------------------------
#
# Project created by QtCreator 2017-08-05T12:53:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chequers
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=  Game_Src\
                GUI_Forms\
                Network_Src\
                Utils

SOURCES += main.cpp\
        GUI_Forms/mainwindow.cpp\
        GUI_Forms/loginform.cpp\
        GUI_Forms/registeruserform.cpp\
        GUI_Forms/serverconnectform.cpp\
        GUI_Forms/gamerequestpopup.cpp\
        Network_Src/webmanager.cpp\
        Game_Src/webprotocolframe.cpp\
        Game_Src/game.cpp\
        Game_Src/protocolframeparser.cpp\
        Game_Src/player.cpp\
        Utils/logger.cpp\
        Utils/lock.cpp

HEADERS  +=  GUI_Forms/mainwindow.h\
        GUI_Forms/loginform.h\
        GUI_Forms/registeruserform.h\
        GUI_Forms/serverconnectform.h\
        GUI_Forms/gamerequestpopup.h\
        Network_Src/webmanager.h\
        Game_Src/webprotocolframe.h\
        Game_Src/game.h\
        Game_Src/protocolframeparser.h\
        Game_Src/player.h\
        Utils/logger.h\
        Utils/lock.h

FORMS    +=  GUI_Forms/mainwindow.ui\
    GUI_Forms/loginform.ui\
    GUI_Forms/registeruserform.ui\
    GUI_Forms/gamerequestpopup.ui\
    GUI_Forms/serverconnectform.ui
