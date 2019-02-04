/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:37:43 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 12:59:18 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	index;
	char	*dst;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	index = 0;
	dst = ft_strnew(len);
	if (dst == NULL)
		return (NULL);
	while (len--)
	{
		dst[index] = f(index, s[index]);
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
