/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:44:47 by mrudzik           #+#    #+#             */
/*   Updated: 2018/09/13 12:14:15 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi2(const char *str, int menos, size_t index)
{
	size_t	res;

	res = 0;
	while (ft_isdigit(str[index]) == 1)
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& (str[index] - '0') > 7)) && menos == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
		&& (str[index] - '0') > 8)) && menos == -1)
			return (0);
		res = (res * 10) + (str[index++] - '0');
	}
	res = res * menos;
	return (res);
}

int		ft_atoi(const char *str)
{
	size_t	index;
	int		menos;
	size_t	res;

	menos = 1;
	index = 0;
	while ((8 < str[index] && str[index] < 14) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			menos = -1;
		index++;
	}
	res = ft_atoi2(str, menos, index);
	return (res);
}
