/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:05:05 by jsarkis           #+#    #+#             */
/*   Updated: 2019/09/17 12:18:16 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

typedef char *t_str;
typedef unsigned char *t_ustr;

typedef	struct		s_room
{
	struct s_room	**arr_links;
	struct s_room	*next;
	unsigned int	visited : 6; 
	unsigned int	links : 8;
	unsigned int	type : 2;
	unsigned int	x : 8;
	unsigned int	y : 8;
	unsigned int	index : 8;
	t_str			name;
}					t_room;

typedef struct 		s_path
{
	struct s_room	*current;
	struct s_path	*next;
	t_ustr			arr_path;
	unsigned int	path_length : 8;
}					t_path;

typedef struct		s_path_set
{
	t_ustr			arr_paths;
	unsigned int	num_moves : 8;
	unsigned int	num_paths : 8;
}					t_path_set;

typedef	struct 		s_data
{
	int				num_ants;
	int				num_rooms;
	t_str			s;
}					t_data;

void				print_err_msg(const t_str err_msg);

int					get_ants(void);

#endif
