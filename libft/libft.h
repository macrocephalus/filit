/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:07:15 by yholub            #+#    #+#             */
/*   Updated: 2017/11/13 16:02:40 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void				*ft_realloc(void *ptr, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				ft_putendl(char const *s);
int					ft_sqrt(int i);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				*ft_memset(void *b, int c, size_t len);

#endif
