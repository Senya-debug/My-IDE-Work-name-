#include <QApplication>
#include <QPushButton>

#include "MainWindow.h"
#include <QDebug>
#include <QtCore/qglobal.h>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	qDebug() << "Qt version:" << QT_VERSION_STR;

	MainWindow mwindow;
	mwindow.show();

	return app.exec();

}
