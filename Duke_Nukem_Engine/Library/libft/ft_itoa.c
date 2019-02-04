/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:43:47 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/12 16:54:41 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	calc_nums(int n)
{
	int	nums;

	nums = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		nums++;
	}
	return (nums);
}

static char	*assgn_nums(int n, int end, char *res)
{
	if (n < 0)
	{
		res[0] = '-';
		end++;
		while (end != 1)
		{
			res[end-- - 1] = ((n % 10) * -1) + '0';
			n = n / 10;
		}
	}
	else
	{
		while (end != 0)
		{
			res[end-- - 1] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		nums;
	char	*res;

	nums = calc_nums(n);
	if (n < 0)
		res = ft_strnew(nums + 1);
	else
		res = ft_strnew(nums);
	if (res == NULL)
		return (NULL);
	else
		res = assgn_nums(n, nums, res);
	return (res);
}
