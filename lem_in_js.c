/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_js.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:34:20 by jsarkis           #+#    #+#             */
/*   Updated: 2019/10/06 13:52:28 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_js.h"

void	check_start_end_rooms(t_room **arr_rooms, t_data data)
{
	t_uint	i;
	t_uint	start;
	t_uint	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < data.num_rooms)
	{
		if (arr_rooms[i]->type == 1)
			start++;
		if (arr_rooms[i]->type == 2)
			end++;
		if (start > 1 || end > 1)
			print_err_msg("Error: Multiple start or end rooms");
		i++;
	}
	if (!start || !end)
		print_err_msg("Error: No start or end room");
}

void	check_coordinates(t_room **arr_rooms)
{
	t_uint	i;
	t_uint	j;
	t_uint	x;
	t_uint	y;

	i = 0;
	while (arr_rooms[i])
	{
		j = i + 1;
		x = arr_rooms[i]->x;
		y = arr_rooms[i]->y;
		while (arr_rooms[j])
		{
			if (x == arr_rooms[j]->x && y == arr_rooms[j]->y)
				print_err_msg("Error: Rooms have the same co-ordinates");
			j++;
		}
		i++;
	}
}

void	validate_rooms(t_room **arr_rooms, t_data data)
{
	check_start_end_rooms(arr_rooms, data);
	check_coordinates(arr_rooms);
}

int		main(void)
{
	t_room			**arr_rooms;
	t_str			*arr_links;
	t_data			data;

	data.num_ants = get_ants();
	arr_rooms = NULL;
	initialize_rooms(&data, &arr_rooms);
	validate_rooms(arr_rooms, data);
	check_start_end_rooms(arr_rooms, data);
	arr_links = read_links(&data, &arr_rooms);
	malloc_links(&arr_rooms, data);
	set_links(arr_rooms, arr_links);
	find_path(arr_rooms, data.num_ants, data.num_rooms);
	free_arr((void **)arr_links);
	while (1);
}
