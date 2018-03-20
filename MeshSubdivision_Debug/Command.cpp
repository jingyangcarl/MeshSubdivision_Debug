#include"Command.h"

// Carl: Predicate can have only one word;
QStringList Command::dicPredicate = { "load", "show", "clear" , "change"};

// Carl: Object can have one or two words;
QStringList Command::dicObject = { "mesh" , "cloud", "keypoint" , "keypoint color" , "text", "layout", "help" };

// Carl: Complement is used for parameters;
QStringList Command::dicComplement = { "" };

// Command list
/*
load mesh [No.]
show help
show help mouse
show help key
show help instruction
show mesh [No.]
show cloud [No.]
show keypoint [No.]
show keypoint color [No.]
show mesh status [No.]
show system status
*show error []
clear text
clear mesh [No.]
clear cloud [No.]
clear keypoint [No.]
clear keypoint color [No.]
change layout [No.]
change cloud color [No.]
change keypoint color [No.]
detect mesh keypoint [No.] [alg.]
subdivide mesh [No.] [alg.]
*/