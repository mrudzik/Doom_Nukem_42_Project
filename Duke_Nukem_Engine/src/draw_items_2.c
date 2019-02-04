/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:12:31 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/09 19:14:09 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

static void			set_color(t_main_data *main, int x, int y, int tex_num)
{
	int color;

	if (DRM.u < CARD_H && DRM.v < CARD_W)
	{
		color = DR.card[tex_num][DRM.u][DRM.v];
		if (color != 0x000000)
		{
			if (SD[DRM.now.sectorno].light == 0)
				DR.img_buff[y][x] = pixel_bright(color, 0.1 * DRM.z);
			else
				DR.img_buff[y][x] = color;
		}
	}
}

static float		interpolate(t_main_data *main, float cmprsd_txtr,
	float sampling_ratio)
{
	if (DRM.u >= CARD_H)
	{
		DRM.u = 0;
		cmprsd_txtr = 0;
	}
	else
	{
		cmprsd_txtr += sampling_ratio;
		DRM.u = (int)cmprsd_txtr;
	}
	return (cmprsd_txtr);
}

void				vline_card(t_main_data *main, int x, int tex_num)
{
	int		y;
	int		y1;
	int		y2;
	float	sampling_ratio;
	float	cmprsd_txtr;

	y1 = DRS.y1;
	y2 = DRS.y2;
	if (y2 > y1)
	{
		sampling_ratio = (float)CARD_H / (float)(abs(y2 - y1));
		if (sampling_ratio < 0.005)
			sampling_ratio = 0.005;
		cmprsd_txtr = 0;
		y = y1;
		while (y <= y2)
		{
			cmprsd_txtr = interpolate(main, cmprsd_txtr, sampling_ratio);
			if (y >= y1)
				if (y < H && 0 < y)
					set_color(main, x, y, tex_num);
			y++;
		}
	}
}
