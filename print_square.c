
#include "print_square.h"
// Проверка на препятсвия на предполагаемой области квадрата
int check_square(char **map, int size, struct coords start){
    int x;
    int y;

    y = start.y;
    while (y < (size + start.y))
    {
        x = start.x;
        while (x < (size + start.x))
        {
            if (map[y][x] != '0')
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}
// Нанесение квадрата(ответ) на карту
char **answer_map(char **map, int size, struct coords start) {
    int x;
    int y;

    y = start.y;
    while (y < (size + start.y))
    {
        x = start.x;
        while (x < (size + start.x))
        {
            map[y][x] = 'X';
            x++;
        }
        y++;
    }
    return (map);
}
// Ищет область для квадрата
char  **search_square(char **map,int *map_size)
{
    int sq_size;
    struct coords start;

    start.x = 0;
    start.y = 0;
    sq_size = (map_size[0] < map_size[1]) ?  map_size[0] : map_size[1];
    while (check_square(map, sq_size, start) != 0)
    {
        if ((start.x + sq_size) < map_size[1])
            start.x++;
        else if ((start.y + sq_size) < map_size[0])
        {
            start.y++;
            start.x = 0;
        }
        else
        {
            sq_size--;
            if (sq_size == 0)
                return (NULL);
            start.x = 0;
            start.y = 0;
        }
    }
    if (check_square(map, sq_size, start) == 0)
        return (answer_map(map, sq_size, start));
    return (NULL);
}
// Печатает карту-ответ
void print_map(char **map, int *map_size)
{
    int x;
    int y;

    y = 0;
    while (y <= map_size[0])
    {
        x = 0;
        while (x <= map_size[1])
        {
            write(1, &map[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
}
// Предполагаю, что map - это карта в структуре из 0 и 1, где 1 - это препятствие
// Также что map_size - это массив с размерами карт. map_size[0] - у (вертикаль), map_size[1] - х (горизонталь)