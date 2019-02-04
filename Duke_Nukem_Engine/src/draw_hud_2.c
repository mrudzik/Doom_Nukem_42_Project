/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:15:25 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 16:15:27 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	draw_key(t_main_data *main, int key, int x, int y)
{
	float		ratio;
	float		u;
	float		v;
	int			cur_x;
	int			cur_y;

	ratio = 1.3;
	u = 0;
	cur_y = y;
	while (u < CARD_H && cur_y < H)
	{
		v = 0;
		cur_x = x;
		while (v < CARD_W && cur_x < W)
		{
			if (u < CARD_H && v < CARD_W)
				if (DR.card[key][(int)u][(int)v] != 0x000000)
					DR.img_buff[cur_y][cur_x] = DR.card[key][(int)u][(int)v];
			v += ratio;
			cur_x++;
		}
		u += ratio;
		cur_y++;
	}
}

void	draw_inventory_short(t_main_data *main)
{
	int x;
	int y;

	x = W - 50;
	y = 100;
	if (PD.inventory.red_key == 1)
	{
		draw_key(main, RED_KEY, x, y);
		y += 50;
	}
	if (PD.inventory.yellow_key == 1)
	{
		draw_key(main, YELLOW_KEY, x, y);
		y += 50;
	}
	if (PD.inventory.green_key == 1)
	{
		draw_key(main, GREEN_KEY, x, y);
		y += 50;
	}
}

void	draw_inventory(t_main_data *main, SDL_Color c, int y)
{
	if (PD.inventory.red_key == 1)
	{
		draw_key(main, RED_KEY, 1050 - 50, y);
		draw_text(main, "Red Key", set_txt(1050, y, c, 20), F_DIGITAL);
		draw_text(main, "F - Doors",
			set_txt(1050, y + 20, c, 20), F_DIGITAL);
		y += 50;
	}
	if (PD.inventory.yellow_key == 1)
	{
		draw_key(main, YELLOW_KEY, 1050 - 50, y);
		draw_text(main, "Yellow Key", set_txt(1050, y, c, 20), F_DIGITAL);
		draw_text(main, "L - Lights",
			set_txt(1050, y + 20, c, 20), F_DIGITAL);
		y += 50;
	}
	if (PD.inventory.green_key == 1)
	{
		draw_key(main, GREEN_KEY, 1050 - 50, y);
		draw_text(main, "Green Key", set_txt(1050, y, c, 20), F_DIGITAL);
		draw_text(main, "G - Lifts",
			set_txt(1050, y + 20, c, 20), F_DIGITAL);
		y += 50;
	}
}

void	draw_lift_stuff(t_main_data *main)
{
	SDL_Color	c;

	if (SD[PD.sector].lift > 0)
	{
		if (PD.inventory.green_key == 0)
		{
			c.r = 150;
			c.g = 0;
			c.b = 0;
			draw_text(main, "ACCESS DENIED",
				set_txt(200, 200, c, 50), F_DIGITAL);
			draw_text(main, "To use lift please recieve GREEN KeyCard",
				set_txt(200, 250, c, 20), F_DIGITAL);
		}
		else if (PD.inventory.green_key == 1)
		{
			c.r = 0;
			c.g = 150;
			c.b = 0;
			draw_text(main, "ACCESS GRANTED",
				set_txt(200, 200, c, 50), F_DIGITAL);
			draw_text(main, "To use lift press G key",
				set_txt(200, 250, c, 20), F_DIGITAL);
		}
	}
}
