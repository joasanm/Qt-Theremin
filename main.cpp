//#include "theremin.h"
#include "ventanaintro.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//theremin w;
	ventanaIntro v;
	v.show();
	return a.exec();
}
