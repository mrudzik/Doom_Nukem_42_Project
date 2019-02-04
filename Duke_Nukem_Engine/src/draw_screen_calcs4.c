/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_calcs4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:50:39 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 18:50:40 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

static float	interpolate(t_main_data *main, float cmprsd_txtr,
	float sampling_ratio)
{
	cmprsd_txtr += sampling_ratio;
	DRM.v = (int)cmprsd_txtr;
	if (DRM.v >= TEX_W || DRM.v < 0)
	{
		cmprsd_txtr = 0;
		DRM.v = 0;
	}
	return (cmprsd_txtr);
}

void			render_wall(t_main_data *main)
{
	float	sampling_ratio;
	float	cmprsd_txtr;

	floor_ceil_views(main);
	project_heights(main);
	DRM.begin_x = max(max(DRM.x1, DRM.now.sx1), DRM.begin_x_local);
	DRM.end_x = min(min(DRM.x2, DRM.now.sx2), DRM.end_x_local);
	DRM.u = 0;
	DRM.v = 0;
	sampling_ratio = (float)TEX_W / (float)(abs(DRM.x2_edge - DRM.x1_edge));
	if (sampling_ratio < 0.005)
		sampling_ratio = 0.005;
	cmprsd_txtr = 0;
	DRM.x = DRM.x1_edge;
	while (++DRM.x <= DRM.end_x)
	{
		cmprsd_txtr = interpolate(main, cmprsd_txtr, sampling_ratio);
		if (DRM.x > DRM.begin_x - 1)
		{
			draw_floor_ceil(main);
			draw_walls(main);
		}
	}
}

int				render_wall_segment(t_main_data *main)
{
	if (DRM.full_len < TEX_LEN)
		return (-1);
	DRM.len += TEX_LEN;
	DRM.vx3 = DRM.vx_start + (DRM.vx_end - DRM.vx_start)
	* (DRM.len / DRM.full_len);
	DRM.vy3 = DRM.vy_start + (DRM.vy_end - DRM.vy_start)
	* (DRM.len / DRM.full_len);
	DRM.vx1 = DRM.vx2;
	DRM.vy1 = DRM.vy2;
	DRM.vx2 = DRM.vx3;
	DRM.vy2 = DRM.vy3;
	DRM.pcos = PD.anglecos;
	DRM.psin = PD.anglesin;
	DRM.tx1 = DRM.vx1 * DRM.psin - DRM.vy1 * DRM.pcos;
	DRM.tz1 = DRM.vx1 * DRM.pcos + DRM.vy1 * DRM.psin;
	DRM.tx2 = DRM.vx2 * DRM.psin - DRM.vy2 * DRM.pcos;
	DRM.tz2 = DRM.vx2 * DRM.pcos + DRM.vy2 * DRM.psin;
	wall_intersections(main);
	perspective_transformation(main);
	if (DRM.x1 >= DRM.x2 || DRM.x2 < DRM.now.sx1 || DRM.x1 > DRM.now.sx2)
		return (0);
	DRM.x1_edge = DRM.x1;
	DRM.x2_edge = DRM.x2;
	render_wall(main);
	return (1);
}

void			calc_wall_lenght(t_main_data *main)
{
	int x;
	int y;

	x = fabs(DRM.vx_end - DRM.vx_start);
	y = fabs(DRM.vy_end - DRM.vy_start);
	DRM.full_len = sqrt((x * x) + (y * y));
	DRM.len = 0;
	if (TEX_LEN > DRM.full_len)
	{
		DRM.x1_edge = DRM.x1;
		DRM.x2_edge = DRM.x2;
		render_wall(main);
	}
}

void			texture_entire_wall(t_main_data *main)
{
	int wall_seg;

	DRM.begin_x_local = max(DRM.x1, DRM.now.sx1);
	DRM.end_x_local = min(DRM.x2, DRM.now.sx2);
	DRM.vx_start = DRM.vx1;
	DRM.vy_start = DRM.vy1;
	DRM.vx_end = DRM.vx2;
	DRM.vy_end = DRM.vy2;
	calc_wall_lenght(main);
	DRM.vx2 = DRM.vx1;
	DRM.vy2 = DRM.vy1;
	while (DRM.len < DRM.full_len)
	{
		wall_seg = render_wall_segment(main);
		if (wall_seg == -1)
			break ;
		else if (wall_seg == 0)
			continue ;
	}
}
