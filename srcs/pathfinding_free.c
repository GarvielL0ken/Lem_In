/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:43:18 by jsarkis           #+#    #+#             */
/*   Updated: 2020/05/04 11:43:23 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_path	*remove_path(t_path *current)
{
	t_path	*remove;
	t_path	*next;

	remove = current->next;
	next = current->next->next;
	free(remove->arr_path);
	free(remove);
	return (next);
}