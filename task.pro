TEMPLATE = app
SOURCES += main.cpp MyWindow.cpp
contains(QT_VERSION, ^5.*) {
 QT +=  widgets
}
HEADERS += MyWindow.h
