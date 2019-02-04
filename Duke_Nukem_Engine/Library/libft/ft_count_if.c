/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:58:14 by mrudzik           #+#    #+#             */
/*   Updated: 2018/03/22 20:00:23 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char *))
{
	int		index;
	int		times;

	index = 1;
	times = 0;
	while (tab[index] != 0)
	{
		if (f(tab[index]) == 1)
			times++;
		index++;
	}
	return (times);
}
