/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 22:39:25 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 19:08:02 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int		ft_linelen(char *buff)
{
	int linelen;

	linelen = 0;
	while (*buff && *buff != '\n')
	{
		linelen++;
		buff++;
	}
	return (linelen);
}

int		ft_process_body(char *buff, char *symbols, int *size, char ***map)
{
	while (*buff && *buff != '\n')
		buff++;
	if (!*(buff++ + 1))
		return (-1);
	if ((size[1] = ft_linelen(buff)) == 0)
		return (-1);
	*map = (char **)malloc(sizeof(char *) * size[0]);
	return (ft_loop(buff, map, symbols, size));
}

void	ft_stdin(void)
{
	char			buff[10000];
	t_list			*map_item;
	struct s_coords	start;
	int nread;
	
	start.x = 0;
	start.y = 0;
	nread = read(0, buff, 10000);
	buff[nread] = '\0';
	map_item = ft_process_buff(buff);
	if (map_item->map)
		search_square(map_item, start);
	print_map(map_item);
	ft_emancipate(map_item);
}
