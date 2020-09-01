/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:17:22 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/01 22:50:40 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_head.h"

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int     ft_strlen(char *str)
{
    int len;

    len = 0;
    while (*str)
    {
        str++;
        len++;
    }
    return (len);
}

int     ft_strcmp(char *s1, char *s2)
{
    while ((*s1) && (*s2) && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void    ft_add_back(t_list **head, t_list *element)
{
    t_list *current;

    if (!*head)
    {
        *head = element;
        return ;
    }
    current = *head;
    while (current->next)
        current = current->next;
    current->next = element;
}

t_list  *ft_create_elem(char **map, char *symbols, int *size)
{
    t_list *element;

    element = (t_list *)malloc(sizeof(t_list));
	if (!map)
	{
		element->map = NULL;
		element->symbols = NULL;
		element->size = NULL;
	}
	else
	{
		element->map = map;
		element->symbols = ft_chararr(symbols, 3);
		element->size = ft_intarr(size, 2);
	}	
	element->next = NULL;
    return (element);
}
