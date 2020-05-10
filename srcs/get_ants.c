/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:07:18 by jsarkis           #+#    #+#             */
/*   Updated: 2020/05/10 15:56:57 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int	get_ants(void)
{
	t_str	s;
	int		num_ants;

	while (1)
	{
		get_next_line(0, &s);
		ft_putendl(s);
		if (s[0] != '#')
			break ;
		free(s);
	}
	if (!is_integer(s))
		print_err_msg("Error: Number of ants not a valid integer");
	num_ants = ft_atoi(s);
	free(s);
	return (num_ants);
}
