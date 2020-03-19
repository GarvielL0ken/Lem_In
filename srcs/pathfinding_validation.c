/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 23:09:27 by jsarkis           #+#    #+#             */
/*   Updated: 2020/03/19 23:09:27 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

int			num_moves(t_path_set path_set, t_path *head, int num_ants, t_room **arr_rooms)
{
	t_path	*current;
	t_uint	*arr_lengths;
	int		i;
	int		j;
	int		min;

	arr_lengths = (t_uint *)malloc(sizeof(t_uint) * path_set.num_paths);
	i = 0;
	min = -1;
	while (i < path_set.num_paths)
	{
		j = 0;
		current = head;
		while (j++ < path_set.arr_paths[i])
			current = current->next;
		if (current->path_length < min || min == -1)
			min = current->path_length;
		print_path(current, arr_rooms);
		arr_lengths[i] = current->path_length;
		i++;
	}
	printf("min = %d\nnum_ants = %d\n", min, num_ants);
	for (i = 0; i < path_set.num_paths; i++)
		printf("%d, ", arr_lengths[i]);
	printf("\n");
	j = 0;
	while (num_ants > 0)
	{
		for (i = 0; i < path_set.num_paths; i++)
		{
			if (arr_lengths[i] <= (t_uint)num_ants || arr_lengths[i] == (t_uint) min)
				num_ants--;
		}
		j++;
	}
	free(arr_lengths);
	return (j + min - 1);
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
