#include "MeshSubdivision_Debug.h"
#include <QtGui>

bool MeshSubdivision_Debug::eventFilter(QObject *object, QEvent *e) {
	// Carl: eventfilter to deal with different events

	if (e->type() == QEvent::KeyPress) {
		// Carl: key events

		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);

		if (keyEvent->key() == Qt::Key_Return) {
			// Carl: enter key events
			QString command = ui.textEdit_cmd->toPlainText().right(ui.textEdit_cmd->toPlainText().size() - textEditRecordLenth);


			return true;
		}
		else if (keyEvent->key() == Qt::Key_Backspace) {
			// Carl: backspace key events
			if (ui.textEdit_cmd->textCursor().hasSelection()) {
				// Carl: if there is a selected text
				if (ui.textEdit_cmd->textCursor().selectionStart() >= textEditRecordLenth)
					return false;
				else if (ui.textEdit_cmd->textCursor().selectionEnd() <= textEditRecordLenth)
					return true;
				else {
					QTextCursor cursor = ui.textEdit_cmd->textCursor();
					cursor.setPosition(ui.textEdit_cmd->textCursor().selectionEnd());
					ui.textEdit_cmd->setTextCursor(cursor);

					// Carl: delete the selected text that is from input instruction
					while (ui.textEdit_cmd->textCursor().position() > textEditRecordLenth+1)	ui.textEdit_cmd->textCursor().deletePreviousChar();
				}
			}
			else {
				// Carl: there isn't any selected text
				if (ui.textEdit_cmd->textCursor().position() > textEditRecordLenth)
					return false;
				else
					return true;
			}

		}
	}

	return false;
}