/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 23:03:49 by jsarkis           #+#    #+#             */
/*   Updated: 2020/03/19 23:03:49 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		path_can_be_expanded(t_path *head, int max_num_path)
{
	int	i;

	if (!head)
		return (-1);
	if (head->current->type != END)
	{
		i = 0;
		while (i < head->current->links)
		{
			if (valid_path(head, max_num_path, i))
				return (1);
			i++;
		}
	}
	return (0);
}

int		propagated(t_path *head, int max_num_paths, int path_length)
{
	int	num_paths_found;
	int	valid;

	num_paths_found = 0;
	valid = 1;
	while (head)
	{
		if (path_can_be_expanded(head, max_num_paths))
			valid = 0;
		if (head->current->type == END && head->path_length == path_length)
			num_paths_found++;
		if (num_paths_found == max_num_paths)
			return (1);
		head = head->next;
	}
	return (valid);
}

int		valid_path(t_path *path, unsigned int max_num_paths, int i)
{
	t_uint	num_visits;

	if (path->current->arr_links[i]->type == END)
		return (1);
	num_visits = path->current->arr_links[i]->visited;
	if (num_visits < max_num_paths && !visited(path, i))
		return (1);
	return (0);
}

int		visited(t_path *path, int next_link)
{
	int	i;

	i = 0;
	while (i < path->path_length)
	{
		if (path->arr_path[i] == path->current->arr_links[next_link]->index)
			return (1);
		i++;
	}
	return (0);
}

int		collide(t_path_set path_set, t_path *head, t_path *next)
{
	t_path	*current;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < path_set.num_paths)
	{
		current = head;
		j = -1;
		while (++j < path_set.arr_paths[i])
			current = current->next;
		j = 1;
		while (j < next->path_length - 1)
		{
			k = 1;
			while (k < current->path_length - 1)
			{
				if (next->arr_path[j] == current->arr_path[k])
					return (1);
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	update_best(t_path_set *best, t_path_set *path_set)
{
	int	j;

	if (path_set->num_moves < best->num_moves)
	{
		j = -1;
		while (++j < path_set->num_paths)
			best->arr_paths[j] = path_set->arr_paths[j];
		best->num_moves = path_set->num_moves;
		best->num_paths = path_set->num_paths;
	}
}