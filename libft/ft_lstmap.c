/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:13:14 by jsarkis           #+#    #+#             */
/*   Updated: 2019/06/14 13:46:03 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;

	head = NULL;
	if (lst)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			return (NULL);
		head = f(lst);
		head->next = ft_lstmap(lst->next, f);
	}
	return (head);
}
