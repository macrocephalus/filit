/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:57:09 by yholub            #+#    #+#             */
/*   Updated: 2017/12/01 16:41:47 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int i)
{
	int j;
	int result;

	j = 0;
	result = 0;
	while (i != result)
	{
		if (result > i)
			return (--j);
		j++;
		result = j * j;
	}
	return (j);
}