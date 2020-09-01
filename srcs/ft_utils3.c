/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:57:38 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/01 18:00:21 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_head.h"

int		ft_atoi(char *str)
{
	int res;

	if (*str == 0)
		return (0);
	res = 0;
	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int		*ft_intarr(int *arr, int size)
{
	int *cpy;
	int i;

	cpy = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}

char	*ft_chararr(char *arr, int size)
{
	char *cpy;
	int i;

	cpy = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}

int     ft_file_size(char *filename)
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
