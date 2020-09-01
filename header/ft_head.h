/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:14:47 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/01 15:07:29 by pfelipa          ###   ########.fr       */
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
	char 			**simple_map;  
	char 			*symbols;    // {empty, obstacle, full}
  	int				*size;	     // {size y, size x}
	struct s_list 	*next;  
}					t_list;  

int     ft_isnumb(char c);
void    ft_putstr(char *str);
int     ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
int     ft_stdin(void);
void    ft_add_back(t_list **head, t_list *element);
t_list  *ft_create_elem(char **map, char *symbols, int *size);
void    ft_emancipate(t_list *head);
int     ft_isnumb(char c);
int     ft_valid_symbols(char *symbols);
int     ft_isprintable(char c);
int     ft_valid_char(char c, char *symbols);
int     ft_atoi(char *str);
#endif
