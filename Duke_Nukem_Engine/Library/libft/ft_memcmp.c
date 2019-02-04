/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:25:58 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 15:12:03 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	index = 0;
	if (n == 0)
		return (0);
	while (src1[index] == src2[index] && index < n - 1)
		index++;
	return (src1[index] - src2[index]);
}
