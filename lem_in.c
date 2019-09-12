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
#include <stdio.h>
#include <stdlib.h>

void	print_rooms(t_room *head)
{
	while (head)
	{
		printf("name = %s, x  = %d, y = %d\n", head->name, head->x, head->y);
		head = head->next;
	}
}

int		valid_chars(t_str s, const t_str valid)
{
	int i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (valid[j])
		{
			if (s[i] == valid[j])
				break ;
			j++;
		}
		if (!valid[j])
			return (0);
		i++;
	}
	return (1);
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
		head->path_length = 1;
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
	while (i < head->path_length - 1)
	{
		printf("%s-", arr_rooms[head->arr_path[i]]->name);
		i++;
	}
	printf("%s\n", arr_rooms[head->arr_path[i]]->name);
}

void	find_path(t_room **arr_rooms, int num_ants, int num_rooms)
{
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
	printf("start.name = %s\n", head->current->name);
	run = 1;
	while (run)
	{
		i = 0;
		while (i < head->current->links)
		{
			if (head->current->arr_links[i]->visited < max_num_paths && !visited(head, i))
			{
				append_path(head, i);
				head->current = head->current->arr_links[i];
				head->current->visited++;
				print_path(head, arr_rooms);
				break ;
			}
			i++;
		}
		printf("current.name = %s\n", head->current->name);
		if (head->current->type == 2)
			run = 0;
	}
	print_path(head, arr_rooms);
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
	while (1)
	{
		get_next_line(0, &s);
		if (s[0] != '#')
			break ;
		free(s);
	}
	if (!valid_chars(s, "0123456789"))
		print_err_msg("INVALID");
	num_ants = ft_atoi(s);
	free(s);
	printf("num_ants = %d\n", num_ants);
	
	/*INITIALIZE ROOMS*/
	num_rooms = 0;
	head = NULL;
	while (1)
	{
		type = 0;
		while (1)
		{
			get_next_line(0, &s);
			if (s[0] != '#')
				break ;
			if (!ft_strcmp(s, "##start"))
				type = 1;
			if (!ft_strcmp(s, "##end"))
				type = 2;
			free(s);
		}
		if (ft_find_index(s, ' ') < 0)
			break ;
		append_head(&head, s, type);
		ft_putendl(s);
		num_rooms++;
		//printf("find_index(s, ' ') = %d\n", ft_find_index(s, ' '));
		free(s);
	}
	//print_rooms(head);
	printf("num_rooms = %d\n", num_rooms);

	arr_rooms = (t_room **)malloc(sizeof(t_room *) * (num_rooms + 1));
	i = 0;
	while (head)
	{
		arr_rooms[i] = head;
		head = head->next;
		i++;
	}
	arr_rooms[i] = NULL;

	/*SET LINKS*/
	links = ft_strnew(1024);
	if (s[0] != '#')
	{
		inc_num_links(arr_rooms, s);
		links = str_cat_char(links, s, ' ');
		//ft_putendl(links);
	}
	free(s);
	while (1)
	{
		while (1)
		{
			get_next_line(0, &s);
			if (s[0] != '#')
				break ;
			free(s);
		}
		if (!s[0])
			break ;
		inc_num_links(arr_rooms, s);
		str_cat_char(links, s, ' ');
		//ft_putendl(s);
		free(s);
	}
	arr_links = ft_strsplit(links, ' ');
	free(links);
	i = 0;
	while (arr_links[i])
	{
		ft_putendl(arr_links[i]);
		i++;
	}
	ft_putchar('\n');
	i = -1;
	while (++i < num_rooms)
	{
		arr_rooms[i]->arr_links = (t_room **)malloc(sizeof(t_room *) * arr_rooms[i]->links);
		arr_rooms[i]->links = 0;
	}
	set_links(arr_rooms, arr_links);
	print_links(arr_rooms);

	find_path(arr_rooms, num_ants, num_rooms);
}