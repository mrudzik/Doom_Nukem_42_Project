/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:42:28 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 13:59:35 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t index;

	if (s)
	{
		index = 0;
		while (s[index] != '\0')
		{
			ft_putchar(s[index]);
			index++;
		}
	}
}
