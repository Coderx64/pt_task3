#include <QtGlobal>
#if QT_VERSION < 0x050000
#include <QtGui>
#else
#include <QtWidgets>
#endif

#include "MyWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    MyWindow *widget = new MyWindow;

    widget->show();

    return app.exec();
}
