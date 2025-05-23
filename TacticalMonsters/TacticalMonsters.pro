QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agent.cpp \
    gallery_page.cpp \
    hexa.cpp \
    inrangesystem.cpp \
    main.cpp \
    menu_page.cpp \
    play_page.cpp \
    welcome_page.cpp

HEADERS += \
    agent.h \
    gallery_page.h \
    hexa.h \
    inrangesystem.h \
    menu_page.h \
    play_page.h \
    welcome_page.h

FORMS += \
    gallery_page.ui \
    menu_page.ui \
    play_page.ui \
    welcome_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image/hexa_images.qrc \
    txt_files/txt_files.qrc
