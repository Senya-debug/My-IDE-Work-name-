#pragma once
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
		explicit MainWindow(QWidget *parent = nullptr);
		~MainWindow() = default;

private slots:
	void onNewFileTriggered();
	void onExitTriggered();

private:
	void createMenuBar();
};
