#include "MainWindow.h"
#include "QApplication"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	resize(800, 600);
	setWindowTitle("MyIDE");

	createMenuBar();
}

void MainWindow::createMenuBar() {

	QMenuBar *mainMenu = this->menuBar();

	QMenu *filemenu = mainMenu->addMenu("File");
	QMenu *editmenu = mainMenu->addMenu("Edit");
	QMenu *viewmenu = mainMenu->addMenu("View");
	QMenu *projectmenu = mainMenu->addMenu("Project");
	QMenu *gitmenu = mainMenu->addMenu("Git");
	QMenu *optionsmenu = mainMenu->addMenu("Settings");
	QMenu *helpmenu = mainMenu->addMenu("Help");

	QAction *newFileAction = new QAction("New file", this);

	QAction *openProjectAction = new QAction("Open project", this);

	QAction *exitAction = new QAction("Exit", this);

	filemenu->addAction(newFileAction);
	filemenu->addAction(openProjectAction);
	filemenu->addAction(exitAction);

	QAction *aboutMenuAction = new QAction("About");
	helpmenu->addAction(aboutMenuAction);

	connect(newFileAction, &QAction::triggered, this, &MainWindow::onNewFileTriggered);
	connect(exitAction, &QAction::triggered, this, &MainWindow::onExitTriggered);

}

void MainWindow::onNewFileTriggered() {
	qDebug() << "New project!";
}
void MainWindow::onExitTriggered() {
	qApp->quit();
}
