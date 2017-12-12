/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:37:49 by yholub            #+#    #+#             */
/*   Updated: 2017/11/29 11:38:06 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		valid_block(char *str)
{
	int		i;
	int		j;
	int		k;
	int		y;
	char	**str2;

	y = 0;
	j = 0;
	str2 = split_blocks(str);
	while (str2[j])
	{
		i = 0;
		k = 0;
		while (str2[j][i])
		{
			if (str2[j][i] == '#')
				k++;
			i++;
		}
		if (k == 4)
			y++;
		j++;
	}
	return (y);
}

int		cmp_block(char *str)
{
	if (g_countfig == (valid_block(str)))
		return (1);
	else
	{
		ft_putendl("error");
		exit(0);
	}
	return (0);
}

int		check_cont(char *str)
{
	int i;
	int k;
	int y;

	i = 0;
	k = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				k++;
			if (str[i - 1] == '#')
				k++;
			if (str[i + 5] == '#')
				k++;
			if (str[i - 5] == '#')
				k++;
		}
		i++;
	}
	if (k >= 6)
		y++;
	return (y);
}

int		check_contacts(char *str)
{
	char	**str2;
	int		j;
	int		y;

	j = 0;
	y = 0;
	str2 = split_blocks(str);
	if (cmp_block(str) == 1)
	{
		while (str2[j])
		{
			if (check_cont(str2[j]) == 1)
				y++;
			j++;
		}
	}
	return (y);
}

int		cmp_block2(char *str)
{
	if (check_contacts(str) == (valid_block(str)) && g_countfig != 0)
	{
		return (1);
	}
	if (check_contacts(str) != (valid_block(str)) || g_countfig == 0)
		ft_putendl("error");
	return (0);
}
