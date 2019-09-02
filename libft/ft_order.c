/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:05:05 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/25 14:19:12 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_order(long n)
{
	int negative;

	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	if (n >= 10)
		return (ft_order(n / 10) + 1 + negative);
	else
		return (1 + negative);
}
