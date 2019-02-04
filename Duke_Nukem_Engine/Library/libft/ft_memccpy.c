/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:07:48 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:17:28 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;
	char	*d;
	char	*s;
	char	symb;

	symb = c;
	d = (char*)dst;
	s = (char*)src;
	index = -1;
	while (++index < n)
	{
		d[index] = s[index];
		if (s[index] == symb)
			return (dst + index + 1);
	}
	return (NULL);
}
