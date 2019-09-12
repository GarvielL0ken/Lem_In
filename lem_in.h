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
	struct s_room	**arr_links;
	struct s_room	*next;
	unsigned int	visited : 6; 
	unsigned int	links : 8;
	unsigned int	type : 2;
	unsigned int	x : 8;
	unsigned int	y : 8;
	t_str			name;
}					t_room;

typedef	struct		s_node
{
	int				index;
	struct s_node	*next;
}					t_node;

void				print_err_msg(const t_str err_msg);

#endif
