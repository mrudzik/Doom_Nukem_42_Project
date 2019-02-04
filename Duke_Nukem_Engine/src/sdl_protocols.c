/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_protocols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:10:21 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 20:15:50 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	sdl_start_protocols(t_main_data *main)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		if ((main->window = SDL_CreateWindow("Doom-Nukem Polygonized",
SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_FOREIGN)))
			if ((main->renderer = SDL_CreateRenderer(main->window, -1,
SDL_RENDERER_PRESENTVSYNC)))
				if ((main->texture = SDL_CreateTexture(main->renderer,
SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, W, H)))
					return ;
	ft_putendl(SDL_GetError());
	sdl_quit(main, 1);
}
