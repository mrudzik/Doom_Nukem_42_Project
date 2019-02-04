/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:05:46 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:18:41 by mrudzik          ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (ft_halp(n) != 0)
		ft_putnbr_fd(ft_halp(n), fd);
	if (n < 0)
		ft_putchar_fd(((n % 10) * -1) + '0', fd);
	else
		ft_putchar_fd((n % 10) + '0', fd);
}
