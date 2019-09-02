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

int	valid_chars(t_str s, const t_str valid)
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

int	main()
{
	t_str	s;
	int		num_ants;

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
		ft_putendl(s);
		//printf("find_index(s, ' ') = %d\n", ft_find_index(s, ' '));
		free(s);
	}

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
