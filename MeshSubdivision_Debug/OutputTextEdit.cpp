#include "MeshSubdivision_Debug.h"

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

void MeshSubdivision_Debug::OutputTextEditWarning(QString output) {
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

void MeshSubdivision_Debug::OutputTextEditColoredString(QColor color, QString output) {
	// Carl: output a colored String

}