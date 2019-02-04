/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:52 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 15:59:54 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	load_helmet_pixel_data(t_main_data *main, SDL_Surface *pic_surface)
{
	unsigned int	*pixels;
	int				y;
	int				x;

	pixels = (unsigned int *)pic_surface->pixels;
	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
			DR.helmet[y][x] = pixels[(y * pic_surface->w) + x];
	}
}

int		load_helmet(t_main_data *main)
{
	SDL_Surface		*pic_surface;
	int				y;

	DR.helmet = (int **)malloc(sizeof(int *) * H);
	y = 0;
	while (y < H)
		DR.helmet[y++] = (int *)malloc(sizeof(int) * W);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	pic_surface = IMG_Load("media/Helmet_sized.png");
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	load_helmet_pixel_data(main, pic_surface);
	SDL_FreeSurface(pic_surface);
	return (1);
}

void	draw_helmet(t_main_data *main)
{
	int y;
	int x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			if (DR.helmet[y][x] != 0x000000)
				DR.img_buff[y][x] = DR.helmet[y][x];
			x++;
		}
		y++;
	}
}

void	draw_hud(t_main_data *main)
{
	SDL_Color	color;
	char		*buff;

	color.r = 168;
	color.g = 168;
	color.b = 37;
	buff = ft_itoa((int)PD.inventory.hp);
	draw_text(main, buff, set_txt(220, H - 150, color, 45), F_DIGITAL);
	ft_strdel(&buff);
	buff = ft_itoa((int)PD.inventory.armor);
	draw_text(main, buff, set_txt(250, H - 100, color, 45), F_DIGITAL);
	ft_strdel(&buff);
	if (PD.inventory.weapon_type == 1 || PD.inventory.weapon_type == 2)
	{
		buff = ft_itoa((int)PD.inventory.ammo);
		draw_text(main, buff, set_txt(W - 250, H - 90, color, 45), F_DIGITAL);
		ft_strdel(&buff);
	}
	if (main->dev_mode == 1)
		draw_inventory(main, color, 100);
	else
		draw_inventory_short(main);
	draw_lift_stuff(main);
}
