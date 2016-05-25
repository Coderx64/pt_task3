#include "MyWindow.h"

#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QPoint>

MyWindow::MyWindow() {
	resize(400, 300);

	Label = new QLabel("", this);

	openButton = new QPushButton("My Button", this);
	openButton->setGeometry(QRect(QPoint(50, 10), QSize(100, 25)));
	connect(openButton, SIGNAL(clicked()), this, SLOT(chooseImage()));
}

void MyWindow::chooseImage() {
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
	this->processImage(fileName);
}

void MyWindow::showEvent(QShowEvent *e) {
	
	QMainWindow::showEvent(e);
	windowLoaded();
}

void MyWindow::windowLoaded() {
		
	processImage("resources/2.jpg");
}

void MyWindow::processImage(QString fileName) {

	QMessageBox::information(this, tr("image"), tr("%1").arg(fileName));
	
	if (!fileName.isEmpty()) {
		QImage image(fileName);
		if (image.isNull()) {
			QMessageBox::information(this, tr("image"), tr("Cannot load %1.").arg(fileName));
			return;
		}
		Label->setPixmap(QPixmap::fromImage(image));
	
		Label->resize(Label->pixmap()->size());
		resize(Label->pixmap()->width(), Label->pixmap()->height());
	
		Label->show();
	}
}