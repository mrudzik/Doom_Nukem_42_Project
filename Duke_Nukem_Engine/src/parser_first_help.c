/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_first_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:04:02 by vomelchu          #+#    #+#             */
/*   Updated: 2019/01/11 17:04:03 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

int		len_of_array(char **str)
{
	int q;

	q = -1;
	while (str[++q] != NULL)
		;
	return (q);
}

int		is_it_digit(char *str)
{
	int q;

	q = -1;
	while (str[++q])
	{
		if (str[q] == '-')
			continue;
		if (str[q] < '0' || str[q] > '9')
			return (1);
		if (q > 3)
			return (1);
	}
	return (0);
}

int		is_it_norm(t_data *data, char **str)
{
	int q;

	q = 0;
	if ((ft_strcmp(str[0], "player") == 0 || (ft_strcmp(str[0], "key") == 0)
				|| (ft_strcmp(str[0], "ammunition") == 0))
			&& len_of_array(str) == 5)
	{
		while (str[++q] != NULL)
			if (is_it_digit(str[q]) == 1)
				ft_error1("bad digit\n");
		if (ft_atoi(str[4]) >= data->count_sector || ft_atoi(str[4]) < 0)
			ft_error1("bad num sector\n");
		if (((ft_strcmp(str[0], "key") == 0) || (ft_strcmp(str[0], "key") == 0))
				&& (ft_atoi(str[1]) < 0 || ft_atoi(str[1]) > 3))
			ft_error1("bad num of type\n");
		return (0);
	}
	else
		ft_error1("bad player\n");
	return (1);
}
