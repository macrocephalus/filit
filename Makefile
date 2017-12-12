#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yholub <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 15:12:20 by yholub            #+#    #+#              #
#    Updated: 2017/11/30 15:12:23 by yholub           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = main.c\
	  check.c\
	  ft_splitbloks.c\
	  block_count.c\
	  solve.c\
	  map.c\
	  recur.c\

OBJ = $(SRC:.c=.o)

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
		make -C ./libft/

clean:
		rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all
