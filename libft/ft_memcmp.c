/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:29:54 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/22 19:33:07 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	while (i < n)
	{
		diff = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (diff != 0)
			return (diff);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
