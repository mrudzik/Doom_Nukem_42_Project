/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:28:08 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 17:24:59 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = -1;
	while (++index < len && src[index] != '\0')
		dst[index] = src[index];
	while (index < len)
		dst[index++] = '\0';
	return (dst);
}
