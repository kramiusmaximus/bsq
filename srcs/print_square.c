#include "unistd.h"
// Координаты начальной точки поиска квадрата
struct coords
{
    int x;
    int y;
};
// Проверка на препятсвия на предполагаемой области квадрата
int check_square(char **map, int size, struct coords start) {
    int x;
    int y;

    x = start.x;
    y = start.y;
    while (y < size)
    {
        while (x < size)
        {
            if (map[y][x] == '1')
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

    x = start.x;
    y = start.y;
    while (y < size)
    {
        while (x < size)
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
    int big_side;
    int temp;

    struct coords start;
    start.x = 0;
    start.y = 0;

    sq_size = (map_size[0] < map_size[1]) ?  map_size[0] : map_size[1];
    big_side = (map_size[0] < map_size[1]) ? map_size[1] : map_size[0];

    while (check_square(map, sq_size, start) == 1)
    {
        temp = 0;
        while (check_square(map, sq_size, start) == 1)
        {
            if ((start.x + sq_size) < big_side)
                start.x++;
            else if ((start.y + sq_size) < big_side)
                start.y++;
                start.x = temp;
        }
        sq_size--;
    }
    if (check_square(map, sq_size, start) == 0)
        return (answer_map(map, sq_size, start));
    return (map);
}
// Печатает карту-ответ
void print_map(char **map, int x_len, int y_len)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y <= y_len)
    {
        while (x <= x_len)
        {
            write(1, &map[y][x], 1);
            x++;
        }
        write(1, "/n", 1);
        y++;
    }
}
// Предполагаю, что map - это карта в структуре из 0 и 1, где 1 - это препятствие
// Также что map_size - это массив с размерами карт. map_size[0] - у (вертикаль), map_size[1] - х (горизонталь)
int main(){
    print_map(search_square(map, map_size), map_size[1], map_size[0]);
    return (0);
}