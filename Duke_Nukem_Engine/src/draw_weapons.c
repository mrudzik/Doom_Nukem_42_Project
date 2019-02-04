/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:28:38 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 13:41:39 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void			load_pistol_animation(t_main_data *main)
{
	int y;
	int sprite;
	int all_sprites;

	all_sprites = 6;
	DR.pistol = (int***)malloc(sizeof(int **) * all_sprites);
	sprite = 0;
	while (sprite < all_sprites)
	{
		DR.pistol[sprite] = (int**)malloc(sizeof(int *) * PISTOL_PIC);
		y = 0;
		while (y < PISTOL_PIC)
		{
			DR.pistol[sprite][y] = (int*)malloc(sizeof(int) * PISTOL_PIC);
			y++;
		}
		load_pistol_sprite(main, sprite);
		sprite++;
	}
}

void			load_shotgun_animation(t_main_data *main)
{
	int y;
	int sprite;
	int all_sprites;

	all_sprites = 9;
	DR.shotgun = (int***)malloc(sizeof(int **) * all_sprites);
	sprite = 0;
	while (sprite < all_sprites)
	{
		DR.shotgun[sprite] = (int**)malloc(sizeof(int *) * SHOTGUN_PIC);
		y = 0;
		while (y < SHOTGUN_PIC)
		{
			DR.shotgun[sprite][y] = (int*)malloc(sizeof(int) * SHOTGUN_PIC);
			y++;
		}
		load_shotgun_sprite(main, sprite);
		sprite++;
	}
}

void			load_weapons(t_main_data *main)
{
	load_pistol_animation(main);
	load_shotgun_animation(main);
	PD.inventory.weapon_type = 1;
	PD.inventory.weapon_phase = 1;
}

void			draw_weapons(t_main_data *main)
{
	if (PD.inventory.weapon_type == 1)
		draw_pistol_animation(main);
	if (PD.inventory.weapon_type == 2)
		draw_shotgun_animation(main);
}
