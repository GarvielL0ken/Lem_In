/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:55:03 by jsarkis           #+#    #+#             */
/*   Updated: 2019/06/10 16:57:35 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_find_index(char *str, char to_find)
{
	int pos;

	pos = 0;
	while (str[pos] != to_find && str[pos] != '\0')
		pos++;
	if (str[pos] == '\0' && to_find != '\0')
		pos = -1;
	return (pos);
}
