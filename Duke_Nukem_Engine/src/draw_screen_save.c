/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_save.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:52:07 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 18:52:09 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void			draw_previous_frame(t_main_data *main)
{
	int x;
	int y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			DR.img_buff[y][x] = DR.saved_img_buff[y][x];
			x++;
		}
		y++;
	}
}

void			save_current_frame(t_main_data *main)
{
	int x;
	int y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			DR.saved_img_buff[y][x] = DR.img_buff[y][x];
			x++;
		}
		y++;
	}
}
