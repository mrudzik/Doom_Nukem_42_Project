/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:18:41 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 16:33:22 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	char			*src;
	char			symb;

	src = (char*)s;
	index = 0;
	symb = c;
	while (index < n)
	{
		if (src[index] == symb)
			return (&src[index]);
		index++;
	}
	return (NULL);
}
