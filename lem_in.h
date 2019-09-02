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
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

void				print_err_msg(const t_str err_msg);

#endif
