/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:56:54 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 21:57:02 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

float		yaw(t_main_data *main, float y, float z)
{
	return (PD.yaw * z + y);
}

void		texture_floor(t_main_data *main)
{
	DRM.flor_ceil = 0;
	if (SD[DRM.now.sectorno].door > 0)
		vline(main, set_point(DRM.x, DR.y_top[DRM.x], DRM.cy_a - 1),
			set_point(0x111111, 0x260600, 0x111111));
	else if (SD[DRM.now.sectorno].lift > 0)
		vline(main, set_point(DRM.x, DR.y_top[DRM.x], DRM.cy_a - 1),
			set_point(0x111111, 0x002000, 0x111111));
	else if (SD[DRM.now.sectorno].end == 1)
		vline(main, set_point(DRM.x, DR.y_top[DRM.x], DRM.cy_a - 1),
			set_point(0x000044, 0x77235e, 0x000044));
	else
		vline(main, set_point(DRM.x, DR.y_top[DRM.x], DRM.cy_a - 1),
			set_point(0x111111, 0x222222, 0x111111));
}

void		texture_ceil(t_main_data *main)
{
	DRM.flor_ceil = 1;
	if (SD[DRM.now.sectorno].door > 0)
		vline(main, set_point(DRM.x, DRM.cy_b + 1, DR.y_bottom[DRM.x]),
			set_point(0x000044, 0x260600, 0x000044));
	else if (SD[DRM.now.sectorno].lift > 0)
		vline(main, set_point(DRM.x, DRM.cy_b + 1, DR.y_bottom[DRM.x]),
			set_point(0x000044, 0x002802, 0x000044));
	else if (SD[DRM.now.sectorno].end == 1)
		vline(main, set_point(DRM.x, DRM.cy_b + 1, DR.y_bottom[DRM.x]),
			set_point(0x000044, 0xd140a5, 0x000044));
	else
		vline(main, set_point(DRM.x, DRM.cy_b + 1, DR.y_bottom[DRM.x]),
			set_point(0x000044, 0x002a59, 0x000044));
}

void		texture_wall(t_main_data *main)
{
	if (SD[DRM.now.sectorno].door > 0)
		vline_tex(main, set_point(DRM.x, DRM.cy_a, DRM.cy_b), 5);
	else if (SD[DRM.now.sectorno].lift > 0)
		vline_tex(main, set_point(DRM.x, DRM.cy_a, DRM.cy_b), 6);
	else
		vline_tex(main, set_point(DRM.x, DRM.cy_a, DRM.cy_b),
			DRM.sect->texture_num);
}
