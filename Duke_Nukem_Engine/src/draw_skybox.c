/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:40:46 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 22:28:02 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	skybox_vline(t_main_data *main, int x, int start_x)
{
	int y;
	int y1;

	y = 0;
	y1 = 871 + (PD.yaw * 94);
	while (y < H)
	{
		if (y1 < SKY_H && start_x < SKY_W)
			DR.img_buff[y][x] = DR.skybox_pix[y1][start_x];
		else
			DR.img_buff[y][x] = 0x5d5f63;
		y1++;
		y++;
	}
}

void	draw_skybox(t_main_data *main)
{
	int x;
	int start_x;

	x = 0;
	if (PD.anglesin <= 0)
		start_x = (int)(PD.anglecos / (2.0 / 360.0) *
			((double)SKY_W / 2 / 360.0));
	else
		start_x = (int)(SKY_W / 2 - (PD.anglecos / (2 / 360.0)
					* ((double)SKY_W / 2 / 360.0)));
	if (start_x < 0)
		start_x = 4320 + start_x;
	while (x < W)
	{
		start_x++;
		if (start_x < 0)
			start_x = SKY_W;
		if (start_x > SKY_W)
			start_x = 0;
		skybox_vline(main, x, start_x);
		x++;
	}
}

void	load_skybox_line(t_main_data *main, SDL_Surface *pic_surface)
{
	int				x;
	int				y;
	unsigned int	*pixels;

	pixels = (unsigned int *)pic_surface->pixels;
	y = -1;
	while (++y < SKY_H)
	{
		DR.skybox_pix[y] = (int *)malloc(sizeof(int) * SKY_W);
		x = -1;
		while (++x < SKY_W)
			DR.skybox_pix[y][x] = pixels[(y * pic_surface->w) + x];
	}
}

int		load_skybox_pix(t_main_data *main, char *path)
{
	SDL_Surface		*pic_surface;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	pic_surface = IMG_Load(path);
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	DR.skybox_pix = (int **)malloc(sizeof(int *) * SKY_H);
	load_skybox_line(main, pic_surface);
	SDL_FreeSurface(pic_surface);
	return (1);
}
