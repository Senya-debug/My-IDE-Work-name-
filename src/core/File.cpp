#include "File.h"
#include <QTextStream>

QString loadfile(const QString &openfile){
	QFile file(openfile);

	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return "";

	QTextStream in(&file);

	QString filecontent = in.readAll();
	file.close();

	return filecontent;
}

void savefile(QString &savefile, QString &sourcetext, QWidget *parent){
	QFile file(savefile);

	if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return ;

	QTextStream out(&file);
	out << sourcetext << "\n";

	file.close();
	
}
