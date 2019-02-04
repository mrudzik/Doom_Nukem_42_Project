/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:56:39 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:25:13 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	ind1;
	size_t	ind2;
	size_t	start;
	char	*hay;

	hay = (char*)haystack;
	ind1 = -1;
	if (ft_strlen(needle) == 0)
		return (hay);
	while (hay[++ind1] != '\0')
	{
		if (hay[ind1] == needle[0])
		{
			start = ind1;
			ind2 = 0;
			while (needle[ind2] == hay[ind1++] && needle[ind2] != '\0')
				ind2++;
			if (needle[ind2] == '\0')
				return (&hay[start]);
			ind1 = start;
		}
	}
	return (NULL);
}
