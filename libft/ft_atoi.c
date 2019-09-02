/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:39:28 by jsarkis           #+#    #+#             */
/*   Updated: 2019/06/14 16:00:45 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_loop_for_atoi(const char *str, int i, int negative)
{
	long n;

	n = 0;
	while (str[i] != '\0' && (ft_isdigit(str[i])))
	{
		n = n + str[i] - '0';
		if ((n * 10) < 0)
		{
			if (negative > 0)
				return (-1);
		}
		n = n * 10;
		i++;
	}
	n = (n / 10) * negative;
	return (n);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		valid;
	int		negative;

	negative = 1;
	i = 0;
	valid = 1;
	while (ft_is_white_space(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (ft_loop_for_atoi(str, i, negative));
}
