QT       += core gui

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

QT += widgets gui core
QT += charts

SOURCES += \
    main.cpp \
    view.cpp \
    model.cpp \
    ctrl.cpp \
    model/record.cpp \
    model/barchartmodel.cpp \
    model/linechartmodel.cpp \
    model/piechartmodel.cpp \
    model/database.cpp \
    model/editDBmodel.cpp \
    view/homeview.cpp \
    view/howitworksview.cpp \
    view/topbar.cpp \
    view/optimizerview.cpp \
    view/barchartview.cpp \
    view/linechartview.cpp \
    view/piechartview.cpp \
    view/editDBview.cpp \
    view/inputdialog.cpp

HEADERS += \
    view.h \
    model.h \
    ctrl.h \
    model/record.h \
    model/barchartmodel.h \
    model/linechartmodel.h \
    model/piechartmodel.h \
    model/database.h \
    model/editDBmodel.h \
    view/homeview.h \
    view/howitworksview.h \
    view/topbar.h \
    view/optimizerview.h \
    view/barchartview.h \
    view/linechartview.h \
    view/piechartview.h \
    view/editDBview.h \
    view/inputdialog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
