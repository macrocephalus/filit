/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:57:32 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 16:00:03 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *arr;

	if (!(arr = malloc(size + 1)))
		return (NULL);
	ft_memset(arr, '\0', size + 1);
	return (arr);
}
