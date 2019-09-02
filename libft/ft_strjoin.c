/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:57:18 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/30 14:14:13 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	int		i;
	char	*str_new;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str_new = malloc(len_1 + len_2 + 1);
	if (!str_new)
		return (NULL);
	i = 0;
	while (i < len_1 + len_2)
	{
		if (i < len_1)
			str_new[i] = s1[i];
		else
			str_new[i] = s2[i - len_1];
		i++;
	}
	str_new[len_1 + len_2] = '\0';
	return (str_new);
}
