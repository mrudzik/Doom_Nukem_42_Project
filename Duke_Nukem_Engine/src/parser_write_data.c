/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_write_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:00:36 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 14:15:05 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	write_vertexes(char **reading, t_vec2 *vert)
{
	int ver_arr;
	int num;
	int *num_array;
	int y;

	y = 0;
	ver_arr = 0;
	num = 0;
	while (reading[y] != NULL)
	{
		if (ft_strncmp("vertex ", reading[y], 7) == 0)
		{
			num_array = ft_intsplit(reading[y], ' ');
			num = 3;
			while (num < num_array[0] + 1)
			{
				vert[ver_arr].y = num_array[2];
				vert[ver_arr].x = num_array[num];
				num++;
				ver_arr++;
			}
			ft_intdel(&num_array);
		}
		y++;
	}
}

void	write_sec_vert(t_main_data *main, t_vec2 *vert, int *num_array,
	int cur_sector)
{
	int num;
	int vertex_num;
	int lenght;

	SD[cur_sector].floor = num_array[2];
	SD[cur_sector].ceil = num_array[3];
	lenght = (num_array[0] - 3) / 2;
	SD[cur_sector].npoints = lenght;
	SD[cur_sector].vertex = (t_vec2 *)malloc(sizeof(t_vec2) * (lenght + 1));
	vertex_num = 1;
	num = 4;
	while (vertex_num < lenght)
	{
		SD[cur_sector].vertex[vertex_num].x = vert[num_array[num]].x;
		SD[cur_sector].vertex[vertex_num].y = vert[num_array[num]].y;
		num++;
		vertex_num++;
	}
	SD[cur_sector].vertex[vertex_num].x = vert[num_array[num]].x;
	SD[cur_sector].vertex[vertex_num].y = vert[num_array[num]].y;
	SD[cur_sector].vertex[0].x = vert[num_array[num]].x;
	SD[cur_sector].vertex[0].y = vert[num_array[num]].y;
}

void	write_sec_neig(t_main_data *main, int *num_array, int cur_sector)
{
	int lenght;
	int vertex_num;
	int num;

	lenght = (num_array[0] - 3) / 2;
	SD[cur_sector].neighbors = (signed char *)malloc(sizeof(signed char)
		* (lenght + 1));
	vertex_num = 0;
	num = 4 + lenght;
	while (vertex_num < lenght)
	{
		SD[cur_sector].neighbors[vertex_num] = (signed char)num_array[num];
		num++;
		vertex_num++;
	}
	SD[cur_sector].end = 0;
	SD[cur_sector].light = 1;
	SD[cur_sector].door = 0;
	SD[cur_sector].lift = 0;
	SD[cur_sector].start_floor = SD[cur_sector].floor;
	SD[cur_sector].start_ceil = SD[cur_sector].ceil;
	SD[cur_sector].texture_num = 0;
}

void	write_player(t_main_data *main, int *num_array)
{
	int num;

	num = 0;
	PD.sector = num_array[5];
	PD.where.x = num_array[2];
	PD.where.y = num_array[3];
	PD.where.z = SD[PD.sector].floor + EYEHEIGHT;
	PD.angle = num_array[4];
	PD.inventory.hp = 83;
	PD.inventory.armor = 200;
	PD.inventory.weapon_type = 1;
	PD.inventory.ammo = 300;
}

void	write_parsed_data(t_main_data *main, t_data *data, char **reading)
{
	t_vec2	vert[400];
	int		*num_array;
	int		y;
	int		cur_sector;

	write_vertexes(reading, (t_vec2 *)vert);
	main->sectors = (t_sector *)malloc(sizeof(t_sector) * data->count_sector);
	y = -1;
	cur_sector = 0;
	while (reading[++y] != NULL)
	{
		if (ft_strncmp("sector ", reading[y], 7) == 0)
		{
			num_array = ft_intsplit(reading[y], ' ');
			write_sec_vert(main, (t_vec2 *)vert, num_array, cur_sector);
			write_sec_neig(main, num_array, cur_sector++);
			ft_intdel(&num_array);
		}
		if (ft_strncmp("player ", reading[y], 7) == 0)
		{
			num_array = ft_intsplit(reading[y], ' ');
			write_player(main, num_array);
			ft_intdel(&num_array);
		}
	}
}
