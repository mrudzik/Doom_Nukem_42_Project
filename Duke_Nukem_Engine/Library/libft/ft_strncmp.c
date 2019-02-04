/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:27:10 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 17:24:30 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			index;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	index = 0;
	while (src1[index] != '\0' && src2[index] != '\0' &&
			src1[index] == src2[index] && index < n - 1)
		index++;
	return (src1[index] - src2[index]);
}
