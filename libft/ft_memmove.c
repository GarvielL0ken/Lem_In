/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:57:34 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/26 12:54:22 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*buff_src;
	unsigned char	*buff_dest;
	size_t			i;

	i = -1;
	buff_src = (unsigned char *)src;
	buff_dest = (unsigned char *)dest;
	if (!buff_dest && !buff_src)
		return (NULL);
	if (buff_src < buff_dest)
		while ((int)(--len) >= 0)
			*(buff_dest + len) = *(buff_src + len);
	else
		while (++i < len)
			*(buff_dest + i) = *(buff_src + i);
	return (dest);
}
