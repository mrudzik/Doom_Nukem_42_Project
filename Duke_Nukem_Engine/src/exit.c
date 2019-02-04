/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:30:57 by ylesik            #+#    #+#             */
/*   Updated: 2019/01/11 14:34:17 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	sdl_quit(t_main_data *main, int e)
{
	int i;

	i = -1;
	if (main->texture != NULL)
		SDL_DestroyTexture(main->texture);
	SDL_DestroyRenderer(main->renderer);
	SDL_DestroyWindow(main->window);
	SDL_Quit();
	if (e == 2)
		ft_putstr("Please, fix map!\n");
	exit(e);
}
