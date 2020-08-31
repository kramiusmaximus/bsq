/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:35:31 by pfelipa           #+#    #+#             */
/*   Updated: 2020/08/31 14:42:33 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_head.h"

void    ft_emancipate(t_list *head)
{
    t_list *prev;

    while (head)
    {
        prev = head;
        head = head->next;
        free(prev->map);
        free(prev->simple_map);
		free(prev->map_details);
        free(prev);
    }
}
