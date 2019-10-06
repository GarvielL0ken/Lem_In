/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_execute_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:48:10 by jsarkis           #+#    #+#             */
/*   Updated: 2019/10/06 14:53:36 by jsarkis          ###   ########.fr       */
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

int			visited(t_path *path, int next_link)
{
	int i;

	i = 0;
	while (i < path->path_length)
	{
		if (path->arr_path[i] == path->current->arr_links[next_link]->index)
			return (1);
		i++;
	}
	return (0);
}

int			valid_path(t_path *path, unsigned int max_num_paths, int i)
{
	unsigned int	num_visits;

	if (path->current->arr_links[i]->type == 2)
		return (1);
	num_visits = path->current->arr_links[i]->visited;
	if (num_visits < max_num_paths && !visited(path, i))
		return (1);
	return (0);
}

int			num_valid_paths(t_path *path, int max_nam_paths)
{
	int	i;
	int	num_paths;

	i = 0;
	num_paths = 0;
	while (i < path->current->links)
	{
		if (valid_path(path, max_nam_paths, i))
			num_paths++;
		i++;
	}
	return (num_paths - 1);
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

int			path_can_be_expanded(t_path *head, int max_num_path)
{
	int	i;

	if (!head)
		return (-1);
	if (head->current->type < 2)
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

int			propagated(t_path *head, int max_num_paths, int path_length)
{
	int		num_paths_found;
	int		valid;

	num_paths_found = 0;
	valid = 1;
	while (head)
	{
		if (path_can_be_expanded(head, max_num_paths))
			valid = 0;
		if (head->current->type == 2 && head->path_length == path_length)
			num_paths_found++;
		if (num_paths_found == max_num_paths)
			return (1);
		head = head->next;
	}
	return (valid);
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

int			collide(t_path_set path_set, t_path *head, t_path *next)
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

int			num_moves(t_path_set path_set, t_path *head, int num_ants)
{
	t_path	*current;
	int		min;
	int		num_paths_to_use;
	int		i;
	int		j;

	current = head;
	num_paths_to_use = 1;
	i = 1;
	j = 0;
	while (j++ < path_set.arr_paths[0])
		current = current->next;
	min = current->path_length;
	while (i < path_set.num_paths)
	{
		while (j++ < path_set.arr_paths[i])
			current = current->next;
		if (current->path_length < min && current->path_length < num_ants + 1)
			min = current->path_length;
		if (current->path_length < num_ants + 1)
			num_paths_to_use++;
		i++;
	}
	return ((num_ants / num_paths_to_use) + min - 1);
}

t_path_set	find_shortest_set(t_path *head, int num_ants, int max_num_paths)
{
	t_path_set	best;
	t_path_set	path_set;
	t_path		*current;
	t_path		*next;
	int			i;
	int			j;

	best.arr_paths = (t_ustr)malloc(max_num_paths);
	best.arr_paths[0] = 0;
	best.num_moves = head->path_length + num_ants - 1;
	best.num_paths = 1;
	path_set.arr_paths = (t_ustr)malloc(max_num_paths);
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
		path_set.num_moves = num_moves(path_set, head, num_ants);
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

void		append_line(int ant_number, t_str name, t_str *line, t_uint *line_length)
{
	t_uint	new_length;
	t_str	str_ant_number;
	int		i;
	int		j;

	new_length = ft_strlen(*line) + 3 + ft_order((long)ant_number) + ft_strlen(name);
	if ((*line_length / STR_SIZE < new_length / STR_SIZE))
		ft_str_realloc(line, ((new_length / STR_SIZE) * STR_SIZE));
	(*line)[*line_length] = 'L';
	str_ant_number = ft_itoa((int)ant_number);
	i = -1;
	while (str_ant_number[++i])
		(*line)[*line_length + 1 + i] = str_ant_number[i];
	(*line)[*line_length + 1 + i] = '-';
	j = -1;
	while (name[++j])
		(*line)[*line_length + 2 + i + j] = name[j];
	(*line)[*line_length + 2 + i + j] = ' ';
	*line_length = new_length;
	free(str_ant_number);
	str_ant_number = NULL;
}

void		print_moves(t_path_set path_set, t_path **arr_paths, int num_ants, t_room **arr_rooms)
{
	t_str	line;
	t_uint	line_length;
	int	move_number;
	int	ant_number;
	int	index;

	move_number = 0;
	line = ft_strnew(STR_SIZE);
	while (++move_number <= path_set.num_moves)
	{
		line_length = 0;
		ant_number = 0;
		index = move_number;
		while (++ant_number <= num_ants && index)
		{
			if (index <= arr_paths[(ant_number % path_set.num_paths)]->path_length)
				append_line(ant_number, arr_rooms[arr_paths[(ant_number % path_set.num_paths)]->arr_path[index]]->name, &line, &line_length);
			if (!(ant_number % path_set.num_paths))
				index--;
		}
		ft_putstr(line);
		while(--line_length > 0)
			line[line_length] = 0;
		line[0] = 0;
		ft_putchar('\n');
	}
	free(line);
}

void		move_ants(t_path_set path_set, t_path *head, int num_ants, t_room **arr_rooms)
{
	t_path	**arr_paths;
	t_path	*temp;
	int		i;
	int		j;

	arr_paths = (t_path **)malloc(sizeof(t_path *) * path_set.num_paths);
	i = 0;
	temp = head;
	while (i < path_set.num_paths)
	{
		j = 0;
		temp = head;
		while (j++ < path_set.arr_paths[i])
			temp = temp->next;
		arr_paths[i] = temp;
		print_path(arr_paths[i], arr_rooms);
		i++;
	}
	print_moves(path_set, arr_paths, num_ants, arr_rooms);
	free(arr_paths);
}

void		find_path(t_room **arr_rooms, int num_ants, int num_rooms)
{
	t_path_set	path_set;
	t_path		*head;
	t_path		*temp;
	int			max_num_paths;
	int			i;
	int			run;

	max_num_paths = num_ants;
	i = -1;
	while (arr_rooms[++i])
	{
		if (arr_rooms[i]->type && arr_rooms[i]->links < max_num_paths)
			max_num_paths = arr_rooms[i]->links;
		if (max_num_paths <= 0)
			print_err_msg("Error: No solution");
		if (arr_rooms[i]->type == 1)
			head = new_head(arr_rooms[i], num_rooms);
	}
	head->current->visited = max_num_paths;
	run = 1;
	i = 0;
	while (run)
	{
		propagate_paths(head, max_num_paths, i);
		i++;
		if (propagated(head, max_num_paths, i))
			run = 0;
	}
	remove_invalid_paths(&head);
	path_set = find_shortest_set(head, num_ants, max_num_paths);
	move_ants(path_set, head, num_ants, arr_rooms);
	free(path_set.arr_paths);
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
