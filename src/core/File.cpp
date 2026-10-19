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
