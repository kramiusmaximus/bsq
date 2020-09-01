#include "print_square.h"

int main() {
    int j;
    char **map = (char **)malloc(sizeof(char *) * 4);
    char rmap[4][5] = {
            {'1', '0','1','0','0'},
            {'1', '0','0','0','0'},
            {'1', '0','0','0','0'},
            {'1', '1','0','0','0'},
    };
    int map_size[2] = {4,5};

    for (int i = 0; i < 4; i++)
    {
        map[i] = (char *) malloc(sizeof(char) * 5);
        for (j = 0; j < 5; j++)
            map[i][j] = rmap[i][j];
    }
    print_map(search_square(map, map_size), map_size);
    return (0);
}
