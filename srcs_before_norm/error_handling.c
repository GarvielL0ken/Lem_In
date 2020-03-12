/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:21:21 by jsarkis           #+#    #+#             */
/*   Updated: 2019/10/24 16:45:37 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

void	print_err_msg(const t_str err_msg)
{
	ft_putendl_fd(err_msg, 2);
	exit(1);
}

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
		print_err_msg("Error: No start and/or no end room");
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
