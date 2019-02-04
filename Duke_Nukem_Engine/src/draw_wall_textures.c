/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:41:35 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 13:14:36 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

int		draw_wall_textures(t_main_data *main)
{
	int temp_tex;

	if (GM.window_modes == 0)
		return (0);
	DRI.s = -1;
	if (GM.window_modes == 1)
		DRI.windows = 1;
	temp_tex = DRM.sect->texture_num;
	DRM.sect->texture_num = 4;
	while (++DRI.s < DRM.sect->npoints)
	{
		player_view_calc(main);
		if (DRM.tz1 <= 0 && DRM.tz2 <= 0)
			continue;
		wall_intersections(main);
		perspective_transformation(main);
		if (DRM.x1 >= DRM.x2 || DRM.x2 < DRM.now.sx1 || DRM.x1 > DRM.now.sx2)
			continue;
		texture_entire_wall(main);
	}
	DRM.sect->texture_num = temp_tex;
	DRI.windows = 0;
	return (1);
}
