/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:18:14 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 18:02:18 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	draw_minimap(t_main_data *main)
{
	SDL_Color color;

	color.r = 180;
	color.g = 20;
	color.b = 20;
	if (main->dev_mode == 1)
	{
		draw_vectors(main);
		draw_text(main, "Powered by: Duke-Nukem Engine",
			set_txt(1, 1, color, 15), F_DIGITAL);
		draw_player_info(main);
		draw_flying_info(main);
	}
}
