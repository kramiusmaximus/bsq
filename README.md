# bsq

Using a terminal from within the BSQ folder:

1. create the executable by using the Makefile (run the command "make")
2. generate a map filled with obstacles using the "mapGenerator" perl program (running the command "perl mapGenerator 18 18 9 > map" will generate a map that's 18x18 in size with an obstacle density of 9 and save it in a file called "map"). Note: maps generated with this generator use the following legend:
'.' - empty tile
'o' - obstacle
'x' - square tile
3. run the command "./bsq map"

For instance if the "map" file contains:

18.ox
.o......o..oo.o.o.
....o...o.oo.....o
o..o.....o.....ooo
.oo...............
o..o..........o...
............o.....
....o..oo....o.o..
..o..oo..o........
.o.......o....ooo.
...o..o....o.o..o.
..oo...o.....o..oo
oo......o....o...o
...o....oo..oo....
.oo..............o
o......o.o...o.o.o
........oo...o....
..o....o.......o..
.........oooo.....

then bsq should output:

![Screen shot]

(https://github.com/kramiusmaximus/bsq/blob/master/Screenshot%202020-09-28%20at%2014.21.45.png?raw=true)
