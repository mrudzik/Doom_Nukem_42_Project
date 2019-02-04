/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:25:35 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 17:18:35 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ind1;
	size_t	ind2;
	size_t	buck;

	ind2 = 0;
	ind1 = 0;
	while (dst[ind1] != '\0' && ind1 < dstsize)
		ind1++;
	if (dstsize - ind1 == 0)
		return (ft_strlen(src) + ind1);
	buck = ind1;
	while (src[ind2] != '\0')
	{
		if (dstsize - (buck + ind2) > 1 && ind1 < dstsize - 1)
			dst[ind1++] = src[ind2];
		ind2++;
	}
	dst[ind1] = '\0';
	return (buck + ind2);
}
