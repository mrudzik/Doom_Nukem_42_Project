/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_calcs3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:07:02 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 22:08:33 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

float		calc_texture_pixel(t_main_data *main, float cmprsd_txtr,
	float sampling_ratio)
{
	if (DRM.u >= TEX_H)
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

void		set_pixel_color(t_main_data *main, int tex_num, int x, int y)
{
	int color;

	color = DR.textures[tex_num][DRM.u * TEX_W + DRM.v];
	if (color != 0x000000)
	{
		if (SD[DRM.now.sectorno].light == 0)
			DR.img_buff[y][x] = pixel_bright(color, 0.1 * DRM.z);
		else
			DR.img_buff[y][x] = color;
	}
}

void		vline_tex(t_main_data *main, t_coord3 borders, int tex_num)
{
	int		y;
	int		y1;
	int		y2;
	float	sampling_ratio;
	float	cmprsd_txtr;

	y1 = borders.y;
	y2 = borders.z;
	if (y2 > y1)
	{
		sampling_ratio = (float)TEX_H / (float)(abs(DRM.y_a - DRM.y_b));
		if (sampling_ratio < 0.005)
			sampling_ratio = 0.005;
		cmprsd_txtr = 0;
		DRM.u = 0;
		y = (int)DRM.y_a - 1;
		if (y < -10000)
			y = -10000;
		while (++y <= y2)
		{
			cmprsd_txtr = calc_texture_pixel(main, cmprsd_txtr, sampling_ratio);
			if (y >= y1)
				set_pixel_color(main, tex_num, borders.x, y);
		}
	}
}

void		light_vline_pixel(t_main_data *main,
	t_coord3 borders, t_coord3 colors, int y)
{
	if (SD[DRM.now.sectorno].light == 0)
	{
		if (DRM.flor_ceil == 1)
			DR.img_buff[y][borders.x] = pixel_bright(colors.y,
				-1 * ft_map(y, borders.y, ft_map_help(H, -1, 0)));
		else
			DR.img_buff[y][borders.x] = pixel_bright(colors.y,
				ft_map(y, 0, ft_map_help(borders.z, 0, 1)));
	}
	else
		DR.img_buff[y][borders.x] = colors.y;
}

void		vline(t_main_data *main, t_coord3 borders, t_coord3 colors)
{
	int y;

	borders.y = clamp(borders.y, 0, H - 1);
	borders.z = clamp(borders.z, 0, H - 1);
	if (borders.z == borders.y)
		DR.img_buff[borders.y][borders.x] = colors.y;
	else if (borders.z > borders.y)
	{
		DR.img_buff[borders.y][borders.x] = colors.x;
		y = borders.y + 1;
		while (y < borders.z)
		{
			light_vline_pixel(main, borders, colors, y);
			y++;
		}
		DR.img_buff[borders.z][borders.x] = colors.z;
	}
}
