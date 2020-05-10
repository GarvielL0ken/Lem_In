/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:36:05 by jsarkis           #+#    #+#             */
/*   Updated: 2020/05/10 15:51:26 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	free_arr(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_rooms(t_room **arr_rooms)
{
	int		i;

	i = -1;
	while (arr_rooms[++i])
	{
		free(arr_rooms[i]->arr_links);
		free(arr_rooms[i]->name);
	}
}
