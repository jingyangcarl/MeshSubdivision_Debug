#include"Command.h"

QStringList Command::dicPredicate = { "show", "load", "change", "clear" };

QStringList Command::dicObject = { "text" , "color" , "mesh" , "layout" };

QStringList Command::dicComplement = { "" };

// Command list
/*
load mesh [No.]
show help
show cloud [No.]
show keypoint color [No.]
show mesh status [No.]
show system status
*show error []
*show 
clear text
clear mesh [No.]
clear keypoint color [No.]
change layout [No.]
change cloud color [No.]
change keypoint color [No.]
detect mesh keypoint [No.] [alg.]
subdivide mesh [No.] [alg.]
*/