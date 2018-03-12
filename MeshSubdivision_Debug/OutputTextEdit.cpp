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

	return;
}

void MeshSubdivision_Debug::OutputTextEditProcessing(QString output) {
	// Carl: output processing instructions

}

void MeshSubdivision_Debug::OutputTextEditNotice(QString output) {
	// Carl: output notice instructions

}

void MeshSubdivision_Debug::OutputTextEditWarning(QString output) {
	// Carl: output warning instructions

}

void MeshSubdivision_Debug::OutputTextEditError(QString output) {
	// Carl: output error instructions

}

void MeshSubdivision_Debug::OutputTextEditColoredString(QColor color, QString output) {
	// Carl: output a colored String

}