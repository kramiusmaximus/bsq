#ifndef UNTITLED_PRINT_SQUARE_H
#define UNTITLED_PRINT_SQUARE_H

#include "unistd.h"
#include "stdlib.h"

struct coords
{
    int x;
    int y;
};

int check_square(char **map, int size, struct coords start);
char **answer_map(char **map, int size, struct coords start);
char **search_square(char **map,int *map_size);
void print_map(char **map, int *map_size);

#endif
