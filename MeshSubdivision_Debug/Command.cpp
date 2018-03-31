#include"Command.h"

// Carl: Predicate can have only one word;
QStringList Command::dicPredicate = {"change", "clear", "detect", "load", "show" , "subdivide" };

// Carl: Object can have one or two words;
QStringList Command::dicObject = { "cloud" , "help", "keypoint" , "layout" , "mesh", "catmull", "loop", "butterfly", "sqrt3", "sqrt3lgt", "efp", "feature"};
// Carl: Complement is used for parameters;
QStringList Command::dicComplement = { "" };

// change layout [1/2/4/6]
// clear cloud [1/2/3/4/5/6]
// clear keypoint [1/2/3/4/5/6]
// clear mesh [1/2/3/4/5/6]
// detect mesh [1/2/3/4/5/6]
// load mesh [1/2/3/4/5/6]
// show cloud [1/2/3/4/5/6]
// show help [instruction/key/note]
// show keypoint [1/2/3/4/5/6]
// show mesh [1/2/3/4/5/6]
// subdivide catmull [1/2/3/4/5/6]
// subdivide longedge [1/2/3/4/5/6]
// subdivide loop [1/2/3/4/5/6]
// subdivide butterfly [1/2/3/4/5/6]
// subdivide sqrt3 [1/2/3/4/5/6]
// subdivide sqrt3lgt [1/2/3/4/5/6]
// subdivide efp  [1/2/3/4/5/6]
// subdivide feature [1/2/3/4/5/6]