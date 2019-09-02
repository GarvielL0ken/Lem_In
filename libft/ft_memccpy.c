/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:18:14 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/22 19:19:53 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*buff_dest;
	unsigned char	*buff_src;
	size_t			i;

	buff_dest = (unsigned char *)dest;
	buff_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		buff_dest[i] = buff_src[i];
		if (buff_src[i] == (unsigned char)c)
			return (buff_dest + i + 1);
		i++;
	}
	return (NULL);
}
