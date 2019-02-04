/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:48:28 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:16:45 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *copy;

	if ((copy = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((copy->content = malloc(content_size * sizeof(void*))) == NULL)
	{
		free(copy);
		return (NULL);
	}
	if (content == '\0')
	{
		copy->content_size = 0;
		copy->content = NULL;
	}
	else
	{
		ft_memmove(copy->content, content, content_size);
		copy->content_size = content_size;
	}
	copy->next = NULL;
	return (copy);
}
