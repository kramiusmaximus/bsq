/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:51:02 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 16:18:29 by qrigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int		check_square(t_list *map_item, int size, struct coords start)
{
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

void	answer_map(t_list *map_item, int size, struct coords start)
{
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

void	search_square(t_list *map_item, struct coords start)
{
	int sq_size;
	int *map_size;

	map_size = map_item->size;
	sq_size = (map_size[0] < map_size[1]) ? map_size[0] : map_size[1];
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

void	search_from_low(t_list *map_item, struct coords start)
{
	int		sq_size;
	int		*map_size;

	map_size = map_item->size;
	sq_size = (map_size[0] < map_size[1]) ? map_size[0] : map_size[1];
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

void	print_map(t_list *map_item)
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
