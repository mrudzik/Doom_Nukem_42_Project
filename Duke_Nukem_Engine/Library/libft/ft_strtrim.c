/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:17:09 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 16:57:18 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_white(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == ',')
		return (1);
	else
		return (0);
}

static char		*ft_isnull(void)
{
	char	*res;

	res = ft_strnew(1);
	res[0] = '\0';
	return (res);
}

char			*ft_strtrim(char const *s)
{
	size_t	index;
	size_t	start;
	size_t	len;
	char	*res;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	index = 0;
	while (ft_iswhite(s[index]) == 1)
		index++;
	if (s[index] == '\0')
		return (ft_isnull());
	start = index;
	while (len > 0 && ft_is_white(s[len]) == 1)
		len--;
	if ((res = ft_strnew(len - start + 1)) == NULL)
		return (NULL);
	index = 0;
	while (s[start] != '\0' && start <= len)
		res[index++] = s[start++];
	res[index] = '\0';
	return (res);
}
