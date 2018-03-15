#include "CommandAnalyser.h"
#include <qlist.h>

CommandAnalyser::CommandAnalyser() {

}

CommandAnalyser::CommandAnalyser(QString input) {
	this->input = input;
}

CommandAnalyser::~CommandAnalyser() {

}

Command CommandAnalyser::Analyse() {
	// Carl: analyse if the input is a command or not;

	// Carl: remove blank characters on left and right, while remove continuous bland characters inside;
	input = input.simplified();

	QStringList inputWords = input.split(QRegExp(" "));
	
	if (Command::dicPredicate.indexOf(inputWords.at(0)) < Command::dicPredicate.size()) {
		// Carl: predicate can be found
	}
	

	return command;
}
