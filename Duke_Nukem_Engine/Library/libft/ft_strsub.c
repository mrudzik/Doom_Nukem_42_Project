/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:53:29 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 18:02:54 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*sub;

	if (!s)
		return (NULL);
	if ((sub = ft_strnew(len)) == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		sub[index] = s[start];
		index++;
		start++;
	}
	return (sub);
}
