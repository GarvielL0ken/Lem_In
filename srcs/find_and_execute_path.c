/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_execute_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:48:10 by jsarkis           #+#    #+#             */
/*   Updated: 2020/03/20 00:02:55 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

void		propagate_paths(t_path *head, int max_num_paths, int path_length)
{
	t_path	*path;
	int		i;
	int		num_paths;

	path = head;
	while (path)
	{
		if (path->path_length == path_length && path->current->type < 2)
		{
			num_paths = num_valid_paths(path, max_num_paths);
			i = 0;
			while (i < path->current->links && num_paths)
			{
				if (valid_path(path, max_num_paths, i))
				{
					new_path(path, i);
					num_paths--;
				}
				i++;
			}
			while (i < path->current->links)
			{
				if (valid_path(path, max_num_paths, i))
				{
					path->current = path->current->arr_links[i];
					path->path_length++;
					path->arr_path[path->path_length] = path->current->index;
					path->current->visited++;
					break ;
				}
				i++;
			}
		}
		path = path->next;
	}
}

void		remove_invalid_paths(t_path **head)
{
	t_path *temp;
	t_path *current;

	current = *head;
	if (!current->next)
		return ;
	while (current->current->type < 2)
	{
		temp = current->next;
		free(current->arr_path);
		free(current);
		current = temp;
		*head = current;
		if (!current)
			print_err_msg("Error: No Solution");
	}
	while (current->next)
	{
		if (current->next->current->type < 2)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp->arr_path);
			free(temp);
		}
		else
			current = current->next;
	}
}

t_path_set	find_shortest_set(t_path *head, t_data data)
{
	t_path_set	best;
	t_path_set	path_set;
	t_path		*current;
	t_path		*next;
	int			i;
	int			j;

	best.arr_paths = (t_ustr)malloc(data.max_num_paths);
	best.arr_paths[0] = 0;
	best.num_moves = head->path_length + data.num_ants - 1;
	best.num_paths = 1;
	path_set.arr_paths = (t_ustr)malloc(data.max_num_paths);
	current = head;
	i = 0;
	while (current)
	{
		path_set.arr_paths[0] = i;
		path_set.num_paths = 1;
		next = current->next;
		j = i + 1;
		while (next)
		{
			if (!collide(path_set, head, next))
			{
				path_set.arr_paths[path_set.num_paths] = j;
				path_set.num_paths++;
			}
			next = next->next;
			j++;
		}
		path_set.num_moves = num_moves(path_set, head, data.num_ants);
		//printf("num_moves = %d\n\n", path_set.num_moves);
		if (path_set.num_moves < best.num_moves)
		{
			j = -1;
			while (++j < path_set.num_paths)
				best.arr_paths[j] = path_set.arr_paths[j];
			best.num_moves = path_set.num_moves;
			best.num_paths = path_set.num_paths;
		}
		current = current->next;
		i++;
	}
	free(path_set.arr_paths);
	return (best);
}

t_path		generate_paths(t_room **arr_rooms, t_data *data)
{
	t_path		*head;
	t_uint		i;
	t_uint		run;

	i = -1;
	while (arr_rooms[++i])
	{
		if (arr_rooms[i]->type && arr_rooms[i]->links < data->max_num_paths)
			data.max_num_paths = arr_rooms[i]->links;
		if (data.max_num_paths <= 0)
			print_err_msg("Error: No solution");
		if (arr_rooms[i]->type == 1)
			head = new_head(arr_rooms[i], data->num_rooms);
	}
	run = 1;
	i = 0;
	while (run)
	{
		propagate_paths(head, data->max_num_paths, i);
		i++;
		if (propagated(head, data->max_num_paths, i))
			run = 0;
	}
	return (head);
}

void		find_path(t_room **arr_rooms, t_data data)
{
	t_path_set	path_set;
	t_path		*head;
	t_path		*temp;

	data.max_num_paths = data.num_ants;
	head = generate_paths(arr_rooms, data);
	remove_invalid_paths(&head);
	path_set = find_shortest_set(head, data);
	move_ants(path_set, head, data.num_ants, arr_rooms);
	free(path_set.arr_paths);
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
