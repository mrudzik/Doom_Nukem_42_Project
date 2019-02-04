/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:54:01 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:19:43 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	index = 0;
	while (src1[index] == src2[index] && (src1[index] != '\0' ||
				src2[index] != '\0'))
		index++;
	return (src1[index] - src2[index]);
}
