/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:54 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 13:40:03 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"
#include <stdio.h>

void	ft_print_solutions(t_list *maps_list)
{
	while (maps_list)
	{
		if (maps_list->map)
		{
			search_square();
			answer_map();
		}
		print_map(maps_list);
		maps_list = maps_list->next;
	}
}

void	ft_master(int nmaps, char **argv)
{
	t_list *maps_list;
	argv++;
	maps_list = ft_parse_arguments(nmaps, argv);
	ft_print_solutions(maps_list);
	printf("successfully executed\n");
	// emancipate(maps_list);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		//ft_stdin();
		return (0);
	}
	else if (argc > 1)
		ft_master(argc - 1, argv);
	return (0);
}
