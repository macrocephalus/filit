/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:39:40 by yholub            #+#    #+#             */
/*   Updated: 2017/11/30 14:25:03 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		ft_check_symbols(char *str)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '#' || str[i] == '\n')
			size++;
		i++;
	}
	if (size == i)
		return (1);
	return (0);
}

static int		is_string(int i, int y, int j)
{
	if ((i + 1 - y) % 5 == 0 && j != 4)
		return (1);
	return (0);
}

static int		is_block(int i, int y, int j)
{
	if ((i - y) % 20 == 0 && j == 4)
		return (1);
	return (0);
}

int				block_count(char *str)
{
	int i;
	int j;
	int y;

	i = 0;
	j = 0;
	y = 0;
	while (ft_check_symbols(str) == 1 && str[i] != '\0')
	{
		if (is_string(i, y, j) && str[i] == '\n')
			j++;
		i++;
		if (j == 4 && is_block(i, y, j) && (str[i] == '\n' || str[i] == '\0'))
		{
			y++;
			j = 0;
		}
	}
	if ((i + 1) == (y * 21) && (y >= 1 && y <= 26))
		return (y);
	return (0);
}
