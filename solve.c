/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:44:19 by yholub            #+#    #+#             */
/*   Updated: 2017/12/01 16:44:36 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figur			*initializ(char *str, int countf)
{
	char		**f_file;
	t_figur		*temp;
	int			i;
	int			j;
	int			itradok;

	i = -1;
	itradok = -1;
	f_file = split_blocks(str);
	if (!(temp = ft_memalloc((sizeof(t_figur) * countf))))
		return (NULL);
	while (++i < countf)
	{
		j = 0;
		while (j < 4)
			while (f_file[i][++itradok])
				if (f_file[i][itradok] == '#')
				{
					temp[i].point[j].x = ((itradok + 1) % 5) - 1;
					temp[i].point[j].y = (((itradok) / 5) + 1) - 1;
					++j;
				}
		itradok = -1;
	}
	return (temp);
}

void			normilize(t_figur *temp, size_t n)
{
	int			minx;
	int			miny;
	int			i;
	int			p;

	i = -1;
	while (++i < (int)n)
	{
		minx = 2147483646;
		miny = 2147483646;
		p = -1;
		while (++p < 4)
		{
			minx = MIN(temp[i].point[p].x, minx);
			miny = MIN(temp[i].point[p].y, miny);
		}
		p = -1;
		while (++p < 4)
		{
			temp[i].point[p].x = temp[i].point[p].x - minx;
			temp[i].point[p].y = temp[i].point[p].y - miny;
		}
		temp[i].sumb = 65 + i;
	}
}
