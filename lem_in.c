/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:04:59 by jsarkis           #+#    #+#             */
/*   Updated: 2019/09/02 15:05:01 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	print_rooms(t_room *head)
{
	while (head)
	{
		printf("name = %s, x  = %d, y = %d\n", head->name, head->x, head->y);
		head = head->next;
	}
}

int		valid_chars(t_str s, const t_str valid)
{
	int i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (valid[j])
		{
			if (s[i] == valid[j])
				break ;
			j++;
		}
		if (!valid[j])
			return (0);
		i++;
	}
	return (1);
}

void	free_arr(void	**arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	append_head(t_room **head, t_str s)
{
	t_room	*new;
	t_str	*arr_data;

	new  = *head;
	if (!*head)
		new = (t_room *)malloc(sizeof(t_room));
	else
	{
		while (new->next)
			new = new->next;
		new->next = (t_room *)malloc(sizeof(t_room));
		new = new->next;
	}
	arr_data = ft_strsplit(s, ' ');
	new->name = ft_strdup(arr_data[0]);
	new->x = ft_atoi(arr_data[1]);
	new->y = ft_atoi(arr_data[2]);
	new->next = NULL;
	free_arr((void **)arr_data);
	if (!*head)
		*head = new;
}

int		main()
{
	t_room	*head;
	t_str	s;
	int		num_ants;
	int		num_rooms;

	/*GET NUMBER OF ANTS*/
	while (1)
	{
		get_next_line(0, &s);
		if (s[0] != '#')
			break ;
		free(s);
	}
	if (!valid_chars(s, "0123456789"))
		print_err_msg("INVALID");
	num_ants = ft_atoi(s);
	free(s);
	printf("num_ants = %d\n", num_ants);
	
	/*INITIALIZE ROOMS*/
	num_rooms = 0;
	head = NULL;
	while (1)
	{
		while (1)
		{
			get_next_line(0, &s);
			if (s[0] != '#')
				break ;
			free(s);
		}
		if (ft_find_index(s, ' ') < 0)
			break ;
		append_head(&head, s);
		ft_putendl(s);
		num_rooms++;
		//printf("find_index(s, ' ') = %d\n", ft_find_index(s, ' '));
		free(s);
	}
	//print_rooms(head);
	printf("num_rooms = %d\n", num_rooms);

	/*SET LINKS*/
	if (s[0] != '#')
		ft_putendl(s);
	free(s);
	while (1)
	{
		while (1)
		{
			get_next_line(0, &s);
			if (s[0] != '#')
				break ;
			free(s);
		}
		if (!s[0])
			break ;
		ft_putendl(s);
		free(s);
	}
}
