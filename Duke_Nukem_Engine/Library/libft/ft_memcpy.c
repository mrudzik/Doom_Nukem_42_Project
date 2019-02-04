/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:02:48 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 16:07:21 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	index = -1;
	while (++index < n)
	{
		d[index] = s[index];
	}
	return (dst);
}
