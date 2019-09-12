/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:05:05 by jsarkis           #+#    #+#             */
/*   Updated: 2019/09/02 15:05:06 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

typedef char *t_str;

typedef	struct		s_room
{
	t_str			name;
	int				start;
	int				end;
	int				visited;
	int				x;
	int				y;
	struct s_room	*next;
	struct s_room	**arr_links;
	int				num_links;
	int				link_to_set;
}					t_room;

typedef	struct		s_node
{
	int				index;
	struct s_node	*next;
}					t_node;

void				print_err_msg(const t_str err_msg);

#endif
