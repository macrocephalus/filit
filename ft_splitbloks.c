/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitbloks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:38:48 by yholub            #+#    #+#             */
/*   Updated: 2017/11/30 14:25:50 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**split_blocks(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s || !(str = (char **)malloc(sizeof(*str) * (g_countfig + 1))))
		return (0);
	i = -1;
	j = 0;
	while (++i < g_countfig)
	{
		k = 0;
		if (!(str[i] = ft_strnew(20)))
			str[i] = NULL;
		while (s[j] == '\n')
			j++;
		while (k != 20 && s[j] != '\0')
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = 0;
	return (str);
}
