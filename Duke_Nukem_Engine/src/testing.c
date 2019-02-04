/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:33:38 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 16:51:03 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

t_coord3	set_point(int a, int b, int c)
{
	t_coord3 res;

	res.x = a;
	res.y = b;
	res.z = c;
	return (res);
}

t_vec3		ft_map_help(float sr_end, float dst_start, float dst_end)
{
	t_vec3 res;

	res.x = sr_end;
	res.y = dst_start;
	res.z = dst_end;
	return (res);
}

float		ft_map(float num, float sr_start, t_vec3 funk)
{
	float sr_end;
	float dst_start;
	float dst_end;

	sr_end = funk.x;
	dst_start = funk.y;
	dst_end = funk.z;
	return ((num - sr_start) * ((dst_end - dst_start) /
		(sr_end - sr_start)) + dst_start);
}

int			pixel_bright(int pixel_color, float change)
{
	SDL_Color	color;

	if (change > 0.9)
		change = 0.9;
	color.r = ((pixel_color >> 16) & 255);
	color.g = ((pixel_color >> 8) & 255);
	color.b = (pixel_color & 255);
	color.r *= 1 - change;
	color.g *= 1 - change;
	color.b *= 1 - change;
	return (((256 * 256 * color.r) + (256 * color.g) + color.b));
}
