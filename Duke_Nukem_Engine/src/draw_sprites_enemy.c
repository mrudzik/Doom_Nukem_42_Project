/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:53:56 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 23:53:58 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	draw_multi_imp(t_main_data *main, float angle_cos)
{
	if (PD.where.y <= DRM.sect->things[DRS.spr_num].position.y)
	{
		if (1 >= angle_cos && angle_cos >= 0.7)
			draw_item_sprite(main, 3);
		else if (0.7 > angle_cos && angle_cos >= 0)
			draw_item_sprite(main, 4);
		else if (0 > angle_cos && angle_cos >= -0.7)
			draw_item_sprite(main, 5);
		else if (-0.7 > angle_cos && angle_cos >= -1)
			draw_item_sprite(main, 6);
	}
	else
	{
		if (1 >= angle_cos && angle_cos >= 0.7)
			draw_item_sprite(main, 10);
		else if (0.7 > angle_cos && angle_cos >= 0)
			draw_item_sprite(main, 9);
		else if (0 > angle_cos && angle_cos >= -0.7)
			draw_item_sprite(main, 8);
		else if (-0.7 > angle_cos && angle_cos >= -1)
			draw_item_sprite(main, 7);
	}
}

void	draw_imp_stuff(t_main_data *main)
{
	float	ax;
	float	ay;
	float	bx;
	float	by;
	float	angle_cos;

	ax = PD.where.x - DRM.sect->things[DRS.spr_num].position.x;
	ay = PD.where.y - DRM.sect->things[DRS.spr_num].position.y;
	bx = 2 + DRM.sect->things[DRS.spr_num].position.x;
	by = DRM.sect->things[DRS.spr_num].position.y;
	angle_cos = (ax * bx + ay * by) /
	(sqrt(ax * ax + ay * ay) * sqrt(bx * bx + by * by));
	draw_multi_imp(main, angle_cos);
	if (DRM.begin_x < 600 && DRM.end_x > 600
		&& PD.inventory.weapon_must_hit > 0)
	{
		main->kills++;
		DRM.sect->things[DRS.spr_num].sprite_id = ARMOR;
		DRM.sect->things[DRS.spr_num].sprite_ceil =
		DRM.sect->things[DRS.spr_num].sprite_floor + 5;
		PD.inventory.weapon_must_hit--;
	}
}
