#include "MeshSubdivision_Debug.h"
#include <QtGui>

bool MeshSubdivision_Debug::eventFilter(QObject *object, QEvent *e) {
	// Carl: eventfilter to deal with different events

	if (e->type() == QEvent::KeyPress) {
		// Carl: key events

		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
		QTextCursor cursor;

		if (keyEvent->key() == Qt::Key_Return) {
			// Carl: enter key events
			QString input = ui.textEdit_cmd->toPlainText().right(ui.textEdit_cmd->toPlainText().size() - textEditRecordLenth);
			OutputTextEditFinished("");
			if (input.size()) {
				// deal with the command;
				commandAnalyser = new CommandAnalyser(input);
				commandProcessor->SetCommand(commandAnalyser->Analyse());
				commandProcessor->start();

				//commandProcessor->wait();
			}

			ui.textEdit_cmd->setTextColor(QColor("white"));
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
					cursor = ui.textEdit_cmd->textCursor();
					cursor.setPosition(ui.textEdit_cmd->textCursor().selectionEnd());
					ui.textEdit_cmd->setTextCursor(cursor);

					// Carl: delete the selected text that is from input instruction
					while (ui.textEdit_cmd->textCursor().position() > textEditRecordLenth)	ui.textEdit_cmd->textCursor().deletePreviousChar();

					ui.textEdit_cmd->setTextColor(QColor("white"));
					return true;
				}
			}
			else {
				// Carl: there isn't any selected text
				if (ui.textEdit_cmd->textCursor().position() > textEditRecordLenth)
					return false;
				else {
					ui.textEdit_cmd->setTextColor(QColor("white"));
					return true;
				}
			}
		}
		else if (keyEvent->key() == Qt::Key_Delete) {
			// Carl: delete key events

			if (ui.textEdit_cmd->textCursor().hasSelection()) {
				// Carl: if there is a selected text
				if (ui.textEdit_cmd->textCursor().selectionStart() >= textEditRecordLenth)
					return false;
				else if (ui.textEdit_cmd->textCursor().selectionEnd() <= textEditRecordLenth)
					return true;
				else {
					cursor = ui.textEdit_cmd->textCursor();
					cursor.setPosition(ui.textEdit_cmd->textCursor().selectionEnd());
					ui.textEdit_cmd->setTextCursor(cursor);

					// Carl: delete the selected text that is from input instruction
					while (ui.textEdit_cmd->textCursor().position() > textEditRecordLenth)	ui.textEdit_cmd->textCursor().deletePreviousChar();

					ui.textEdit_cmd->setTextColor(QColor("white"));
					return true;
				}
			}
			else {
				// Carl: there isn't any selected text
				if (ui.textEdit_cmd->textCursor().position() >= textEditRecordLenth)
					return false;
				else {
					ui.textEdit_cmd->setTextColor(QColor("white"));
					return true;
				}
			}
		}
		else {
			// Carl: other keys

			if (ui.textEdit_cmd->textCursor().hasSelection()) {
				// Carl: if there is a selected text
				if (ui.textEdit_cmd->textCursor().selectionStart() >= textEditRecordLenth) {

					ui.textEdit_cmd->setTextColor(QColor("white")); 
					return false;

				}
				else if (ui.textEdit_cmd->textCursor().selectionEnd() <= textEditRecordLenth) {
					cursor = ui.textEdit_cmd->textCursor();
					cursor.movePosition(QTextCursor::End);
					ui.textEdit_cmd->setTextCursor(cursor);

					ui.textEdit_cmd->setTextColor(QColor("white"));
					return false;
				}
				else {
					cursor = ui.textEdit_cmd->textCursor();
					cursor.setPosition(ui.textEdit_cmd->textCursor().selectionEnd());
					ui.textEdit_cmd->setTextCursor(cursor);

					// Carl: delete the selected text that is from input instruction
					while (ui.textEdit_cmd->textCursor().position() > textEditRecordLenth)	ui.textEdit_cmd->textCursor().deletePreviousChar();

					ui.textEdit_cmd->setTextColor(QColor("white"));
					return false;
				}
			}
			else {
				// Carl: there isn't any selected text
				if (ui.textEdit_cmd->textCursor().position() < textEditRecordLenth) {
					cursor = ui.textEdit_cmd->textCursor();
					cursor.movePosition(QTextCursor::End);
					ui.textEdit_cmd->setTextCursor(cursor);

				}
				ui.textEdit_cmd->setTextColor(QColor("white"));
				return false;
			}
		}

	}
	
	return false;
}