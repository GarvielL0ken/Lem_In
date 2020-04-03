/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_queries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 23:22:00 by jsarkis           #+#    #+#             */
/*   Updated: 2020/04/03 09:25:03 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

t_uint		*calculate_lengths(t_path_set path_set, t_path *head, t_uint *min)
{
	t_path	*current;
	t_uint	*arr_lengths;
	t_uint	i;
	t_uint	j;
	
	arr_lengths = (t_uint *)malloc(sizeof(t_uint) * path_set.num_paths);
	if (!arr_lengths)
		print_err_msg("Malloc Failed\n");
	i = 0;
	*min = 0;
	while (i < path_set.num_paths)
	{
		j = 0;
		current = head;
		while (j++ < path_set.arr_paths[i])
			current = current->next;
		if (current->path_length < *min || *min == 0)
			*min = current->path_length;
		arr_lengths[i] = current->path_length;
		i++;
	}
	return (arr_lengths);
}

int			num_moves(t_path_set path_set, t_path *head, int num_ants)
{
	t_uint	*arr_lengths;
	t_uint	i;
	t_uint	j;
	t_uint	min;

	arr_lengths = calculate_lengths(path_set, head, &min);
	j = 0;
	while (num_ants > 0)
	{
		for (i = 0; i < path_set.num_paths; i++)
		{
			if (arr_lengths[i] <= (t_uint)num_ants || arr_lengths[i] == min)
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
