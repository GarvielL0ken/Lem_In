/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 22:58:09 by jsarkis           #+#    #+#             */
/*   Updated: 2020/03/19 22:58:09 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

t_path		*new_head(t_room *room, int num_rooms)
{
	t_path	*head;
	int		i;

	head = (t_path *)malloc(sizeof(t_path));
	if (head)
	{
		head->current = room;
		head->next = NULL;
		head->arr_path = (unsigned char *)malloc(num_rooms);
		i = 0;
		while (++i < num_rooms)
			head->arr_path[i] = 0;
		head->arr_path[0] = room->index;
		head->path_length = 0;
	}
	return (head);
}

void		append_path(t_path *path, int next_link)
{
	unsigned int	index;

	index = path->current->arr_links[next_link]->index;
	path->arr_path[path->path_length] = index;
	path->path_length++;
}

void		new_path(t_path *path, int i)
{
	t_path	*new;
	int		j;

	new = path;
	while (new->next)
		new = new->next;
	new->next = (t_path *)malloc(sizeof(t_path));
	if (new->next)
	{
		new = new->next;
		new->next = NULL;
		new->current = path->current->arr_links[i];
		new->path_length = path->path_length + 1;
		new->arr_path = (unsigned char *)malloc(1024);
		j = -1;
		while (++j < new->path_length)
			new->arr_path[j] = path->arr_path[j];
		new->arr_path[j] = path->current->arr_links[i]->index;
		new->current->visited++;
	}
}
