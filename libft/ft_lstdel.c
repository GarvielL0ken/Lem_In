/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:48:00 by jsarkis           #+#    #+#             */
/*   Updated: 2019/05/30 14:01:31 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_current;
	t_list	*tmp_next;

	tmp_current = *alst;
	while (tmp_current)
	{
		tmp_next = tmp_current->next;
		ft_lstdelone(&tmp_current, del);
		tmp_current = tmp_next;
	}
	*alst = NULL;
}
