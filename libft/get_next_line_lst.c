/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:42:37 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/09 11:04:20 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*temp;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!head)
		head = ft_lstnew_content_malloc((BUFF_SIZE + 1), fd);
	temp = head;
	while ((int)temp->content_size != fd && temp->next)
		temp = temp->next;
	if ((int)temp->content_size != fd)
	{
		temp->next = ft_lstnew_content_malloc((BUFF_SIZE + 1), fd);
		temp = temp->next;
	}
	return (gnl_main_loop(fd, line, (char **)&(temp->content)));
}
