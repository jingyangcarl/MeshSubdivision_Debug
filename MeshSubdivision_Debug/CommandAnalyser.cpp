#include "CommandAnalyser.h"
#include <qlist.h>

CommandAnalyser::CommandAnalyser() {

}

CommandAnalyser::CommandAnalyser(QString input) {
	this->input = input;
}

CommandAnalyser::~CommandAnalyser() {

}

void CommandAnalyser::SetInput(QString input) {
	this->input = input;
}

Command CommandAnalyser::Analyse() {
	// Carl: analyse if the input is a command or not;

	// Carl: remove blank characters on left and right, while remove continuous bland characters inside;
	input = input.simplified();

	QStringList inputWords = input.split(QRegExp(" "));
	
	// Carl: PREDICATE
	if (inputWords.size() >= 1 && Command::dicPredicate.indexOf(inputWords.at(0)) < Command::dicPredicate.size()) {
		// Carl: predicate can be found
		command.predicate = inputWords.at(0);
	}
	else {
		command.predicate = "show";
		command.object = "error";
		command.complement = "No such instruction, please check your input;";

		return command;
	}

	// Carl: OBJECT and COMPLEMENT
	if (inputWords.size() >= 3 && Command::dicObject.indexOf(inputWords.at(1) + " " + inputWords.at(2)) != -1) {
		// Carl: object with two words
		command.object = inputWords.at(1) + " " + inputWords.at(2);
		for (QStringList::Iterator iter = inputWords.begin() + 3; iter != inputWords.end(); iter++)
			command.complement += *iter + " ";
	}
	else if (inputWords.size() >= 2 && Command::dicObject.indexOf(inputWords.at(1)) != -1) {
		// Carl: object with one word
		command.object = inputWords.at(1);
		for (QStringList::Iterator iter = inputWords.begin() + 2; iter != inputWords.end(); iter++)
			command.complement += *iter + " ";
	}
	else {
		command.complement = "No such instruction, please check your input after " + command.predicate;
		command.predicate = "show";
		command.object = "error";

		return command;
	}
	
	return command;
}
