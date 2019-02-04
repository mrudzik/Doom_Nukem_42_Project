/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:29:14 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 14:29:16 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

SDL_Surface		*load_shotgun_part(int sprite)
{
	SDL_Surface *pic_surface;

	if (sprite == 0)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_1.png");
	if (sprite == 1)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_2.png");
	if (sprite == 2)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_3.png");
	if (sprite == 3)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_4.png");
	if (sprite == 4)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_5.png");
	if (sprite == 5)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_6.png");
	if (sprite == 6)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_7.png");
	if (sprite == 7)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_8.png");
	if (sprite == 8)
		pic_surface = IMG_Load("media/sprites/weapons/shotgun_9.png");
	return (pic_surface);
}

int				load_shotgun_sprite(t_main_data *main, int sprite)
{
	SDL_Surface		*pic_surface;
	unsigned int	*pixels;
	int				x;
	int				y;

	pic_surface = load_shotgun_part(sprite);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	pixels = (unsigned int *)pic_surface->pixels;
	y = -1;
	while (++y < SHOTGUN_PIC)
	{
		x = -1;
		while (++x < SHOTGUN_PIC)
			DR.shotgun[sprite][y][x] = pixels[(y * pic_surface->w) + x];
	}
	SDL_FreeSurface(pic_surface);
	ft_putendl("Shotgun Part Loaded!");
	return (1);
}

SDL_Surface		*load_pistol_part(int sprite)
{
	SDL_Surface *pic_surface;

	if (sprite == 0)
		pic_surface = IMG_Load("media/sprites/weapons/pistol_1.png");
	if (sprite == 1)
		pic_surface = IMG_Load("media/sprites/weapons/pistol_2.png");
	if (sprite == 2)
		pic_surface = IMG_Load("media/sprites/weapons/pistol_3.png");
	if (sprite == 3)
		pic_surface = IMG_Load("media/sprites/weapons/pistol_4.png");
	if (sprite == 4)
		pic_surface = IMG_Load("media/sprites/weapons/pistol_5.png");
	if (sprite == 5)
		pic_surface = IMG_Load("media/sprites/weapons/pistol_6.png");
	return (pic_surface);
}

int				load_pistol_sprite(t_main_data *main, int sprite)
{
	SDL_Surface		*pic_surface;
	unsigned int	*pixels;
	int				x;
	int				y;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	pic_surface = load_pistol_part(sprite);
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	pixels = (unsigned int *)pic_surface->pixels;
	y = -1;
	while (++y < PISTOL_PIC)
	{
		x = -1;
		while (++x < PISTOL_PIC)
			DR.pistol[sprite][y][x] = pixels[(y * pic_surface->w) + x];
	}
	SDL_FreeSurface(pic_surface);
	ft_putendl("Pistol Part Loaded!");
	return (1);
}
