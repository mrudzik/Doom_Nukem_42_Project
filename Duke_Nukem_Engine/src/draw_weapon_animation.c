/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:27:12 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 14:27:18 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void			draw_shotgun(t_main_data *main, int x_pos,
	int y_pos, int sprite)
{
	int		x;
	int		y;
	int		x_img;
	float	x_num;
	float	y_num;

	y = 0;
	y_num = 0;
	while (y < SHOTGUN_PIC && y_pos < H)
	{
		x = 0;
		x_num = 0;
		x_img = x_pos;
		while (x < SHOTGUN_PIC - 1 && x_img < W)
		{
			x_num += 0.35;
			x = (int)x_num;
			if (DR.shotgun[sprite][y][x] != 0x000000)
				DR.img_buff[y_pos][x_img] = DR.shotgun[sprite][y][x];
			x_img++;
		}
		y_num += 0.35;
		y = (int)y_num;
		y_pos++;
	}
}

void			draw_pistol(t_main_data *main, int x_pos, int y_pos, int sprite)
{
	int		x;
	int		y;
	int		x_img;
	float	x_num;
	float	y_num;

	y = 0;
	y_num = 0;
	while (y < PISTOL_PIC && y_pos < H)
	{
		x = 0;
		x_num = 0;
		x_img = x_pos;
		while (x < PISTOL_PIC - 1 && x_img < W)
		{
			x_num += 0.35;
			x = (int)x_num;
			if (DR.pistol[sprite][y][x] != 0x000000)
				DR.img_buff[y_pos][x_img] = DR.pistol[sprite][y][x];
			x_img++;
		}
		y_num += 0.35;
		y = (int)y_num;
		y_pos++;
	}
}

void			draw_pistol_animation(t_main_data *main)
{
	if (PD.inventory.weapon_phase == 1)
		draw_pistol(main, 600, H - 400, 0);
	else if (PD.inventory.weapon_phase > 1)
	{
		draw_pistol(main, 600, H - 400, (int)PD.inventory.weapon_phase - 1);
		PD.inventory.weapon_phase += 0.5;
	}
	if (PD.inventory.weapon_phase >= 7)
		PD.inventory.weapon_phase = 1;
	if (PD.inventory.weapon_phase >= 3)
		PD.inventory.weapon_must_hit = 0;
}

void			draw_shotgun_animation(t_main_data *main)
{
	if (PD.inventory.weapon_phase == 1)
		draw_shotgun(main, 450, 270, 0);
	else if (PD.inventory.weapon_phase > 1)
	{
		draw_shotgun(main, 450, 270, (int)PD.inventory.weapon_phase - 1);
		PD.inventory.weapon_phase += 0.2;
	}
	if (PD.inventory.weapon_phase >= 10)
		PD.inventory.weapon_phase = 1;
	if (PD.inventory.weapon_phase >= 4)
		PD.inventory.weapon_must_hit = 0;
}
