/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:34:20 by jsarkis           #+#    #+#             */
/*   Updated: 2020/05/10 15:53:34 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_room	**arr_rooms;
	t_str	*arr_links;
	t_data	data;

	data.move_number = 0;
	data.num_ants = get_ants();
	arr_rooms = initialize_rooms(&data);
	validate_rooms(arr_rooms, data);
	arr_links = read_links(&data, &arr_rooms);
	malloc_links(&arr_rooms, data);
	set_links(arr_rooms, arr_links);
	find_path(arr_rooms, data);
	free_arr((void **)arr_links);
	free_rooms(arr_rooms);
	free_arr((void **)arr_rooms);;
}
