/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:51:02 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 15:17:19 by qrigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

// Проверка на препятсвия на предполагаемой области квадрата
int check_square(t_list *map_item, int size, struct coords start){
    int x;
    int y;

    y = start.y;
    while (y < (size + start.y))
    {
        x = start.x;
        while (x < (size + start.x))
        {
            if (map_item->map[y][x] != map_item->symbols[0])
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}
// Нанесение квадрата(ответ) на карту
void answer_map(t_list *map_item, int size, struct coords start) {
    int x;
    int y;

    y = start.y;
    while (y < (size + start.y))
    {
        x = start.x;
        while (x < (size + start.x))
        {
            map_item->map[y][x] = map_item->symbols[2];
            x++;
        }
        y++;
    }
}
// Ищет область для квадрата
void search_square(t_list *map_item)
{
    int sq_size;
    struct coords start;
	int *map_size;

	map_size = map_item->size;
    start.x = 0;
    start.y = 0;
    sq_size = (map_size[0] < map_size[1]) ?  map_size[0] : map_size[1];
    while (check_square(map_item, sq_size, start) != 0)
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
                break ;
            start.x = 0;
            start.y = 0;
        }
    }
    if (check_square(map_item, sq_size, start) == 0)
        answer_map(map_item, sq_size, start);
}
// Печатает карту-ответ
void print_map(t_list *map_item)
{
    int x;
    int y;
	
	if (!(map_item->map))
	{
		ft_putstr("map error\n");
		return ;
	}
    y = 0;
    while (y < map_item->size[0])
    {
        x = 0;
        while (x < map_item->size[1])
        {
            write(1, &map_item->map[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
}
// Предполагаю, что map - это карта в структуре из 0 и 1, где 1 - это препятствие
// Также что map_size - это массив с размерами карт. map_size[0] - у (вертикаль), map_size[1] - х (горизонталь)
