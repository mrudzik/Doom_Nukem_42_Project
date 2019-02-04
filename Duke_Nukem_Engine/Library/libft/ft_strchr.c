/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:16:19 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:19:22 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	*src;

	index = 0;
	src = (char*)s;
	while (src[index] != '\0' && src[index] != (char)c)
		index++;
	if (src[index] == (char)c)
		return (&src[index]);
	return (NULL);
}
