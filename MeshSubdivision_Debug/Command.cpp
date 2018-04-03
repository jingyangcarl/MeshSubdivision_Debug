#include"Command.h"

// Carl: Predicate can have only one word;
QStringList Command::dicPredicate = {"change", "clear", "detect", "load", "show" , "subdivide" };

// Carl: Object can have one or two words;
QStringList Command::dicObject = { "butterfly", "catmull", "cloud" , "cloud status", "efp", "feature", "help", "keypoint", "layout", "loop", "mesh", "mesh status", "setup", "sqrt3", "sqrt3lgt", "status"};
// Carl: Complement is used for parameters;
QStringList Command::dicComplement = { "" };

// change layout [1/2/4/6]
// clear cloud [1/2/3/4/5/6]
// clear keypoint [1/2/3/4/5/6]
// clear mesh [1/2/3/4/5/6]
// detect mesh [1/2/3/4/5/6]
// load mesh [1/2/3/4/5/6]
// show cloud [1/2/3/4/5/6]
// show cloud status [1/2/3/4/5/6/all]
// show help [instruction/key/note]
// show keypoint [1/2/3/4/5/6]
// show mesh [1/2/3/4/5/6]
// show mesh status [1/2/3/4/5/6/all]
// subdivide catmull [1/2/3/4/5/6]
// subdivide longedge [1/2/3/4/5/6]
// subdivide loop [1/2/3/4/5/6]
// subdivide butterfly [1/2/3/4/5/6]
// subdivide sqrt3 [1/2/3/4/5/6]
// subdivide sqrt3lgt [1/2/3/4/5/6]
// subdivide efp  [1/2/3/4/5/6]
// subdivide feature [1/2/3/4/5/6]