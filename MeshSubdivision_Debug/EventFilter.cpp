#include "MeshSubdivision_Debug.h"
#include <QtGui>

bool MeshSubdivision_Debug::eventFilter(QObject *object, QEvent *e) {
	// Carl: eventfilter to deal with different events

	if (e->type() == QEvent::KeyPress) {
		// Carl: key events

		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
	}

	return false;
}