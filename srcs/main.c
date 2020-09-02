/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:21:01 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 18:44:49 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

void	ft_print_solutions(t_list *maps_list)
{
	struct s_coords start;

	start.x = 0;
	start.y = 0;
	while (maps_list->next)
	{
		if (maps_list->map)
			search_square(maps_list, start);
		print_map(maps_list);
		maps_list = maps_list->next;
		ft_putstr("\n");
	}
	if (maps_list->map)
		search_square(maps_list, start);
	print_map(maps_list);
}

void	ft_master(int nmaps, char **argv)
{
	t_list *maps_list;

	argv++;
	maps_list = ft_parse_arguments(nmaps, argv);
	ft_print_solutions(maps_list);
	ft_emancipate(maps_list);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_stdin();
	else if (argc > 1)
		ft_master(argc - 1, argv);
	return (0);
}
