/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_js.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:05:05 by jsarkis           #+#    #+#             */
/*   Updated: 2019/10/06 12:16:09 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_JS_H
# define LEM_IN_JS_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# define CLEAR "\e[1;1H\e[2J"
# define STR_SIZE 1024

typedef char			*t_str;
typedef unsigned char	*t_ustr;
typedef	unsigned int	t_uint;

typedef	struct		s_room
{
	struct s_room	**arr_links;
	struct s_room	*next;
	t_uint			visited : 6;
	t_uint			links : 8;
	t_uint			type : 2;
	t_uint			x : 8;
	t_uint			y : 8;
	t_uint			index : 8;
	t_str			name;
}					t_room;

typedef struct		s_path
{
	struct s_room	*current;
	struct s_path	*next;
	t_ustr			arr_path;
	t_uint			path_length : 8;
}					t_path;

typedef struct		s_path_set
{
	t_ustr			arr_paths;
	t_uint			num_moves : 8;
	t_uint			num_paths : 8;
}					t_path_set;

typedef	struct		s_data
{
	t_uint			num_ants;
	t_uint			num_rooms;
	t_uint			room_1;
	t_uint			room_2;
	t_str			s;
}					t_data;

void				initialize_rooms(t_data *data, t_room ***arr_rooms);

void				free_arr(void	**arr);

void				find_path(t_room **arr_rooms, int num_ants, int num_rooms);

int					get_ants(void);

void				malloc_links(t_room ***arr_rooms, t_data data);

void				print_err_msg(const t_str err_msg);

void				print_links(t_room **arr_rooms);

void				print_path(t_path *head, t_room **arr_rooms);

void				print_paths(t_path *head, t_room **arr_rooms);

void				print_rooms(t_room *head);

t_str				*read_links(t_data *data, t_room ***arr_rooms);

void				set_links(t_room **arr_rooms, t_str *arr_links);

int					is_integer(t_str s);

int					count_occurrences(t_str s, char c);

#endif
