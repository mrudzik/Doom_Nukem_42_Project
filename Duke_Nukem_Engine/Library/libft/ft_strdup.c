/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:27:12 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 17:16:11 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		size;

	size = ft_strlen(s1);
	if ((res = ft_strnew(size)) == NULL)
		return (NULL);
	ft_memcpy(res, s1, size);
	return (res);
}
