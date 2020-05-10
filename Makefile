# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 15:02:35 by jsarkis           #+#    #+#              #
#    Updated: 2020/05/10 14:39:14 by jsarkis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN = lem_in
HEADER = lem_in.h
CFLAGS = -Wall -Werror -Wextra
LINK = -L./libft -lft
LIB = libft/libft.a
SRCS = srcs/*.c


all: $(LIB) $(LEMIN) $(SRCS) $(HEADER)

$(LIB):
	sudo make -C libft

$(LEMIN): lem_in.c $(SRCS) $(HEADER)
	sudo gcc $(CFLAGS) lem_in.c $(SRCS) $(LINK) -o $(LEMIN)

fclean:
	sudo make -C libft fclean
	sudo rm $(LEMIN)

re: fclean all

norm:
	norminette lem_in_js.c $(SRCS) $(HEADER)
