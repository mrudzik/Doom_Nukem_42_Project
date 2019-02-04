/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:29:09 by vomelchu          #+#    #+#             */
/*   Updated: 2019/01/12 14:29:10 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	cos_sphe(t_vec2 pos1, t_vec2 pos2, t_vec2 pos3, t_main_data *main)
{
	double discr;
	t_vec2 dist;
	double t_0;

	dist.x = pos1.x - pos3.x;
	dist.y = pos1.y - pos3.y;
	main->a = pos2.x * pos2.x + pos2.y * pos2.y;
	main->b = 2 * (pos2.x * dist.x + pos2.y * dist.y);
	main->c = (dist.x * dist.x + dist.y * dist.y) - main->r * main->r;
	discr = main->b * main->b - 4 * main->a * main->c;
	if (discr >= 0)
	{
		main->sqrt_discr = sqrtl(discr);
		t_0 = (-main->b + main->sqrt_discr) / (2 * main->a);
		DRM.sect->things[DRS.spr_num].position.x -= t_0;
		if (pos1.y < pos3.y)
			DRM.sect->things[DRS.spr_num].position.y -= 0.5;
		else
			DRM.sect->things[DRS.spr_num].position.y += 0.5;
	}
}

void	pos_enemy(t_main_data *main)
{
	t_vec2 pos1;
	t_vec2 pos2;
	t_vec2 pos3;

	main->r = 1;
	pos1.x = main->player.where.x;
	pos1.y = main->player.where.y;
	pos2.x = DRM.sect->things[DRS.spr_num].position.x;
	pos2.y = DRM.sect->things[DRS.spr_num].position.y;
	pos3.x = DRM.sect->things[DRS.spr_num].position.x;
	pos3.y = DRM.sect->things[DRS.spr_num].position.y;
	cos_sphe(pos1, pos2, pos3, main);
}
