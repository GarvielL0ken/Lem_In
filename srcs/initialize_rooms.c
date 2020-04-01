/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:07:36 by jsarkis           #+#    #+#             */
/*   Updated: 2020/01/13 13:11:21 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

void	append_head(t_room **head, t_str s, unsigned int type)
{
	t_room	*new;
	t_str	*arr_data;

	new = *head;
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
	if (!is_integer(arr_data[1]) || !is_integer(arr_data[2]))
		print_err_msg("Error: Co-ordinate is not a valid integer");
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

t_room	**initialize_rooms(t_data *data)
{
	t_room			**arr_rooms;
	t_room			*head;
	unsigned int	type;
	int				i;

	data->num_rooms = 0;
	head = NULL;
	while (1)
	{
		type = 0;
		while (1)
		{
			i = get_next_line(0, &(data->s));
			ft_putendl(data->s);
			if (!i)
				print_err_msg("Error: No links specified");
			if (data->s[0] != '#')
				break ;
			if (!ft_strcmp(data->s, "##start"))
				type = START;
			if (!ft_strcmp(data->s, "##end"))
				type = END;
			free(data->s);
		}
		if (ft_find_index(data->s, ' ') == -1)
			break ;
		if (count_occurrences(data->s, ' ') != 2)
			print_err_msg("Error: Invalid syntax for room");
		if (data->s[0] == 'L')
			print_err_msg("Error: Room name starts with an 'L'");
		append_head(&head, data->s, type);
		data->num_rooms++;
		free(data->s);
	}
	if (!data->num_rooms)
		print_err_msg("Error: No rooms specified");
	arr_rooms = (t_room **)malloc(sizeof(t_room *) * (data->num_rooms + 1));
	i = 0;
	while (head)
	{
		arr_rooms[i] = head;
		head = head->next;
		i++;
	}
	free(head);
	arr_rooms[i] = NULL;
	return (arr_rooms);
}
