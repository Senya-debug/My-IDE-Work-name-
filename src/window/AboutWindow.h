#pragma once

#include <QWidget>

namespace Ui { class AboutMenu; }

class AboutWindow : public QWidget {
	Q_OBJECT
public:
		explicit AboutWindow(QWidget *parent = nullptr);
		~AboutWindow();
private:
		Ui::AboutMenu *ui;
};
