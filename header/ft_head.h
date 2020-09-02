/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:14:47 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 16:23:54 by qrigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAD_H
# define FT_HEAD_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			**map;
	char			*symbols;	// {empty, obstacle, full}
	int				*size;		// {size y, size x}
	struct s_list	*next;
}					t_list;

int			ft_isnumb(char c);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
void			ft_stdin(void);
void		ft_add_back(t_list **head, t_list *element);
t_list		*ft_create_elem(char **map, char *symbols, int *size);
void		ft_emancipate(t_list *head);
int			ft_isnumb(char c);
int			ft_valid_symbols(char *symbols);
int			ft_isprintable(char c);
int			ft_valid_char(char c, char *symbols);
int			ft_atoi(char *str);
int			*ft_intarr(int *arr, int size);
char		*ft_chararr(char *arr, int size);
int			ft_file_size(char *filename);
t_list		*ft_parse_arguments(int n_maps, char **filenames);
int			ft_linelen(char *buff);
int			ft_process_body(char *buff, char *symbols, int *size, char ***map);
int			ft_process_header(char *buff, char *symbols, int *size, int len);
int			ft_loop(char *buff, char ***map, char *symbols, int *size);
t_list		*ft_process_buff(char *buff);
void		ft_print_solutions(t_list *maps_list);

struct	coords
{
	int	x;
	int	y;
};

int			check_square(t_list *map_item, int size, struct coords start);
void		answer_map(t_list *map_item, int size, struct coords start);
void		search_square(t_list *map_item, struct coords start);
void		print_map(t_list *map_item);

#endif
