/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:04:59 by jsarkis           #+#    #+#             */
/*   Updated: 2019/09/02 15:05:01 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> //DELETE THIS
#include <stdlib.h>

void	print_rooms(t_room *head)
{
	while (head)
	{
		printf("name = %s, x  = %d, y = %d\n", head->name, head->x, head->y);
		head = head->next;
	}
}

void	free_arr(void	**arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	append_head(t_room **head, t_str s, unsigned int type)
{
	t_room	*new;
	t_str	*arr_data;

	new  = *head;
	if (!*head)
	{
		new = (t_room *)malloc(sizeof(t_room));
		new->index = 0;
	}
	else
	{
		while (new->next)
			new = new->next;
		new->next = (t_room *)malloc(sizeof(t_room));
		new->next->index = new->index + 1;
		new = new->next;
	}
	arr_data = ft_strsplit(s, ' ');
	new->name = ft_strdup(arr_data[0]);
	new->x = ft_atoi(arr_data[1]);
	new->y = ft_atoi(arr_data[2]);
	new->next = NULL;
	new->arr_links = NULL;
	new->links = 0;
	new->type = type;
	new->visited = 0;
	free_arr((void **)arr_data);
	if (!*head)
		*head = new;
}

void	inc_num_links(t_room **arr_rooms, t_str s)
{
	int		i;
	t_str	*rooms;

	i = 0;
	rooms = ft_strsplit(s, '-');
	while (arr_rooms[i])
	{
		if (!ft_strcmp(arr_rooms[i]->name, rooms[0]) || !ft_strcmp(arr_rooms[i]->name, rooms[1]))
			arr_rooms[i]->links += 1;
		i++;
	}
	free_arr((void **)rooms);
}

t_str	str_cat_char(t_str dst, t_str src, char c)
{
	int	len;
	int	i;

	len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = c;
	dst[len + i + 1] = '\0';
	return (dst);
}

void	set_links(t_room **arr_rooms, t_str *arr_links)
{
	t_str	*current_rooms;
	int	i;
	int	j;
	int	k;
	int	tmp;

	i = 0;
	while (arr_links[i])
	{
		current_rooms = ft_strsplit(arr_links[i], '-');
		j = 0;
		while (ft_strcmp(arr_rooms[j]->name, current_rooms[0]))
			j++;
		k = 0;
		while (ft_strcmp(arr_rooms[k]->name, current_rooms[1]))
			k++;
		tmp = arr_rooms[j]->links;
		arr_rooms[j]->arr_links[tmp] = arr_rooms[k];
		arr_rooms[j]->links++;
		tmp = arr_rooms[k]->links;
		arr_rooms[k]->arr_links[tmp] = arr_rooms[j];
		arr_rooms[k]->links++;
		free_arr((void **)current_rooms);
		i++;
	}
}

void	print_links(t_room **arr_rooms)
{
	int	i;
	int	j;

	i = 0;
	while (arr_rooms[i])
	{
		j = 0;
		while (j < arr_rooms[i]->links)
		{
			ft_putstr(arr_rooms[i]->name);
			ft_putchar('-');
			ft_putendl(arr_rooms[i]->arr_links[j]->name);
			j++;
		}
		i++;
	}
}

t_path	*new_head(t_room *room, int num_rooms)
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

void	append_path(t_path *path, int next_link)
{
	path->arr_path[path->path_length] = path->current->arr_links[next_link]->index;
	path->path_length++;
}

int		visited(t_path *path, int next_link)
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

void	print_path(t_path *head, t_room **arr_rooms)
{
	int i;

	i = 0;
	while (i < head->path_length)
	{
		printf("%s-", arr_rooms[head->arr_path[i]]->name);
		i++;
	}
	printf("%s\n", arr_rooms[head->arr_path[i]]->name);
}

void	print_paths(t_path *head, t_room **arr_rooms)
{
	while (head)
	{
		print_path(head, arr_rooms);
		head = head->next;
	}
}

int		valid_path(t_path *path, int max_num_paths, int i)
{
	if (path->current->arr_links[i]->type == 2)
		return (1);
	if (path->current->arr_links[i]->visited < max_num_paths && !visited(path, i))
		return (1);
	return (0);
}

int		num_valid_paths(t_path *path, int max_nam_paths)
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

void	new_path(t_path *path, int i)
{
	t_path 	*new;
	int		j;

	new = path;
	while (new->next)
		new = new->next;
	new->next = (t_path *)malloc(sizeof(t_path));
	if (new->next)
	{
		new = new->next;
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

int		path_can_be_expanded(t_path *head, int max_num_path)
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

void	propagate_paths(t_path *head, int max_num_paths, int path_length)
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

int		propagated(t_path *head, int max_num_paths, int path_length)
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

void	remove_invalid_paths(t_path *head)
{
	t_path *temp;

	if (!head->next)
		return ;
	while (head->current->type < 2)
	{
		temp = head->next;
		free(head->arr_path);
		free(head);
		head = temp;
		if (!head)
			return ;
	}
	while (head->next)
	{
		if (head->next->current->type < 2)
		{
			temp = head->next;
			head->next = head->next->next;
			free(temp->arr_path);
			free(temp);
		}
		else
			head = head->next;
	}
}

int		collide(t_path_set path_set, t_path *head, t_path *next)
{
	t_path *current;
	int		i;
	int 	j;
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

int		num_moves(t_path_set path_set, t_path *head, int num_ants)
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

t_path_set	find_shortest_set(t_path *head, int num_ants, int max_num_paths, t_room **arr_rooms)
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
		ft_putstr("Current: ");
		print_path(current, arr_rooms);
		while (next)
		{
			ft_putstr("Next:    ");
			print_path(next, arr_rooms);
			printf("collide = %d\n", collide(path_set, head, next));
			if (!collide(path_set, head, next))
			{
				ft_putstr("OK\n");
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
	return (best);
}

void	move_ants(t_path_set path_set, t_path *head, t_room **arr_rooms)
{
	t_path **arr_paths;
	t_path *temp;
	int		i;
	int 	j;

	ft_putchar('\n');
	arr_paths = (t_path **)malloc(sizeof(t_path *) * path_set.num_paths);
	i = 0;
	temp = head;
	while (i < path_set.num_paths)
	{
		j = 0;
		while (j++ < path_set.arr_paths[i])
			temp = temp->next;
		arr_paths[i] = temp;
		print_path(arr_paths[i], arr_rooms);
		i++;
	}
}

void	find_path(t_room **arr_rooms, int num_ants, int num_rooms)
{
	t_path_set	path_set;
	t_path	*head;
	int	max_num_paths;
	int	i;
	int run;

	max_num_paths = num_ants;
	i = -1;
	while (arr_rooms[++i])
	{
		if (arr_rooms[i]->type && arr_rooms[i]->links < max_num_paths)
			max_num_paths = arr_rooms[i]->links;
		if (arr_rooms[i]->type == 1)
			head = new_head(arr_rooms[i], num_rooms);
	}
	head->current->visited = max_num_paths;
	printf("max_num_paths = %d\n\n", max_num_paths);

	run = 1;
	i = 0;
	while (run)
	{
		propagate_paths(head, max_num_paths, i);
		i++;
		if (propagated(head, max_num_paths, i))
			run = 0;
	}
	remove_invalid_paths(head);
	print_paths(head, arr_rooms);
	path_set = find_shortest_set(head, num_ants, max_num_paths, arr_rooms);
	move_ants(path_set, head, arr_rooms);
}

int		main()
{
	t_room			**arr_rooms;
	t_room			*head;
	t_str			s;
	t_str			links;
	t_str			*arr_links;
	int				num_ants;
	int				num_rooms;
	int				i;
	unsigned int	type;

	/*GET NUMBER OF ANTS*/
	num_ants = get_ants();
	
	/*INITIALIZE ROOMS*/
	num_rooms = 0;
	head = NULL;
	/*LOOP THROUGH EACH LINE ON STDIN*/
	while (1)
	{
		type = 0;
		/*LOOP UNTIL A LINE THAT DOESNT START WITH A '#' IS FOUND*/
		while (1)
		{
			get_next_line(0, &s);
			ft_putendl(s);
			/*EXIT CONDITION*/
			if (s[0] != '#')
				break ;
			/*CHECK WHETHER THE NEXT ROOM IS THE START OR THE END ROOM*/
			if (!ft_strcmp(s, "##start"))
				type = 1;
			if (!ft_strcmp(s, "##end"))
				type = 2;
			free(s);
		}
		/*EXIT THE LOOP IF THERE ARE NO SPACES IN THE LINE*/
		if (ft_find_index(s, ' ') == -1)
			break ;
		/*ADD A NEW ROOM TO THE END OF THE LINKED LIST OF ROOMS AND INCREMENT THE NUMBER OF ROOMS*/
		append_head(&head, s, type);
		num_rooms++;
		free(s);
	}
 
	arr_rooms = (t_room **)malloc(sizeof(t_room *) * (num_rooms + 1));
	i = 0;
	/*FOR EVERY ROOM SET AN INDEX OF ARR_ROOMS TO POINT TO THAT ROOMS*/
	while (head)
	{
		arr_rooms[i] = head;
		head = head->next;
		i++;
	}
	arr_rooms[i] = NULL;

	/*SET LINKS*/
	/*STR TO STORE ALL THE LINKS SEPERATED BY SPACES*/
	links = ft_strnew(1024);
	/*IF THE LAST LINE READ IN THE PREVIOUS SECTIONS IS NOT A COMMENT*/
	if (s[0] != '#')
	{
		/*INCREMENT THE NUMBER OF LINKS FOR BOTH ROOMS THAT THE LINE SPECIFIES*/
		inc_num_links(arr_rooms, s);
		/*APPEND LINKS WITH THE CURRENT LINE FOLLOWED BY A SPACE*/
		links = str_cat_char(links, s, ' ');
		//ft_putendl(links);
	}
	free(s);
	/*LOOP THROUGH THE REMAINING LINES ON STDIN*/
	while (1)
	{
		/*SKIP OVER COMMENTS*/
		while (1)
		{
			get_next_line(0, &s);
			ft_putendl(s);
			if (s[0] != '#')
				break ;
			free(s);
		}
		/*EXIT LOOP IF THE LAST LINE HAS BEEN FOUND*/
		if (!s[0])
			break ;
		inc_num_links(arr_rooms, s);
		str_cat_char(links, s, ' ');
		free(s);
	}
	/*SPLIT EACH LINK INTO AN INDEX OF AN ARRAY OF STRINGS*/
	arr_links = ft_strsplit(links, ' ');
	free(links);
	i = -1;
	/*MALLOC EACH ARRAY IN EVERY ROOM TO THE REQUIRED SIZE AND SET EACH ROOMS LINK VAR TO ZERO TO BE USED LATER*/
	while (++i < num_rooms)
	{
		arr_rooms[i]->arr_links = (t_room **)malloc(sizeof(t_room *) * arr_rooms[i]->links);
		arr_rooms[i]->links = 0;
	}
	/*FOR EVERY LINK IN ARR_LINKS MAKE THE CORRESPONDING ROOMS POINT TO EACH OTHER*/
	set_links(arr_rooms, arr_links);

	/*FIND AND EXECUTE PATH*/
	find_path(arr_rooms, num_ants, num_rooms);
}