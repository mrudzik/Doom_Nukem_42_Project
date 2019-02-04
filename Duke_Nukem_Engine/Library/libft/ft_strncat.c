/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:06:31 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 20:15:23 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	ind1;
	size_t	ind2;

	ind2 = 0;
	ind1 = 0;
	while (s1[ind1] != '\0')
		ind1++;
	while (s2[ind2] != '\0' && ind2 < n)
	{
		s1[ind1++] = s2[ind2];
		ind2++;
	}
	s1[ind1] = '\0';
	return (s1);
}
