/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:25:37 by ylesik            #+#    #+#             */
/*   Updated: 2019/01/11 14:43:33 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	init_start(t_main_data *main)
{
	main->draw.num_sectors = 0;
	main->sectors = NULL;
	main->key_state = SDL_GetKeyboardState(NULL);
	SDL_ShowCursor(SDL_ENABLE);
}
