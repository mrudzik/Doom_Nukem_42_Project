/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:41:15 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:16:17 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*res;

	if ((res = (char*)malloc(size * sizeof(char))) == NULL)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
