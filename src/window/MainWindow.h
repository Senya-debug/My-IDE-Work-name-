#pragma once
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>

class AboutWindow;

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
		explicit MainWindow(QWidget *parent = nullptr);
		~MainWindow() = default;

private slots:
	void onNewFileTriggered();
	void onExitTriggered();

	void onAboutMenuTriggered();

private:
	void createMenuBar();
	void createToolBar();
	void createStatusBar();

	void createFileTreeDock();
	void createWorkspaceDock();
	void createConsoleDock();

	AboutWindow *m_aboutwindow = nullptr;
private:
	QAction *m_newFileAction = nullptr;
	QAction *m_openProjectAction = nullptr;
	QAction *m_exitAction = nullptr;

	QAction *m_runProjectAction = nullptr;
	QAction *m_debugProjectAction = nullptr;

	QAction *m_aboutMenuAction = nullptr;
};
