/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:54 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/01 23:04:54 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_head.h"

void	ft_master(int nmaps, char **argv)
{
	t_list *maps_list;
	argv++;
	maps_list = ft_parse_arguments(nmaps, argv);
	// add_solution(maps_list);
	// print_maps(maps_list);
	// emancipate(maps_list);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_stdin();
	else if (argc > 1)
		ft_master(argc - 1, argv);
	return (0);
}
