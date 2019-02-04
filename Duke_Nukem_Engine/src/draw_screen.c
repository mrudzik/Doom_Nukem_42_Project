/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:58:42 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 18:40:02 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void			sched_neighbor(t_main_data *main)
{
	if (DRM.neighbor >= 0 && DRM.end_x_local >= DRM.begin_x_local &&
		(DR.head + MAX_QUEUE + 1 - DR.tail) % MAX_QUEUE)
	{
		*DR.head = (t_item) { DRM.neighbor, DRM.begin_x_local, DRM.end_x_local};
		if (++DR.head == DR.queue + MAX_QUEUE)
			DR.head = DR.queue;
	}
}

void			draw_screen_init(t_main_data *main, int *renderedsectors)
{
	DR.head = DR.queue;
	DR.tail = DR.queue;
	DRI.x = 0;
	while (DRI.x < W)
		DR.y_top[DRI.x++] = 0;
	DRI.x = 0;
	while (DRI.x < W)
		DR.y_bottom[DRI.x++] = H - 1;
	DRI.n = 0;
	while (DRI.n < DR.num_sectors)
		renderedsectors[DRI.n++] = 0;
	DRI.qu = -1;
	while (++DRI.qu < MAX_QUEUE)
		*DR.head = (t_item) { PD.sector, 0, W - 1 };
	if (++DR.head == DR.queue + MAX_QUEUE)
		DR.head = DR.queue;
}

void			render_room(t_main_data *main)
{
	DRM.sect = &SD[DRM.now.sectorno];
	DRI.s = -1;
	while (++DRI.s < DRM.sect->npoints)
	{
		player_view_calc(main);
		if (DRM.tz1 <= 0 && DRM.tz2 <= 0)
			continue ;
		wall_intersections(main);
		perspective_transformation(main);
		if (DRM.x1 >= DRM.x2 || DRM.x2 < DRM.now.sx1 || DRM.x1 > DRM.now.sx2)
			continue ;
		DRI.wal++;
		texture_entire_wall(main);
		sched_neighbor(main);
	}
}

void			draw_screen(t_main_data *main)
{
	int renderedsectors[DR.num_sectors];

	DRI.wal = 0;
	draw_screen_init(main, renderedsectors);
	while (DR.head != DR.tail)
	{
		DRM.now = *DR.tail;
		if (++DR.tail == DR.queue + MAX_QUEUE)
			DR.tail = DR.queue;
		if (renderedsectors[DRM.now.sectorno] & 0x21)
			continue;
		++renderedsectors[DRM.now.sectorno];
		render_room(main);
		++renderedsectors[DRM.now.sectorno];
	}
	if (DRI.wal == 0)
		draw_previous_frame(main);
	else
		save_current_frame(main);
}
