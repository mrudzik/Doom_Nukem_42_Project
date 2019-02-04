/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:44:04 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 23:44:10 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	find_sprite_end(t_main_data *main, float dist)
{
	float v1_x_loc;
	float v1_y_loc;
	float v2_x_loc;
	float v2_y_loc;

	v1_x_loc = (DRM.sect->things[DRS.spr_num].position.x - PD.where.x) / dist;
	v1_y_loc = (DRM.sect->things[DRS.spr_num].position.y - PD.where.y) / dist;
	v2_x_loc = -v1_y_loc;
	v2_y_loc = v1_x_loc;
	DRM.vx1 = (DRM.sect->things[DRS.spr_num].position.x - PD.where.x);
	DRM.vy1 = (DRM.sect->things[DRS.spr_num].position.y - PD.where.y);
	DRM.vx2 = (v2_x_loc * 1) + DRM.sect->things[DRS.spr_num].position.x
	- PD.where.x;
	DRM.vy2 = (v2_y_loc * 1) + DRM.sect->things[DRS.spr_num].position.y
	- PD.where.y;
}

void	find_sprite_visual(t_main_data *main, float dist)
{
	DRM.y_ceil = DRM.sect->things[DRS.spr_num].sprite_ceil - PD.where.z;
	DRM.y_floor = DRM.sect->things[DRS.spr_num].sprite_floor - PD.where.z;
	DRM.y1_a = H / 2 - (int)(yaw(main, DRM.y_ceil, DRM.tz1) * DRM.y_scale1);
	DRM.y1_b = H / 2 - (int)(yaw(main, DRM.y_floor, DRM.tz1) * DRM.y_scale1);
	DRM.y2_a = H / 2 - (int)(yaw(main, DRM.y_ceil, DRM.tz2) * DRM.y_scale2);
	DRM.y2_b = H / 2 - (int)(yaw(main, DRM.y_floor, DRM.tz2) * DRM.y_scale2);
	DRM.begin_x = DRM.x1;
	DRM.end_x = DRM.begin_x + 2000 / dist;
	if (DRM.end_x < 0)
		DRM.end_x = 0;
}

void	transformation_formulas(t_main_data *main)
{
	DRM.pcos = PD.anglecos;
	DRM.psin = PD.anglesin;
	DRM.tx1 = DRM.vx1 * DRM.psin - DRM.vy1 * DRM.pcos;
	DRM.tz1 = DRM.vx1 * DRM.pcos + DRM.vy1 * DRM.psin;
	DRM.tx2 = DRM.vx2 * DRM.psin - DRM.vy2 * DRM.pcos;
	DRM.tz2 = DRM.vx2 * DRM.pcos + DRM.vy2 * DRM.psin;
}

int		calc_sprite_interactions(t_main_data *main)
{
	int ret;

	if (DRS.dist < 100 && DRS.dist > 1 &&
		DRM.sect->things[DRS.spr_num].sprite_id == IMP)
		pos_enemy(main);
	if (DRS.dist < 5 && DRM.sect->things[DRS.spr_num].sprite_id == IMP)
	{
		main->time = SDL_GetTicks();
		main->flag = 1;
		PD.inventory.hp--;
	}
	else if (DRS.dist < 2)
	{
		main->obj++;
		main->time = SDL_GetTicks();
		main->flag = 0;
		ret = DRM.sect->things[DRS.spr_num].sprite_id;
		DRM.sect->things[DRS.spr_num].sprite_id = -1;
		return (ret);
	}
	return (-1);
}

int		calc_sprite_view(t_main_data *main)
{
	int		ret;
	float	abx;
	float	aby;

	abx = (PD.where.x - DRM.sect->things[DRS.spr_num].position.x);
	aby = (PD.where.y - DRM.sect->things[DRS.spr_num].position.y);
	DRS.dist = (float)sqrt(abx * abx + aby * aby);
	ret = calc_sprite_interactions(main);
	if (ret != -1)
		return (ret);
	find_sprite_end(main, DRS.dist);
	transformation_formulas(main);
	if (DRM.tz1 <= 0 && DRM.tz2 <= 0)
		return (-1);
	perspective_transformation(main);
	find_sprite_visual(main, DRS.dist);
	return (10);
}
