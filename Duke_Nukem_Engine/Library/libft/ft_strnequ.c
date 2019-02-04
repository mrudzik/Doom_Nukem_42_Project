/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:06:06 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 16:27:25 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
	{
		if (s1 == s2)
			return (1);
		return (0);
	}
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
