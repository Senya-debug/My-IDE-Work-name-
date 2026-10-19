#include "AboutWindow.h"
#include "ui_AboutWindow.h"

AboutWindow::AboutWindow(QWidget *parent) : QWidget(parent), ui(new Ui::AboutMenu){
	setWindowFlags(Qt::Window);

	ui->setupUi(this);
}

AboutWindow::~AboutWindow() {
	delete ui;
}
