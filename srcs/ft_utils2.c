/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:35:31 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 13:32:40 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

void    ft_emancipate(t_list *head)
{
    t_list *prev;

    while (head)
    {
        prev = head;
        head = head->next;
		/*if (prev->map)
		{
		
		}*/ // to free or not to free?
		free(prev->map);
		free(prev->symbols);
		free(prev->size);
        free(prev);  // function needs to be completed
    }
}

int		ft_isnumb(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isprintable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int		ft_valid_symbols(char *symbols)
{
	int i;
	int j;

	i = 0;
	while (i < 2)
	{
		if (!ft_isprintable(symbols[i]))
			return (0);
		j = i + 1;
		while (j < 3)
			if (symbols[i] == symbols[j++])
				return (0);
		i++;
	}
	return (1);
}

int		ft_valid_char(char c, char *symbols)
{
	int i;

	i = 0;
	while (i < 2)
		if (symbols[i++] == c)
			return (1);
	return (0);
}
