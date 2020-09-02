/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:45 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 13:31:48 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int			ft_process_header(char *buff, char *symbols, int *size, int len)
{
	char	numstring[len];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (len < 4)
		return (-1);
	while (ft_isnumb(buff[i]) && i < len - 3)
		numstring[k++] = buff[i++];
	numstring[k] = '\0';
	while (i < len && j < 3)
		symbols[j++] = buff[i++];
	if (buff[i] != '\n')
		return (-1);
	if (!ft_valid_symbols(symbols))
		return (-1);
	if ((size[0] = ft_atoi(numstring)) == 0)
		return (-1);
	size[1] = 0;
	return (1);
}

int			ft_loop(char *buff, char ***map, char *symbols, int *size)
{
	int y;
	int x;

	y = 0;
	while (*buff)
	{
		(*map)[y] = (char *)malloc(sizeof(char) * size[1]);
		x = 0;
		while (*buff && *buff != '\n' && x < size[1])
		{
			if (!ft_valid_char(*buff, symbols))
				return (-1);
			(*map)[y][x++] = *buff++;
		}
		if (x != size[1])
			return (-1);
		if (*buff)
			buff++;
		y++;
	}
	if (y != size[0])
		return (-1);
	return (1);
}

t_list		*ft_process_buff(char *buff)
{
	int		i;
	int		size[2];
	char	symbols[3];
	char	**map;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if ((ft_process_header(buff, symbols, size, i)) < 0)
		return (ft_create_elem(NULL, NULL, NULL));
	if ((ft_process_body(buff, symbols, size, &map)) < 0)
		return (ft_create_elem(NULL, NULL, NULL));
	return (ft_create_elem(map, symbols, size));
}

t_list		*ft_read_file(char *filename, int file_size)
{
	char	buff[file_size + 1];
	int		desc;
	int		nread;

	if ((desc = open(filename, O_RDONLY)) < 0)
		return (ft_create_elem(NULL, NULL, NULL));
	if ((nread = read(desc, buff, file_size)) <= 0)
		return (ft_create_elem(NULL, NULL, NULL));
	if (nread == -1)
		return (ft_create_elem(NULL, NULL, NULL));
	if ((desc = close(desc)) == -1)
		return (ft_create_elem(NULL, NULL, NULL));
	buff[file_size] = '\0';
	return (ft_process_buff(buff));
}

t_list		*ft_parse_arguments(int n_maps, char **filenames)
{
	int		i;
	t_list	*maps_list;

	maps_list = NULL;
	i = 0;
	while (i < n_maps)
	{
		ft_add_back(&maps_list,
				ft_read_file(filenames[i], ft_file_size(filenames[i])));
		i++;
	}
	return (maps_list);
}
