#pragma once

#include <qstring>
#include <qstringlist.h>

struct Command {

	// Carl: Command should be organized in a sentence including Predicate, Object, and Complement
	// Carl: Predicate should be a verb such as 'change', 'show', 'load', etc.
	// Carl: Object should be a targect such as 'widget', 'text', etc.
	// Carl: Complement should be the extra information of the object such as '1', '2', 'all'

	QString predicate;
	QString object;
	QString complement;

	static QStringList dicPredicate;
	static QStringList dicObject;
	static QStringList dicComplement;
};