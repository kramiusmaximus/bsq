# bsq

# Задача
хуярить


# Steps to become god
1. Count number of arguments:
	1. if argc == 1: read from stdin
	2. if argc > 1: process file(s) accordingly
2. For each map argument:
	1. Parse map format (first line must contain info on map \[line\_numb]\[empty\_char]\[obstacle\_char]\[full\_char])
	2. Check if map is valid (1 & 2 done at same time?)
	3. Convert map to array representation (if error then return NULL)
	4. Convert map to array representation with 0's and 1's (0 for empty, 1 for obstacle)
	5. Add both maps to linked list through custom structure. 
3. Now, given a 2D array, or list of 2D arrays which represent each map argument in simple form go through whole square and find the location and size of largest square. (If error don't do anything)
4. Draw that square in each 2D Map Array using correct symbols
5. Print each array out.



Other:
- Should there be no passed arguments, your program must be able to read on the standard input.
- You should have a valid Makefile that’ll compile your project. Your Makefile **mustn’t relink**.
- When your program receives more than one map in argument, each solution or map error must be followed by a line break.
- In the case that more than one solution exists, we’ll choose to represent the square that’s closest to the top of the map, then the one that’s most to the left.

Definition of Valid Map:
- All lines have same length
- There's at least one line of atleast one box.
- At each end of line, there's a line break
- The characters on the map can only be those introduced in first line
- The map is invalid if a character is missing from the first line, or if two charactrs (empty, full, and obstacle characters) are identical.
- Incase of Invalid map, print map error followed by line break.


#Functions

1. Utility Functions:
	- void	ft\_put(char c)
	- 
2. Process Map:
	- 
	- 
3. Process Array of Map:
	- void	ft\_find\_square(char \*\*map\_array, int \*map\_info, int \*square\_info) // Function that takes simple map array, map info ([y size, x size]), and replaces square\_info[0], square\_info[1], square\_infor[2] with y, x, max square size values.
4. df 
