/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:54:00 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 17:09:51 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	move_player(t_main_data *main, float dx, float dy)
{
	int			s;
	float		px;
	float		py;
	t_sector	*sect;
	t_vec2		*vert;

	px = PD.where.x;
	py = PD.where.y;
	sect = &SD[PD.sector];
	vert = sect->vertex;
	s = -1;
	while (++s < (int)sect->npoints)
		if (sect->neighbors[s] >= 0
				&& INTERSECTBOX(px, py, px + dx, py + dy, vert[s + 0].x,
					vert[s + 0].y, vert[s + 1].x, vert[s + 1].y)
				&& pointside(ft_map_help(px + dx, py + dy, vert[s + 0].x),
					vert[s + 0].y, vert[s + 1].x, vert[s + 1].y) < 0)
		{
			PD.sector = sect->neighbors[s];
			break ;
		}
	PD.where.x += dx;
	PD.where.y += dy;
	PD.anglesin = sinf(PD.angle);
	PD.anglecos = cosf(PD.angle);
}

void	mouse_aim(t_main_data *main)
{
	SDL_GetRelativeMouseState(&GM.x_m, &GM.y_m);
	PD.angle += GM.x_m * 0.03f;
	GM.yaw = clamp(GM.yaw - GM.y_m * 0.05f, -5, 5);
	PD.yaw = -1 * (GM.yaw - PD.velocity.z * 0.5f);
	move_player(main, 0, 0);
}
