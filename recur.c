/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:11:34 by yholub            #+#    #+#             */
/*   Updated: 2017/12/07 18:11:36 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		reurcia_f(char **map, int size_map, t_figur *temp, int index_f)
{
	int i;
	int j;

	i = 0;
	while (i < size_map)
	{
		j = 0;
		while (j < size_map)
		{
			if (put_check_fig(map, i, j, &temp[index_f]))
			{
				put_fig(map, i, j, &temp[index_f]);
				if (index_f == (g_countfig - 1))
					return (1);
				if (!(reurcia_f(map, size_map, temp, index_f + 1)))
					del_fig(map, i, j, &temp[index_f]);
				else
					return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

void	print_map(char **str)
{
	int		j;

	j = 0;
	while (str[j])
	{
		ft_putstr(str[j]);
		ft_putchar('\n');
		j++;
	}
}
