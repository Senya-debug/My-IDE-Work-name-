#pragma once

#include <QPlainTextEdit>
#include <QWidget>
#include <QColor>
#include <QTextBlock>
#include <QPainter>

class CodeEditor : public QPlainTextEdit{
	Q_OBJECT

public:
	explicit CodeEditor(QWidget *parent = nullptr);
	~CodeEditor() = default;

	void lineNumberAreaPaintEvent(QPaintEvent *event);
	void setFilePath(const QString &file) { m_filePath = file; }
	void setModifed(bool modifed) { editedAfterSave = modifed; }
	
	QString getFilePath() { return m_filePath; }

	int lineNumberAreaWidth();

	bool getModifed() { return editedAfterSave; }

protected:
	void resizeEvent(QResizeEvent *event);

private slots:
	void updateLineNumberAreaWidth(int newBlockCount);
	void highlightCurrentLine();
	void updateLineNumberArea(const QRect &, int);

	void setmodifedfile();

private:
	QWidget *lineNumberArea;
	QString m_filePath;
	bool editedAfterSave = false;
};

class LineNumberArea : public QWidget{
public:
	LineNumberArea(CodeEditor *editor) : QWidget(editor){
		codeEditor = editor;
	}
	QSize sizeHint() const {
		return QSize(codeEditor->lineNumberAreaWidth(), 0);
	}
protected:
	void paintEvent(QPaintEvent *event){
		codeEditor->lineNumberAreaPaintEvent(event);
	}
private:
	CodeEditor *codeEditor;
};
