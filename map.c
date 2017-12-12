/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:08:07 by yholub            #+#    #+#             */
/*   Updated: 2017/12/07 21:08:11 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**init_map(int i)
{
	int		j;
	int		k;
	char	**str;

	if (!(str = (char **)malloc(sizeof(*str) * i + 1)))
		return (0);
	j = -1;
	while (++j < i)
	{
		k = 0;
		if (!(str[j] = ft_strnew(i)))
			str[j] = NULL;
		ft_memset(str[j], '.', i);
	}
	str[i] = 0;
	return (str);
}

char	**clean_map(char **str)
{
	int		j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str[j]);
	free(str);
	return (NULL);
}

int		put_check_fig(char **map, int y, int x, t_figur *temp)
{
	int count;
	int k;

	k = 0;
	count = 0;
	while (count < 4)
	{
		if ((temp->point[count].y + y) < (int)ft_strlen(map[0]))
		{
			if (map[temp->point[count].y + y][temp->point[count].x + x] == '.')
			{
				++k;
			}
		}
		count++;
	}
	if (k == 4)
		return (1);
	return (0);
}

void	put_fig(char **map, int y, int x, t_figur *temp)
{
	int count;

	count = 0;
	while (count < 4)
	{
		map[temp->point[count].y + y][temp->point[count].x + x] = temp->sumb;
		count++;
	}
}

void	del_fig(char **map, int y, int x, t_figur *temp)
{
	int count;

	count = 0;
	while (count < 4)
	{
		map[temp->point[count].y + y][temp->point[count].x + x] = '.';
		count++;
	}
}
