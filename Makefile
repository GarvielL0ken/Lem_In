# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bswanepo <bswanepo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 15:02:35 by jsarkis           #+#    #+#              #
#    Updated: 2019/09/19 13:45:43 by bswanepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN = lem_in
HEADER = lem_in_js.h
CFLAGS = -Wall -Werror -Wextra
LINK = -L./libft -lft
LIB = libft/libft.a
SRCS = srcs/*.c


all: $(LIB) $(LEMIN) $(SRCS) $(HEADER)

$(LIB):
	make -C libft

$(LEMIN): lem_in_js.c $(SRCS) $(HEADER)
	gcc $(CFLAGS) lem_in_js.c $(SRCS) $(LINK) -o $(LEMIN)

fclean:
	make -C libft fclean
	rm lem_in

norm:
	norminette lem_in_js.c $(SRCS) $(HEADER)
