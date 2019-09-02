/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_content_malloc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:33:41 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/03 13:36:09 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_content_malloc(size_t size, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = ft_strnew(size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
