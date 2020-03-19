/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_occurrences.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:07:21 by bswanepo          #+#    #+#             */
/*   Updated: 2020/03/19 20:06:50 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in_js.h"

int	count_occurrences(t_str s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	is_integer(t_str s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || '9' < s[i])
			return (0);
		i++;
	}
	return (1);
}
