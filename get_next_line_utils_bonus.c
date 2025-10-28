/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:11:14 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/29 01:11:21 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

ssize_t	min(ssize_t a, ssize_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void *const	dest_o = dest;

	while (n)
	{
		--n;
		*(unsigned char *)(dest++) = *(unsigned char *)(src++);
	}
	return (dest_o);
}

struct s_gnl_buf_list	*gnl_lstnew(void)
{
	struct s_gnl_buf_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->bytes_read = 0;
	lst->next = NULL;
	return (lst);
}

struct s_gnl_buf_list	*gnl_lstadd_next(struct s_gnl_buf_list *lst,
	struct s_gnl_buf_list *new)
{
	if (lst)
		(lst)->next = new;
	lst = new;
	return (new);
}

struct s_gnl_buf_list	*gnl_delhead(struct s_gnl_buf_list **head)
{
	struct s_gnl_buf_list *const	next = (*head)->next;

	free(*head);
	*head = next;
	return (next);
}
