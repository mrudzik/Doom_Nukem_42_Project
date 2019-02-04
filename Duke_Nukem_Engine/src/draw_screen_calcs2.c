/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_calcs2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:49:45 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 21:38:57 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void		floor_ceil_views(t_main_data *main)
{
	DRM.y_ceil = DRM.sect->ceil - PD.where.z;
	DRM.y_floor = DRM.sect->floor - PD.where.z;
	DRM.neighbor = DRM.sect->neighbors[DRI.s];
	DRM.ny_ceil = 0;
	DRM.ny_floor = 0;
	if (DRM.neighbor >= 0)
	{
		DRM.ny_ceil = SD[DRM.neighbor].ceil - PD.where.z;
		DRM.ny_floor = SD[DRM.neighbor].floor - PD.where.z;
	}
}

void		project_heights(t_main_data *main)
{
	DRM.y1_a = H / 2 - (int)(yaw(main, DRM.y_ceil, DRM.tz1) * DRM.y_scale1);
	DRM.y1_b = H / 2 - (int)(yaw(main, DRM.y_floor, DRM.tz1) * DRM.y_scale1);
	DRM.y2_a = H / 2 - (int)(yaw(main, DRM.y_ceil, DRM.tz2) * DRM.y_scale2);
	DRM.y2_b = H / 2 - (int)(yaw(main, DRM.y_floor, DRM.tz2) * DRM.y_scale2);
	DRM.ny1_a = H / 2 - (int)(yaw(main, DRM.ny_ceil, DRM.tz1) * DRM.y_scale1);
	DRM.ny1_b = H / 2 - (int)(yaw(main, DRM.ny_floor, DRM.tz1) * DRM.y_scale1);
	DRM.ny2_a = H / 2 - (int)(yaw(main, DRM.ny_ceil, DRM.tz2) * DRM.y_scale2);
	DRM.ny2_b = H / 2 - (int)(yaw(main, DRM.ny_floor, DRM.tz2) * DRM.y_scale2);
}

void		draw_floor_ceil(t_main_data *main)
{
	DRM.z = ((DRM.x - DRM.x1) * (DRM.tz2 - DRM.tz1)
		/ (DRM.x2 - DRM.x1) + DRM.tz1) * 0.6;
	DRM.y_a = (DRM.x - DRM.x1) * (DRM.y2_a - DRM.y1_a)
	/ (DRM.x2 - DRM.x1) + DRM.y1_a;
	DRM.cy_a = clamp(DRM.y_a, DR.y_top[DRM.x], DR.y_bottom[DRM.x]);
	DRM.y_b = (DRM.x - DRM.x1) * (DRM.y2_b - DRM.y1_b)
	/ (DRM.x2 - DRM.x1) + DRM.y1_b;
	DRM.cy_b = clamp(DRM.y_b, DR.y_top[DRM.x], DR.y_bottom[DRM.x]);
	texture_floor(main);
	texture_ceil(main);
}

void		lift_wall_help(t_main_data *main)
{
	DRM.ny_a = (DRM.x - DRM.x1) * (DRM.ny2_a - DRM.ny1_a)
	/ (DRM.x2 - DRM.x1) + DRM.ny1_a;
	DRM.cny_a = clamp(DRM.ny_a, DR.y_top[DRM.x], DR.y_bottom[DRM.x]);
	DRM.ny_b = (DRM.x - DRM.x1) * (DRM.ny2_b - DRM.ny1_b)
	/ (DRM.x2 - DRM.x1) + DRM.ny1_b;
	DRM.cny_b = clamp(DRM.ny_b, DR.y_top[DRM.x], DR.y_bottom[DRM.x]);
	DR.y_top[DRM.x] = clamp(max(DRM.cy_a, DRM.cny_a),
		DR.y_top[DRM.x], H - 1);
	DR.y_bottom[DRM.x] = clamp(min(DRM.cy_b, DRM.cny_b),
		0, DR.y_bottom[DRM.x]);
}

void		draw_walls(t_main_data *main)
{
	if (DRM.neighbor >= 0 && DRI.windows == 0)
	{
		lift_wall_help(main);
		DRM.ny_a = (DRM.x - DRM.x1) * (DRM.ny2_a - DRM.ny1_a)
		/ (DRM.x2 - DRM.x1) + DRM.ny1_a;
		DRM.cny_a = clamp(DRM.ny_a, DR.y_top[DRM.x], DR.y_bottom[DRM.x]);
		DRM.ny_b = (DRM.x - DRM.x1) * (DRM.ny2_b - DRM.ny1_b)
		/ (DRM.x2 - DRM.x1) + DRM.ny1_b;
		DRM.cny_b = clamp(DRM.ny_b, DR.y_top[DRM.x], DR.y_bottom[DRM.x]);
		DR.y_top[DRM.x] = clamp(max(DRM.cy_a, DRM.cny_a),
			DR.y_top[DRM.x], H - 1);
		DR.y_bottom[DRM.x] = clamp(min(DRM.cy_b, DRM.cny_b),
			0, DR.y_bottom[DRM.x]);
		vline(main, set_point(DRM.x, DRM.cy_a, DRM.cny_a - 1),
			set_point(0, DRM.x == DRM.x1 || DRM.x == DRM.x2 ? 0 : DRM.r1, 0));
		vline_tex(main, set_point(DRM.x, DRM.cy_a, DRM.cny_a - 1), 3);
		vline_tex(main, set_point(DRM.x, DRM.cny_b + 1, DRM.cy_b), 1);
	}
	else
		texture_wall(main);
}
