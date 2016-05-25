#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class QLabel;
class QAction;

class MyWindow : public QMainWindow {
	
	Q_OBJECT 

	public:
		explicit MyWindow();
		
	protected:
		void showEvent(QShowEvent *e);	
	
	private slots:
		void chooseImage();
		void windowLoaded();
 
	private:
		QLabel *Label;
		QPushButton *openButton;
		void processImage(QString fileName);
	};

#endif // __MYWINDOW_H__
