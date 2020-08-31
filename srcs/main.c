/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:54 by pfelipa           #+#    #+#             */
/*   Updated: 2020/08/31 14:48:42 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_head.h"

int		main(int argc, char **argv)
{
	t_list *maps;

	if (argc == 1)
		ft_stdin();
	else if (argc > 1)
		process(maps, argv);
	emancipate(maps);
}
