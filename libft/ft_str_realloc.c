/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:33:38 by jsarkis           #+#    #+#             */
/*   Updated: 2019/06/13 11:02:01 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_str_realloc(char **str, size_t size)
{
	size_t	i;
	char	*new;

	new = (char *)malloc(size);
	i = 0;
	while (*(*str + i) != '\0')
	{
		new[i] = *(*str + i);
		i++;
	}
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	free(*str);
	free(str);
	return (new);
}
