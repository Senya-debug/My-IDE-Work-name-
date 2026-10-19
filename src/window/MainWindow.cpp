#include "MainWindow.h"
#include "AboutWindow.h"

#include "../core/File.h"

#include <QApplication>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	resize(800, 600);
	setWindowTitle("MyIDE");

	m_newFileAction = new QAction("New file", this);
	m_saveProjectAction = new QAction("Save project", this);
	m_openProjectAction = new QAction("Open project", this);
	m_exitAction = new QAction("Exit", this);

	m_runProjectAction = new QAction("Run", this);
	m_debugProjectAction = new QAction("Debug", this);


	m_aboutMenuAction = new QAction("About");

	connect(m_newFileAction, &QAction::triggered, this, &MainWindow::onNewFileTriggered);
//	connect(m_saveProjectAction, &QAction::triggered, this, &MainWindow::onNewFileTriggered);
	connect(m_openProjectAction, &QAction::triggered, this, &MainWindow::onOpenFileTriggered);
	connect(m_exitAction, &QAction::triggered, this, &MainWindow::onExitTriggered);
	connect(m_aboutMenuAction, &QAction::triggered, this, &MainWindow::onAboutMenuTriggered);

	createToolBar();
	createMenuBar();
	createStatusBar();

	createWorkspaceBar();
	createFileTreeDock();
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
	filemenu->addAction(m_saveProjectAction);
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
	mainbar->addAction(m_saveProjectAction);
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

void MainWindow::createWorkspaceBar(){

	m_tabwidget = new QTabWidget(this);

	m_tabwidget->setTabsClosable(true);
	m_tabwidget->setMovable(true);
	m_tabwidget->setDocumentMode(true);

	this->setCentralWidget(m_tabwidget);
	connect(m_tabwidget, &QTabWidget::tabCloseRequested, this, &MainWindow::onCloseTabTriggered );

}

void MainWindow::onCloseTabTriggered(int index){

	QWidget *w = m_tabwidget->widget(index);

	m_tabwidget->removeTab(index);

	delete w;
}

void MainWindow::createConsoleDock(){

	QDockWidget *cosnoledock = new QDockWidget("Console", this);
 	cosnoledock->setDockLocation(Qt::DockWidgetArea::BottomDockWidgetArea);

}

void MainWindow::onOpenFileTriggered(){
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "/home", tr("C++ files (*.cpp *.h *.hpp *.cc)"));

	QString openedfile = loadfile(fileName);
	QPlainTextEdit *texteditor = new QPlainTextEdit(m_tabwidget);
	int index = m_tabwidget->addTab(texteditor, fileName);
	texteditor->setPlainText(openedfile);
}

void MainWindow::onSaveProjectTriggered(){
	}

void MainWindow::onNewFileTriggered() {
	QPlainTextEdit *texteditor = new QPlainTextEdit(m_tabwidget);
	int index = m_tabwidget->addTab(texteditor, "untitled");
	QFont font("Monospace", 20);
	texteditor->setFont(font);
	m_tabwidget->setCurrentIndex(index);
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
