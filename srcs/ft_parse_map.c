/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:45 by pfelipa           #+#    #+#             */
/*   Updated: 2020/08/31 22:22:33 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_head.h"
#include <stdio.h>


int		ft_file_size(char *filename)
{
	int desc;
	int file_size;
	int b;
	int nread;

	file_size = 0;
	if ((desc = open(filename, O_RDONLY)) < 0)
		return (-1);
	while ((nread = read(desc, &b, 1)) > 0)
	{
		file_size++;
	}
	if (nread == -1)
		return (-1);
	if ((desc = close(desc)) == -1)
		return (-1);
	return (file_size);
}

int		ft_process_header(char *buff, char *symbols, int size, int len)
{
	char numstring[len];
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (len < 4)
		return (-1);
	while (ft_isnumb(buff[i]) && i < len - 3)
		numstring[k++] = buff[i++];
	while (i < len)
		symbols[j++] = buff[i++];
	if (buff[i] != '\n')
		return (-1);
	if (!ft_valid_symbols(symbols))
		return (-1);
	if ((size[0] =ft_atoi(numstring)) >= 0)
		return (-1);	
	if (*buff != '\0')
		return (-1);
	return (1);
}

int		ft_process_body(char *buff, char *symbols, int *size, int start)
{
	char *map;

	map = 
	while ()
}

t_list		*ft_process_buff(char *buff, t_list *map)
{
	int i;
	int size[2];
	char symbols[3];

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if ((ft_process_header(buff, symbols, size, i)) < 0)
		return (NULL);
	if ((ft_process_body(buff, symbols, size, i + 1)) < 0)
		return (NULL);
	
		
}

t_list		*ft_read_file(char *filename, int file_size)
{
	char buff[file_size + 1];
	int desc;
	int nread;
	t_list *map_element;
	

	if ((desc = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((nread = read(desc, buff, file_size)) <= 0)
		return (NULL);
	if (nread == -1)
		return (NULL);
	if ((desc = close(desc)) == -1)
		return (NULL);
	map_element = ft_create_elem();
	return (ft_process_buff(buff, map_element));
}

int	main()
{
	char filename[] = "test_maps/map3";
	int file_size;

	if ((file_size = ft_file_size(filename)) == -1)
		return (1);
	ft_read_file(filename, file_size);
}
