# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 15:02:35 by jsarkis           #+#    #+#              #
#    Updated: 2019/09/02 15:02:36 by jsarkis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN = lem_in
HEADER = lem_in.h
CFLAGS = -Wall -Werror -Wextra
LINK = -L./libft -lft
LIB = libft/libft.a
SRCS = error_handling.c

all: $(LIB) $(LEMIN) $(SRCS) $(HEADER)

$(LIB):
	make -C libft

$(LEMIN): lem_in.c $(SRCS) $(HEADER)
	gcc $(CFLAGS) lem_in.c $(SRCS) $(LINK) -o $(LEMIN)