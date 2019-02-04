/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:46:13 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 17:47:09 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void		fly_physics(t_main_data *main, float nextz)
{
	if (PD.velocity.z > 0)
	{
		if (nextz > SD[PD.sector].ceil)
			PD.velocity.z = 0;
		else
		{
			PD.where.z += PD.velocity.z;
			GM.moving = 1;
			PD.velocity.z -= 0.5;
		}
	}
	else if (PD.velocity.z < 0)
	{
		if (nextz < SD[PD.sector].floor + GM.eyeheight)
		{
			PD.where.z = SD[PD.sector].floor + GM.eyeheight;
			PD.velocity.z = 0;
		}
		else
		{
			PD.where.z += PD.velocity.z;
			GM.moving = 1;
			PD.velocity.z += 0.5;
		}
	}
}

void		fly_mode(t_main_data *main)
{
	float nextz;

	if (GM.flying == 1)
	{
		GM.falling = 0;
		GM.ground = 0;
		nextz = PD.where.z + PD.velocity.z;
		fly_physics(main, nextz);
		if (PD.where.z < SD[PD.sector].floor + GM.eyeheight)
		{
			PD.where.z = SD[PD.sector].floor + GM.eyeheight;
			PD.velocity.z = 0;
		}
	}
}

void		vertical_collision(t_main_data *main)
{
	float nextz;

	if (GM.falling)
	{
		PD.velocity.z -= 0.05f;
		nextz = PD.where.z + PD.velocity.z;
		if (PD.velocity.z < 0 && nextz < SD[PD.sector].floor + GM.eyeheight)
		{
			PD.where.z = SD[PD.sector].floor + GM.eyeheight;
			PD.velocity.z = 0;
			GM.falling = 0;
			GM.ground = 1;
		}
		else if (PD.velocity.z > 0 && nextz > SD[PD.sector].ceil)
		{
			PD.velocity.z = 0;
			GM.falling = 1;
		}
		if (GM.falling)
		{
			PD.where.z += PD.velocity.z;
			GM.moving = 1;
		}
	}
}

int			bumps(t_main_data *main, float dx, float dy, size_t s)
{
	if (INTERSECTBOX(PD.where.x, PD.where.y, PD.where.x + dx, PD.where.y
		+ dy, SD[PD.sector].vertex[s + 0].x, SD[PD.sector].vertex[s + 0].y,
		SD[PD.sector].vertex[s + 1].x, SD[PD.sector].vertex[s + 1].y)
		&& pointside(ft_map_help(PD.where.x + dx, PD.where.y + dy,
		SD[PD.sector].vertex[s + 0].x), SD[PD.sector].vertex[s + 0].y,
		SD[PD.sector].vertex[s + 1].x, SD[PD.sector].vertex[s + 1].y) < 0)
		if ((SD[PD.sector].neighbors[s] < 0 ? -9e9 :
			min(SD[PD.sector].ceil, SD[SD[PD.sector].neighbors[s]].ceil))
			< PD.where.z + HEADMARGIN || (SD[PD.sector].neighbors[s]
			< 0 ? 9e9 : max(SD[PD.sector].floor,
			SD[SD[PD.sector].neighbors[s]].floor)) > PD.where.z
			- GM.eyeheight + KNEEHEIGHT)
			return (1);
	return (0);
}

void		horizontal_collision(t_main_data *main, float dx,
	float dy, size_t s)
{
	float		xd;
	float		yd;
	float		dx_temp;

	if (GM.moving == 1)
	{
		while (++s < SD[PD.sector].npoints)
			if (bumps(main, dx, dy, s) == 1)
			{
				xd = SD[PD.sector].vertex[s + 1].x
				- SD[PD.sector].vertex[s + 0].x;
				yd = SD[PD.sector].vertex[s + 1].y
				- SD[PD.sector].vertex[s + 0].y;
				dx_temp = xd * (dx * xd + yd * dy) / (xd * xd + yd * yd);
				dy = yd * (dx * xd + yd * dy) / (xd * xd + yd * yd);
				dx = dx_temp;
				GM.moving = 0;
			}
		move_player(main, dx, dy);
		if (point_on_map(main) != 1)
			move_player(main, -dx, -dy);
		GM.falling = 1;
	}
}
