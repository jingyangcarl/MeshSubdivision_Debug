#include "MeshSubdivision_Debug.h"
#include <qscrollbar.h>

void MeshSubdivision_Debug::OutputTextEditFinished(QString output) {
	// Carl: output finished instructions

	// Carl: move the cursor the the end of the text edit field
	QTextCursor cursor = ui.textEdit_cmd->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit_cmd->setTextCursor(cursor);

	// Carl: output in gray and update record length
	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText(output);
	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText("\n>> ");
	textEditRecordLenth = ui.textEdit_cmd->toPlainText().size();

	// Carl: set output color back
	ui.textEdit_cmd->setTextColor(QColor("white"));
	return;
}

void MeshSubdivision_Debug::OutputTextEditProcessing(QString output) {
	// Carl: output processing instructions

	// Carl: move the cursor the the end of the text edit field
	QTextCursor cursor = ui.textEdit_cmd->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit_cmd->setTextCursor(cursor);

	// Carl: output in gray and update record length
	ui.textEdit_cmd->setTextColor(QColor("green"));
	ui.textEdit_cmd->textCursor().insertText(output);
	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText("\n>> ");
	textEditRecordLenth = ui.textEdit_cmd->toPlainText().size();

	// Carl: set output color back
	ui.textEdit_cmd->setTextColor(QColor("white"));
	return;
}

void MeshSubdivision_Debug::OutputTextEditNotice(QString output) {
	// Carl: output notice instructions

	// Carl: move the cursor the the end of the text edit field
	QTextCursor cursor = ui.textEdit_cmd->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit_cmd->setTextCursor(cursor);

	// Carl: output in gray and update record length
	ui.textEdit_cmd->setTextColor(QColor("blue"));
	ui.textEdit_cmd->textCursor().insertText(output);
	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText("\n>> ");
	textEditRecordLenth = ui.textEdit_cmd->toPlainText().size();

	// Carl: set output color back
	ui.textEdit_cmd->setTextColor(QColor("white"));
	return;
}

void MeshSubdivision_Debug::OutputTextEditHelp(QString output) {
	// Carl: output warning instructions

	// Carl: move the cursor the the end of the text edit field
	QTextCursor cursor = ui.textEdit_cmd->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit_cmd->setTextCursor(cursor);

	// Carl: output in gray and update record length
	ui.textEdit_cmd->setTextColor(QColor("orange"));
	ui.textEdit_cmd->textCursor().insertText(output);
	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText("\n>> ");
	textEditRecordLenth = ui.textEdit_cmd->toPlainText().size();

	// Carl: set output color back
	ui.textEdit_cmd->setTextColor(QColor("white"));
	return;
}

void MeshSubdivision_Debug::OutputTextEditError(QString output) {
	// Carl: output error instructions

	// Carl: move the cursor the the end of the text edit field
	QTextCursor cursor = ui.textEdit_cmd->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit_cmd->setTextCursor(cursor);

	// Carl: output in gray and update record length
	ui.textEdit_cmd->setTextColor(QColor("red"));
	ui.textEdit_cmd->textCursor().insertText(output);
	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText("\n>> ");
	textEditRecordLenth = ui.textEdit_cmd->toPlainText().size();

	// Carl: set output color back
	ui.textEdit_cmd->setTextColor(QColor("white"));
	return;
}

void MeshSubdivision_Debug::OutputTextEditColoredString(QVector<QPair<QColor, QString>> content) {
	// Carl: output a colored String
	QTextCursor cursor = ui.textEdit_cmd->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit_cmd->setTextCursor(cursor);

	for (QVector<QPair<QColor, QString>>::iterator i = content.begin(); i != content.end(); i++) {
		ui.textEdit_cmd->setTextColor((*i).first);
		ui.textEdit_cmd->textCursor().insertText((*i).second);
	}
	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText("\n>> ");
	textEditRecordLenth = ui.textEdit_cmd->toPlainText().size();

	ui.textEdit_cmd->setTextColor(QColor("white"));
	ui.textEdit_cmd->verticalScrollBar()->setValue(ui.textEdit_cmd->verticalScrollBar()->maximum());

	return;
}