/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:11:04 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:18:24 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_halp(int n)
{
	n = n / 10;
	if (n < 0)
		return (-n);
	return (n);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (ft_halp(n) != 0)
		ft_putnbr(ft_halp(n));
	if (n < 0)
		ft_putchar(((n % 10) * -1) + '0');
	else
		ft_putchar((n % 10) + '0');
}
