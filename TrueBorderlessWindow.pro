#-------------------------------------------------
#
# TrueBorderlessWindow.pro
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrueBorderlessWindow
TEMPLATE = app

SOURCES += main.cpp\
    widget.cpp

HEADERS  += widget.h

win32 {
    # Only include / compile these files on Windows
    SOURCES += \
        qwinwidget.cpp \
        winnativewindow.cpp

    HEADERS += \
        qwinwidget.h \
        winnativewindow.h

    LIBS += -L"C:\Program Files\Microsoft SDKs\Windows\v7.1\Lib" \
        -ldwmapi \
        -lgdi32
}

mac {
    # Only include / compile these files on OS X
    OBJECTIVE_SOURCES += \
        OSXHideTitleBar.mm
    HEADERS  +=\
        OSXHideTitleBar.h

    # Additionally include Cocoa for OS X code

    LIBS += -framework Foundation -framework Cocoa
    INCLUDEPATH += /System/Library/Frameworks/Foundation.framework/Versions/C/Headers
}
