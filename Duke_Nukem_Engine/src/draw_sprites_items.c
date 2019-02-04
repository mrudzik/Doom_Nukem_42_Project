/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:50:58 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 23:50:59 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	light_key_line(t_main_data *main, int x1, int key)
{
	if (x1 < W && x1 > 0)
	{
		if (x1 > DRM.begin_x - 1)
		{
			DRS.y1 = (370 + DRS.dist * 0.3) - PD.yaw * 160;
			DRS.y2 = DRS.y1 + (DRM.end_x - DRM.begin_x);
			vline_card(main, x1, key);
		}
	}
}

void	draw_key_sprite(t_main_data *main, int key)
{
	int		x1;
	float	sampling_ratio;
	float	cmprsd_txtr;

	DRM.u = 0;
	DRM.v = 0;
	sampling_ratio = (float)CARD_W / (float)(abs(DRM.end_x - DRM.begin_x));
	if (sampling_ratio < 0.005)
		sampling_ratio = 0.005;
	cmprsd_txtr = 0;
	x1 = DRM.begin_x;
	while (x1 < DRM.end_x)
	{
		cmprsd_txtr += sampling_ratio;
		DRM.v = (int)cmprsd_txtr;
		if (DRM.v >= CARD_W || DRM.v < 0)
		{
			cmprsd_txtr = 0;
			DRM.v = 0;
		}
		light_key_line(main, x1, key);
		x1++;
	}
}

void	light_item_line(t_main_data *main, int x1, int item)
{
	if (x1 < W && x1 > 0)
	{
		if (x1 > DRM.begin_x - 1)
		{
			DRS.y1 = (370 + DRS.dist * 0.3) - PD.yaw * 160;
			DRS.y2 = DRS.y1 + (DRM.end_x - DRM.begin_x);
			vline_item(main, x1, item);
		}
	}
}

void	draw_item_sprite(t_main_data *main, int item)
{
	int		x1;
	float	sampling_ratio;
	float	cmprsd_txtr;

	DRM.u = 0;
	DRM.v = 0;
	sampling_ratio = (float)ITEM_W / (float)(abs(DRM.end_x - DRM.begin_x));
	if (sampling_ratio < 0.005)
		sampling_ratio = 0.005;
	cmprsd_txtr = 0;
	x1 = DRM.begin_x;
	while (x1 < DRM.end_x)
	{
		cmprsd_txtr += sampling_ratio;
		DRM.v = (int)cmprsd_txtr;
		if (DRM.v >= ITEM_W || DRM.v < 0)
		{
			cmprsd_txtr = 0;
			DRM.v = 0;
		}
		light_item_line(main, x1, item);
		x1++;
	}
}
