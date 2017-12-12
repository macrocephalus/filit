#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yholub <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/02 14:51:00 by yholub            #+#    #+#              #
#    Updated: 2017/11/13 16:02:53 by yholub           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_realloc.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_putendl.c\
	  ft_sqrt.c\
	  ft_memalloc.c\
	  ft_strnew.c\
	  ft_strlen.c\
	  ft_putstr.c\
	  ft_putchar.c\
	  ft_memset.c\

OSRC = $(patsubst %.c, %.o, $(SRC))
all: $(NAME)
    
$(NAME): $(OSRC)
	ar cr $(NAME) $(OSRC)
	ranlib $(NAME)

%.o : %.c
	gcc -c -Wall -Wextra -Werror $<

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
