/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:43:21 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/02 18:44:56 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_str_shift(char *str, int shift_size)
{
	int	i;

	i = 0;
	while (str[shift_size])
	{
		str[i] = str[shift_size];
		i++;
		shift_size++;
	}
	str[i] = '\0';
	return (str);
}
