/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:21:04 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/30 12:56:12 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*buff_dest;
	char	*buff_src;
	size_t	i;

	buff_dest = (char *)dest;
	buff_src = (char *)src;
	i = -1;
	if (!buff_dest && !buff_src)
		return (0);
	while (++i < n)
		*(buff_dest + i) = *(buff_src + i);
	return (dest);
}
