/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:46:34 by jsarkis           #+#    #+#             */
/*   Updated: 2020/03/19 19:46:34 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

void		append_line(int ant_number, t_str name, t_str *line, t_uint *line_length)
{
	t_uint	new_length;
	t_str	str_ant_number;
	int		i;
	int		j;

	new_length = ft_strlen(*line) + 3 + ft_order((long)ant_number) + ft_strlen(name);
	if ((*line_length / STR_SIZE < new_length / STR_SIZE))
		ft_str_realloc(line, ((new_length / STR_SIZE) * STR_SIZE));
	(*line)[*line_length] = 'L';
	str_ant_number = ft_itoa((int)ant_number);
	i = -1;
	while (str_ant_number[++i])
		(*line)[*line_length + 1 + i] = str_ant_number[i];
	(*line)[*line_length + 1 + i] = '-';
	j = -1;
	while (name[++j])
		(*line)[*line_length + 2 + i + j] = name[j];
	(*line)[*line_length + 2 + i + j] = ' ';
	*line_length = new_length;
	free(str_ant_number);
	str_ant_number = NULL;
}

void		print_moves(t_path_set path_set, t_path **arr_paths, int num_ants, t_room **arr_rooms)
{
	t_str	line;
	t_uint	line_length;
	int	move_number;
	int	ant_number;
	int	index;

	move_number = 0;
	line = ft_strnew(STR_SIZE);
	while (++move_number <= path_set.num_moves)
	{
		line_length = 0;
		ant_number = 0;
		index = move_number;
		while (++ant_number <= num_ants && index)
		{
			if (index <= arr_paths[(ant_number % path_set.num_paths)]->path_length)
				append_line(ant_number, arr_rooms[arr_paths[(ant_number % path_set.num_paths)]->arr_path[index]]->name, &line, &line_length);
			if (!(ant_number % path_set.num_paths))
				index--;
		}
		ft_putstr(line);
		while(--line_length > 0)
			line[line_length] = 0;
		line[0] = 0;
		ft_putchar('\n');
	}
	free(line);
}

void		move_ants(t_path_set path_set, t_path *head, int num_ants, t_room **arr_rooms)
{
	t_path	**arr_paths;
	t_path	*temp;
	int		i;
	int		j;

	arr_paths = (t_path **)malloc(sizeof(t_path *) * path_set.num_paths);
	i = 0;
	temp = head;
	while (i < path_set.num_paths)
	{
		j = 0;
		temp = head;
		while (j++ < path_set.arr_paths[i])
			temp = temp->next;
		arr_paths[i] = temp;
		print_path(arr_paths[i], arr_rooms);
		i++;
	}
	print_moves(path_set, arr_paths, num_ants, arr_rooms);
	free(arr_paths);
}
