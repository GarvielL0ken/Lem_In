/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:12:06 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/25 14:55:28 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *buff;

	buff = (unsigned char *)s;
	while (0 < n)
	{
		if (*buff == (unsigned char)c)
			return (buff);
		buff++;
		n--;
	}
	return (NULL);
}
