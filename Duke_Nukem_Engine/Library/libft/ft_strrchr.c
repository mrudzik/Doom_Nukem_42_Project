/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:41:07 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:20:40 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*src;
	size_t	last;

	index = 0;
	last = 0;
	src = (char*)s;
	while (src[index] != '\0')
	{
		if (src[index] == (char)c)
			last = index;
		index++;
	}
	if (src[index] == (char)c)
		last = index;
	if (src[last] == (char)c)
		return (&src[last]);
	return (NULL);
}
