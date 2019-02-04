/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_png.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:44:52 by mrudzik           #+#    #+#             */
/*   Updated: 2018/09/18 12:02:36 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

unsigned int	get_pixel_int(SDL_Surface *surface, int x, int y)
{
	unsigned int *pixels;

	pixels = (unsigned int *)surface->pixels;
	return (pixels[(y * surface->w) + x]);
}

int				load_image_png(t_main_data *main, int tex_arr_num, char *path)
{
	SDL_Surface		*pic_surface;
	int				x;
	int				y;
	unsigned int	*pixels;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	pic_surface = IMG_Load(path);
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	pixels = (unsigned int *)pic_surface->pixels;
	y = -1;
	while (++y < TEX_H)
	{
		x = -1;
		while (++x < TEX_W)
			DR.textures[tex_arr_num][x + (TEX_W * y)] =
		pixels[(y * pic_surface->w) + x];
	}
	SDL_FreeSurface(pic_surface);
	return (1);
}

SDL_Surface		*load_png_picture(char *path)
{
	SDL_Surface		*pic_surface;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	pic_surface = IMG_Load(path);
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (NULL);
	}
	return (pic_surface);
}
