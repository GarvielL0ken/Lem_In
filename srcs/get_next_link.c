/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 09:57:12 by jsarkis           #+#    #+#             */
/*   Updated: 2020/05/04 10:58:30 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	get_next_link(t_data *data)
{
	while (1)
	{
		get_next_line(0, &data->s);
		ft_putendl(data->s);
		if (data->s[0] != '#')
			break ;
		free(data->s);
	}
}