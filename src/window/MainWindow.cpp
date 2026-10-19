#include "MainWindow.h"
#include "AboutWindow.h"


#include <QApplication>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	resize(800, 600);
	setWindowTitle("MyIDE");

	m_newFileAction = new QAction("New file", this);
	m_openProjectAction = new QAction("Open project", this);
	m_exitAction = new QAction("Exit", this);

	m_runProjectAction = new QAction("Run", this);
	m_debugProjectAction = new QAction("Debug", this);


	m_aboutMenuAction = new QAction("About");

	connect(m_newFileAction, &QAction::triggered, this, &MainWindow::onNewFileTriggered);
	connect(m_exitAction, &QAction::triggered, this, &MainWindow::onExitTriggered);
	connect(m_aboutMenuAction, &QAction::triggered, this, &MainWindow::onAboutMenuTriggered);

	createToolBar();
	createMenuBar();
	createStatusBar();

	createFileTreeDock();
	createWorkspaceDock();
	createConsoleDock();
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

	filemenu->addAction(m_newFileAction);
	filemenu->addAction(m_openProjectAction);
	filemenu->addAction(m_exitAction);

	projectmenu->addAction(m_runProjectAction);
	projectmenu->addAction(m_debugProjectAction);

	helpmenu->addAction(m_aboutMenuAction);

}

void MainWindow::createToolBar(){

	QToolBar *mainbar = new QToolBar(this);
	this->addToolBar(mainbar);

	mainbar->addAction(m_newFileAction);
	mainbar->addAction(m_openProjectAction);

	mainbar->addAction(m_runProjectAction);
	mainbar->addAction(m_debugProjectAction);

}
void MainWindow::createStatusBar(){

	QStatusBar *statusbar = new QStatusBar(this);
	this->setStatusBar(statusbar);
	statusbar->showMessage(tr("Hello"));
}

void MainWindow::createFileTreeDock(){

	QDockWidget *filetreedock = new QDockWidget("File tree", this);
    filetreedock->setDockLocation(Qt::DockWidgetArea::LeftDockWidgetArea);


}

void MainWindow::createWorkspaceDock(){

	QDockWidget *workspacedock = new QDockWidget("Test", this);
    workspacedock->setDockLocation(Qt::DockWidgetArea::RightDockWidgetArea);

}

void MainWindow::createConsoleDock(){

	QDockWidget *cosnoledock = new QDockWidget("Console", this);
 	cosnoledock->setDockLocation(Qt::DockWidgetArea::BottomDockWidgetArea);

}
void MainWindow::onNewFileTriggered() {
	qDebug() << "New project!";
}

void MainWindow::onExitTriggered() {
	qApp->quit();
}

void MainWindow::onAboutMenuTriggered(){
	if(!m_aboutwindow){
		m_aboutwindow = new AboutWindow(this);
	}

	m_aboutwindow->show();
	m_aboutwindow->activateWindow();




}
