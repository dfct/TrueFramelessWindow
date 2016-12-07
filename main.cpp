#include <QApplication>

#ifdef _WIN32
#include "QWinWidget.h"
#else
#include "Widget.h"
#endif

#ifdef __APPLE__
#include "OSXHideTitleBar.h"
#endif

int main(int argc, char *argv[])
{    
    //This has the app draw at HiDPI scaling on HiDPI displays, usually two pixels for every one logical pixel
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //This has QPixmap images use the @2x images when available
    //See this bug for more details on how to get this right: https://bugreports.qt.io/browse/QTBUG-44486#comment-327410
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);



    QApplication app(argc, argv);



    //A common feature is to save your app's geometry on close such that you can draw in the same place on relaunch
    //Thus this project supports specifying the X/Y/Width/Height in a cross-platform manner
    int windowXPos, windowYPos, windowWidth, windowHeight;
    windowXPos = 100;
    windowYPos = 100;
    windowWidth = 1024;
    windowHeight = 768;


#ifdef _WIN32

    //On Windows, the widget needs to be encapsulated in a native window for frameless rendering
    //In this case, QWinWidget #includes "Widget.h", creates it, and adds it to a layout
    QWinWidget w;

#else

    //On OS X / Linux, the widget can handle everything itself so just create Widget as normal
    Widget w;

#endif

#ifdef __APPLE__

    //Then, hide the OS X title bar
    OSXHideTitleBar::HideTitleBar(w.winId());

#endif

    w.setGeometry(windowXPos, windowYPos, windowWidth, windowHeight);

    w.show();
    return app.exec();
}
