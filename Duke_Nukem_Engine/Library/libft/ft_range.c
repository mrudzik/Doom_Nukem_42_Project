/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:55:27 by mrudzik           #+#    #+#             */
/*   Updated: 2018/03/22 14:31:25 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	nums;
	int index;
	int *range;

	if (min >= max)
		return (NULL);
	nums = max - min;
	if (nums == 1)
	{
		range = &min;
		return (range);
	}
	range = malloc(nums * sizeof(int));
	index = 0;
	while (index < nums)
	{
		range[index] = min + index;
		index++;
	}
	return (range);
}
