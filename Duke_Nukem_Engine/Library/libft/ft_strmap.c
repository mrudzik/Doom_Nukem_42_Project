/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:59:05 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 13:01:38 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		dst[index] = f(s[index]);
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
