/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_first_checking.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:48:45 by vomelchu          #+#    #+#             */
/*   Updated: 2019/01/11 17:02:45 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

int		is_it_norm_other(t_data *data, char **str)
{
	if (ft_strcmp(str[0], "door_sector") == 0
			|| ft_strcmp(str[0], "end") == 0 || ft_strcmp(str[0], "lift") == 0)
	{
		if (len_of_array(str) == 2
			&& is_it_digit(str[1]) == 0 && ft_atoi(str[1]) >= 0 &&
			ft_atoi(str[1]) < data->count_sector)
			return (0);
		else
			ft_error1("bad lift || door || sector\n");
	}
	else if (ft_strcmp(str[0], "enemy") == 0)
	{
		if (len_of_array(str) == 4 && is_it_digit(str[1]) == 0
			&& is_it_digit(str[2]) == 0 && is_it_digit(str[3]) == 0
			&& ft_atoi(str[3]) >= 0 && ft_atoi(str[3]) < data->count_sector)
			return (0);
	}
	else if (ft_strcmp(str[0], "texture_sector") == 0)
	{
		if (len_of_array(str) == 3 && ft_atoi(str[1]) >= 0 && ft_atoi(str[1])
			< data->count_sector && ft_atoi(str[2]) >= 0
			&& ft_atoi(str[2]) <= 6)
			return (0);
	}
	return (1);
}

void	check_name(t_data *data, char **str)
{
	if (ft_strcmp(str[0], "vertex") == 0)
	{
		data->size_vert += len_of_array(str) - 2;
		data->count_vert++;
	}
	else if (ft_strcmp(str[0], "sector") == 0)
		data->count_sector++;
	else if (ft_strcmp(str[0], "player") == 0 && is_it_norm(data, str) == 0)
		data->count_play++;
	else if (ft_strcmp(str[0], "key") == 0 && is_it_norm(data, str) == 0)
		data->count_key++;
	else if (ft_strcmp(str[0], "ammunition") == 0 && is_it_norm(data, str) == 0)
		data->count_ammun++;
	else if (ft_strcmp(str[0], "door_sector") == 0 && NORM)
		data->count_door++;
	else if (ft_strcmp(str[0], "enemy") == 0 && NORM)
		data->count_enemy++;
	else if (ft_strcmp(str[0], "end") == 0 && NORM)
		data->count_end++;
	else if (ft_strcmp(str[0], "lift") == 0 && NORM)
		data->count_lift++;
	else if (ft_strcmp(str[0], "texture_sector") == 0 & NORM)
		data->count_text++;
	else
		ft_error1("Huston, we have a problem\n");
}

void	check_vet_sect(t_data *data)
{
	if (data->size_vert > data->count_sector * 5)
		ft_error1("not norm vertex_sector\n");
	if (data->count_play != 1 || data->count_end != 1)
		ft_error1("bad start || end\n");
	if (data->count_text != data->count_sector)
		ft_error1("texture_sector != sector\n");
}

void	count_all(t_data *data, char **reading)
{
	char	**str;
	int		q;
	int		i;

	q = -1;
	while (reading[++q] != NULL)
	{
		str = ft_strsplit(reading[q], ' ');
		if (str[0] == NULL)
			continue;
		check_name(data, str);
		i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
	}
	check_vet_sect(data);
}

void	init_count(t_data *data)
{
	data->count_vert = 0;
	data->count_sector = 0;
	data->count_play = 0;
	data->count_key = 0;
	data->count_ammun = 0;
	data->count_door = 0;
	data->count_lift = 0;
	data->count_end = 0;
	data->count_enemy = 0;
	data->count_text = 0;
	data->size_vert = 0;
}
