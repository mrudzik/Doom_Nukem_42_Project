/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:42:43 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 12:40:46 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void		draw_sector(t_main_data *main, t_sector sect, int color)
{
	int		ver_x;
	int		ver_y;
	Uint32	index;
	t_coord	start;
	t_coord	end;

	index = 0;
	while (index < sect.npoints)
	{
		ver_x = 600 - (int)(PD.where.x - sect.vertex[index].x) * 5;
		ver_y = 400 - (int)(PD.where.y - sect.vertex[index].y) * 5;
		start.x = ver_x;
		start.y = ver_y;
		if (index > 0)
			ft_draw_line(main, start, end, color);
		end = start;
		index++;
	}
	ver_x = 600 - (int)(PD.where.x - sect.vertex[0].x) * 5;
	ver_y = 400 - (int)(PD.where.y - sect.vertex[0].y) * 5;
	start.x = ver_x;
	start.y = ver_y;
	ft_draw_line(main, start, end, color);
}

int			draw_neighbors(t_main_data *main)
{
	Uint32 index;

	index = 0;
	while (index < SD[PD.sector].npoints)
	{
		if (SD[PD.sector].neighbors[index] >= 0)
			draw_sector(main, SD[SD[PD.sector].neighbors[index]], 0xAA00AA);
		index++;
	}
	return (1);
}

void		draw_face_arrow(t_main_data *main, int pl_x, int pl_y)
{
	t_coord start;
	t_coord end;

	start.x = pl_x + 5 * cos(PD.angle);
	start.y = pl_y + 5 * sin(PD.angle);
	end.x = pl_x;
	end.y = pl_y;
	ft_draw_line(main, start, end, 0xFFFF00);
}

void		draw_vectors(t_main_data *main)
{
	int pl_x;
	int pl_y;

	pl_x = W / 2;
	pl_y = H / 2;
	DR.img_buff[pl_y][pl_x] = 0xFF0000;
	draw_neighbors(main);
	draw_sector(main, SD[PD.sector], 0x00AA00);
	draw_face_arrow(main, pl_x, pl_y);
}
