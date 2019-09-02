/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:11:53 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/23 16:21:22 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t len_src;

	len_src = ft_strlen(src);
	dst = ft_strncpy(dst, src, len_src);
	dst[len_src] = '\0';
	return (dst);
}
