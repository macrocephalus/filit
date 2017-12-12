/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:26:13 by yholub            #+#    #+#             */
/*   Updated: 2017/11/30 14:25:28 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_figur
{
	t_point			point[4];
	char			sumb;
}					t_figur;

int					g_countfig;

void				del_fig(char **map, int y, int x, t_figur *temp);
void				put_fig(char **map, int y, int x, t_figur *temp);
int					put_check_fig(char **map, int y, int x, t_figur *temp);
char				**clean_map(char **str);
char				**init_map(int i);
void				print_map(char **str);
int					block_count(char *str);
char				**split_blocks(char *s);
char				*read_file(char *str);
int					valid_block(char *str);
int					cmp_block(char *str);
int					check_cont(char *str);
int					check_contacts(char *str);
int					cmp_block2(char *str);
t_figur				*initializ(char *str, int countf);
void				normilize(t_figur *temp, size_t n);
int					reurcia_f(char **map, int size_map,
					t_figur *temp, int index_f);

#endif
