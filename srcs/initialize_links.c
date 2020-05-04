/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:14:33 by jsarkis           #+#    #+#             */
/*   Updated: 2020/05/04 11:42:54 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	compare_name(t_data *data, t_str *rooms, t_str name)
{
	data->room_1 = 0;
	data->room_2 = 0;
	if (ft_strequ(name, rooms[0]))
		data->room_1++;
	if (ft_strequ(name, rooms[1]))
		data->room_2++;
	if (data->room_1 && data->room_2)
		print_err_msg("Error: Room links to itself");
}

void	inc_num_links(t_room **arr_rooms, t_str s)
{
	int		i;
	int		found;
	t_data	data;
	t_str	*rooms;

	i = 0;
	rooms = ft_strsplit(s, '-');
	found = 0;
	while (arr_rooms[i])
	{
		compare_name(&data, rooms, arr_rooms[i]->name);
		if (data.room_1 || data.room_2)
		{
			arr_rooms[i]->links += 1;
			found++;
		}
		if (found == 2)
			break ;
		i++;
	}
	if (!arr_rooms[i])
		print_err_msg("Error: Room does not exist");
	free_arr((void **)rooms);
}

void	str_cat_char(t_str *dst, t_str src, char c)
{
	int	len;
	int	i;

	len = ft_strlen(*dst);
	i = 0;
	while (src[i])
	{
		(*dst)[len + i] = src[i];
		i++;
	}
	(*dst)[len + i] = c;
	(*dst)[len + i + 1] = '\0';
}

t_str	*read_links(t_data *data, t_room ***arr_rooms)
{
	t_str	links;
	t_str	*arr_links;

	links = ft_strnew(STR_SIZE);
	if (data->s[0] != '#')
	{
		inc_num_links(*arr_rooms, data->s);
		str_cat_char(&links, data->s, ' ');
	}
	free(data->s);
	while (1)
	{
		get_next_link(data);
		if (!data->s[0])
			break ;
		inc_num_links(*arr_rooms, data->s);
		str_cat_char(&links, data->s, ' ');
		free(data->s);
	}
	free(data->s);
	arr_links = ft_strsplit(links, ' ');
	free(links);
	return (arr_links);
}

void	malloc_links(t_room ***arr_rooms, t_data data)
{
	t_uint	i;
	t_uint	n;

	i = 0;
	while (i < data.num_rooms)
	{
		n = (*arr_rooms)[i]->links;
		(*arr_rooms)[i]->arr_links = (t_room **)malloc(sizeof(t_room *) * n);
		(*arr_rooms)[i]->links = 0;
		i++;
	}
}

void	set_links(t_room **arr_rooms, t_str *arr_links)
{
	t_str	*current_rooms;
	int		i;
	int		j;
	int		k;
	int		tmp;

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
