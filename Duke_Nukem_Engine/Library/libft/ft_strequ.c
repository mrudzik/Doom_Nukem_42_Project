/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:02:30 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 16:24:56 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
	{
		if (s1 == s2)
			return (1);
		return (0);
	}
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
