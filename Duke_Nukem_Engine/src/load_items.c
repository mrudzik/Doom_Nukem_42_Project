/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:41:14 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 17:41:16 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

int		upload_cards(t_main_data *main, int card_num, char *path)
{
	SDL_Surface		*pic_surface;
	unsigned int	*pixels;
	int				x;
	int				y;

	pic_surface = IMG_Load(path);
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	DR.card[card_num] = (int**)malloc(sizeof(int *) * CARD_H);
	pixels = (unsigned int *)pic_surface->pixels;
	y = -1;
	while (++y < CARD_H)
	{
		x = -1;
		DR.card[card_num][y] = (int *)malloc(sizeof(int) * CARD_W);
		while (++x < CARD_W)
			DR.card[card_num][y][x] = pixels[(y * pic_surface->w) + x];
	}
	SDL_FreeSurface(pic_surface);
	return (1);
}

int		upload_items(t_main_data *main, int item_num, char *path)
{
	SDL_Surface		*pic_surface;
	unsigned int	*pixels;
	int				x;
	int				y;

	pic_surface = IMG_Load(path);
	if (!pic_surface)
	{
		ft_putendl("Img_Load:");
		ft_putendl(IMG_GetError());
		return (-1);
	}
	DR.item[item_num] = (int**)malloc(sizeof(int *) * ITEM_H);
	pixels = (unsigned int *)pic_surface->pixels;
	y = -1;
	while (++y < ITEM_H)
	{
		x = -1;
		DR.item[item_num][y] = (int *)malloc(sizeof(int) * ITEM_W);
		while (++x < ITEM_W)
			DR.item[item_num][y][x] = pixels[(y * pic_surface->w) + x];
	}
	SDL_FreeSurface(pic_surface);
	return (1);
}
