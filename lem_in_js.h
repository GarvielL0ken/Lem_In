/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_js.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:05:05 by jsarkis           #+#    #+#             */
/*   Updated: 2020/03/19 23:51:00 by jsarkis          ###   ########.fr       */
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
	t_uint			max_num_paths;
	t_uint			path_length;
	t_uint			room_1;
	t_uint			room_2;
	t_str			s;
}					t_data;

void				append_path(t_path *path, int next_link);

int 				add_new_paths(t_path *path, t_data *data);

int					collide(t_path_set path_set, t_path *head, t_path *next);

t_room				**initialize_rooms(t_data *data);

void				free_arr(void	**arr);

t_path 				*remove_path(t_path *current)

void				find_path(t_room **arr_rooms, t_data);

int					get_ants(void);

t_path				*new_head(t_room *room, int num_rooms);

void				new_path(t_path *path, int i);

int					num_moves(t_path_set path_set, t_path *head, int num_ants);

int					num_valid_paths(t_path *path, int max_nam_paths);

void				malloc_links(t_room ***arr_rooms, t_data data);

void				move_ants(t_path_set path_set, t_path *head, int num_ants, 							t_room **arr_rooms);

int					path_can_be_expanded(t_path *head, int max_num_path);

void				print_err_msg(const t_str err_msg);

void				print_links(t_room **arr_rooms);

void				print_path(t_path *head, t_room **arr_rooms);

void				print_paths(t_path *head, t_room **arr_rooms);

void				print_rooms(t_room *head);

int					propagated(t_path *head, int max_num_paths, int path_length);

t_str				*read_links(t_data *data, t_room ***arr_rooms);

void				set_links(t_room **arr_rooms, t_str *arr_links);

int					is_integer(t_str s);

int					count_occurrences(t_str s, char c);

void				validate_rooms(t_room **arr_rooms, t_data data);

int					valid_path(t_path *path, unsigned int max_num_paths, int i);

int					visited(t_path *path, int next_link);
#endif
