/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:05:45 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 13:05:47 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void		draw_flying_info(t_main_data *main)
{
	int			pl_x;
	int			pl_y;
	SDL_Color	color;

	pl_x = W / 2;
	pl_y = H / 2;
	color.r = 255;
	color.g = 255;
	color.b = 100;
	if (GM.flying == 1)
		draw_text(main, "Flying", set_txt(pl_x + 20,
			pl_y - 20, color, 10), F_ARIAL);
	if (GM.ground == 1)
		draw_text(main, "Grounded", set_txt(pl_x + 20,
			pl_y - 20, color, 10), F_ARIAL);
	if (GM.falling == 1 && GM.ground != 1 && GM.flying != 1)
		draw_text(main, "Falling", set_txt(pl_x + 20,
			pl_y - 20, color, 10), F_ARIAL);
}

void		draw_player_info(t_main_data *main)
{
	SDL_Color	color;
	char		*buff;

	color.r = 255;
	color.g = 255;
	color.b = 100;
	draw_text(main, "X:", set_txt(620, 400, color, 10), F_ARIAL);
	buff = ft_itoa((int)PD.where.x);
	draw_text(main, buff, set_txt(640, 400, color, 10), F_ARIAL);
	ft_strdel(&buff);
	draw_text(main, "Y:", set_txt(620, 410, color, 10), F_ARIAL);
	buff = ft_itoa((int)PD.where.y);
	draw_text(main, buff, set_txt(640, 410, color, 10), F_ARIAL);
	ft_strdel(&buff);
	draw_text(main, "Z:", set_txt(620, 420, color, 10), F_ARIAL);
	buff = ft_itoa((int)PD.where.z);
	draw_text(main, buff, set_txt(640, 420, color, 10), F_ARIAL);
	ft_strdel(&buff);
	draw_text(main, "Sector:", set_txt(620, 430, color, 10), F_ARIAL);
	buff = ft_itoa((int)PD.sector);
	draw_text(main, buff, set_txt(660, 430, color, 10), F_ARIAL);
	ft_strdel(&buff);
}
