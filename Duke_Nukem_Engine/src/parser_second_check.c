/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_second_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:56:30 by vomelchu          #+#    #+#             */
/*   Updated: 2019/01/09 14:10:02 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	nut_to_sect(t_data *data, char **str, int len)
{
	int q;
	int max;

	q = 0;
	if (len == 11)
		max = 7;
	else
		max = 8;
	while (++q < max)
	{
		if (is_it_digit(str[q]) == 1 ||
			(q > 2 && (ft_atoi(str[q]) >= data->size_vert ||
			ft_atoi(str[q]) < 0)))
			ft_error1("bad_num vertex\n");
	}
}

void	check_walls(t_data *data, char **str, int len)
{
	int q;

	if (len == 11)
		q = 6;
	else
		q = 7;
	while (++q != len)
	{
		if (str[q][0] == '-' && str[q][1] == '1' && str[q][2] == '\0')
			continue;
		if (is_it_digit(str[q]) == 1 ||
			ft_atoi(str[q]) < 0 || ft_atoi(str[q]) >= data->count_sector)
			ft_error1("bad walls in sector\n");
	}
}

void	check_sect(t_data *data, char **str)
{
	int q;
	int len;

	q = -1;
	len = len_of_array(str);
	if (len != 11 && len != 13)
		ft_error1("bad line on sector\n");
	if (ft_atoi(str[2]) - ft_atoi(str[1]) > 100 ||
		ft_atoi(str[2]) < ft_atoi(str[1]))
		ft_error1("bad floor ceil\n");
	nut_to_sect(data, str, len);
	check_walls(data, str, len);
}

void	check_vertex(char **str)
{
	int q;

	q = 0;
	while (str[++q])
	{
		if (is_it_digit(str[q]) == 1)
			ft_error1("bad vertex dig\n");
	}
}

void	second_checking(t_data *data, char **reading)
{
	int		q;
	char	**str;
	int		i;

	q = -1;
	while (reading[++q] != NULL)
	{
		str = ft_strsplit(reading[q], ' ');
		if (str[0] == NULL)
			continue;
		if (ft_strcmp(str[0], "sector") == 0)
			check_sect(data, str);
		if (ft_strcmp(str[0], "vertex") == 0)
			check_vertex(str);
		i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
	}
}
