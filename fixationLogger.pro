greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000

TARGET = fixationLogger
TEMPLATE = app

INCLUDEPATH += \
    $$PWD/src/main \
    $$PWD/src/main/ \
    $$PWD/src/main/player \
    $$PWD/src/main/ui \
    $$PWD/src/main/pics \
    $$PWD/src/external \

SOURCES += \
    src/main/main.cpp \
    src/main/player/player.cpp \
    src/main/ui/MainWindow.cpp \
    src/main/ui/featuredialog.cpp \
    src/main/ui/resultsdialog.cpp \
    src/external/qcustomplot.cpp

HEADERS += \
    src/main/player/player.h \
    src/main/ui/MainWindow.h \
    src/main/ui/featuredialog.h \
    src/main/ui/resultsdialog.h \
    src/external/qcustomplot.h

FORMS += \
    src/main/ui/MainWindow.ui \
    src/main/ui/featuredialog.ui \
    src/main/ui/resultsdialog.ui

LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui

UI_DIR=ui_h
OBJECTS_DIR=.obj
MOC_DIR=.moc
