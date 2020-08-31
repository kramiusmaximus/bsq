/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:14:47 by pfelipa           #+#    #+#             */
/*   Updated: 2020/08/31 20:54:12 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAD_H
# define FT_HEAD_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct 		s_list  
{  
	char 			**map;  
	int 			**simple_map;  
	char 			*symbols;    // {empty, obstacle, full}
  	int				*size;	     // {size y, size x}
	struct s_list 	*next;  
}					t_list;  

#endif
