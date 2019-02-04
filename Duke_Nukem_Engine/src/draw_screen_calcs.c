/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_calcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:42:16 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 21:26:09 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void			player_view_calc(t_main_data *main)
{
	DRM.vx1 = DRM.sect->vertex[DRI.s + 0].x - PD.where.x;
	DRM.vy1 = DRM.sect->vertex[DRI.s + 0].y - PD.where.y;
	DRM.vx2 = DRM.sect->vertex[DRI.s + 1].x - PD.where.x;
	DRM.vy2 = DRM.sect->vertex[DRI.s + 1].y - PD.where.y;
	DRM.pcos = PD.anglecos;
	DRM.psin = PD.anglesin;
	DRM.tx1 = DRM.vx1 * DRM.psin - DRM.vy1 * DRM.pcos;
	DRM.tz1 = DRM.vx1 * DRM.pcos + DRM.vy1 * DRM.psin;
	DRM.tx2 = DRM.vx2 * DRM.psin - DRM.vy2 * DRM.pcos;
	DRM.tz2 = DRM.vx2 * DRM.pcos + DRM.vy2 * DRM.psin;
}

static void		wall_intersect_checks(t_main_data *main)
{
	if (DRM.tz1 < DRM.near_z)
	{
		DRM.tx1 = DRM.i2.x;
		DRM.tz1 = DRM.i2.y;
		if (DRM.i1.y > 0)
		{
			DRM.tx1 = DRM.i1.x;
			DRM.tz1 = DRM.i1.y;
		}
	}
	if (DRM.tz2 < DRM.near_z)
	{
		DRM.tx2 = DRM.i2.x;
		DRM.tz2 = DRM.i2.y;
		if (DRM.i1.y > 0)
		{
			DRM.tx2 = DRM.i1.x;
			DRM.tz2 = DRM.i1.y;
		}
	}
}

void			wall_intersections(t_main_data *main)
{
	if (DRM.tz1 <= 0 || DRM.tz2 <= 0)
	{
		DRM.near_z = 1e-4f;
		DRM.near_side = 1e-5f;
		DRM.far_side = 20.f;
		DRM.far_z = 5;
		DRM.i1 = intersect(ft_map_help(DRM.tx1, DRM.tz1, DRM.tx2),
			ft_map_help(DRM.tz2, -DRM.near_side, DRM.near_z),
			-DRM.far_side, DRM.far_z);
		DRM.i2 = intersect(ft_map_help(DRM.tx1, DRM.tz1, DRM.tx2),
			ft_map_help(DRM.tz2, DRM.near_side, DRM.near_z),
			DRM.far_side, DRM.far_z);
		wall_intersect_checks(main);
	}
}

void			perspective_transformation(t_main_data *main)
{
	DRM.x_scale1 = HFOV / DRM.tz1;
	DRM.y_scale1 = VFOV / DRM.tz1;
	DRM.x1 = W / 2 - (int)(DRM.tx1 * DRM.x_scale1);
	DRM.x_scale2 = HFOV / DRM.tz2;
	DRM.y_scale2 = VFOV / DRM.tz2;
	DRM.x2 = W / 2 - (int)(DRM.tx2 * DRM.x_scale2);
}
