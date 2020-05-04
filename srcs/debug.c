/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:56:43 by jsarkis           #+#    #+#             */
/*   Updated: 2020/05/04 11:42:34 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	print_rooms(t_room *head)
{
	while (head)
	{
		printf("name = %s, x  = %d, y = %d\n", head->name, head->x, head->y);
		head = head->next;
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

void	print_path(t_path *head, t_room **arr_rooms)
{
	int	i;

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
