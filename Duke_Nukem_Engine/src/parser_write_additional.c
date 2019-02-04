/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_write_additional.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:37:57 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 14:58:08 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	parse_find_end(t_main_data *main, char **reading, int y)
{
	int *num_array;

	if (ft_strncmp("end ", reading[y], 4) == 0)
	{
		num_array = ft_intsplit(reading[y], ' ');
		SD[num_array[2]].end = 1;
		ft_intdel(&num_array);
	}
}

void	parse_find_texture(t_main_data *main, char **reading, int y)
{
	int *num_array;

	if (ft_strncmp("texture_sector ", reading[y], 15) == 0)
	{
		num_array = ft_intsplit(reading[y], ' ');
		SD[num_array[2]].texture_num = num_array[3];
		ft_intdel(&num_array);
	}
}

void	parse_find_doornlift(t_main_data *main, char **reading, int y)
{
	int *num_array;

	if (ft_strncmp("door_sector ", reading[y], 12) == 0)
	{
		num_array = ft_intsplit(reading[y], ' ');
		SD[num_array[2]].door = DOOR_CLOSED;
		SD[num_array[2]].ceil = SD[num_array[2]].floor;
		ft_intdel(&num_array);
	}
	if (ft_strncmp("lift ", reading[y], 5) == 0)
	{
		num_array = ft_intsplit(reading[y], ' ');
		SD[num_array[2]].lift = LIFT_DOWN;
		ft_intdel(&num_array);
	}
}

void	parser_write_additional(t_main_data *main, t_data *data,
	char **reading)
{
	int y;
	int sec_sprites[400];

	main->draw.num_sectors = (Uint32)data->count_sector;
	y = 0;
	while (y < (int)DR.num_sectors)
	{
		sec_sprites[y] = 0;
		y++;
	}
	sprite_loading(main);
	y = 0;
	while (reading[y] != NULL)
	{
		parse_find_end(main, reading, y);
		parse_find_texture(main, reading, y);
		parse_find_doornlift(main, reading, y);
		parse_find_items(main, reading, y, (int*)sec_sprites);
		parse_find_enemy(main, reading, y, (int*)sec_sprites);
		parse_find_key(main, reading, y, (int*)sec_sprites);
		y++;
	}
}
