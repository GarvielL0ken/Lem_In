/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 09:52:04 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/09 11:04:51 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_main_loop(const int fd, char **line, char **buff)
{
	int	i;
	int end_of_line;
	int	read_ret;

	*line = ft_strnew(1000 * 100);
	i = 0;
	end_of_line = 0;
	while (!end_of_line)
	{
		if (!ft_find_index(*buff, '\0'))
			read_ret = read(fd, *buff, BUFF_SIZE);
		else
			read_ret = BUFF_SIZE;
		*(*buff + read_ret) = '\0';
		if (read_ret)
			i = ft_strncpyi(line, *buff, ft_find_index(*buff, '\n'), i);
		if (read_ret != BUFF_SIZE || ft_find_index(*buff, '\n') != -1)
			end_of_line = 1;
		prep_buff(buff);
	}
	return ((read_ret || i));
}
