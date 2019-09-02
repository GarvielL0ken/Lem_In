/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:30:49 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/26 14:24:31 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_str(char const *s, char c, int start)
{
	int		len;
	int		i;
	char	*str;

	i = start;
	while (s[i] != c && s[i] != '\0')
		i++;
	i--;
	len = i - start + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
