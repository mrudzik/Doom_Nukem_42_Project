/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:58:39 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 22:53:29 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	texture_sprite(t_main_data *main)
{
	if (DRM.sect->things[DRS.spr_num].sprite_id == YELLOW_KEY)
		draw_key_sprite(main, YELLOW_KEY);
	if (DRM.sect->things[DRS.spr_num].sprite_id == RED_KEY)
		draw_key_sprite(main, RED_KEY);
	if (DRM.sect->things[DRS.spr_num].sprite_id == GREEN_KEY)
		draw_key_sprite(main, GREEN_KEY);
	if (DRM.sect->things[DRS.spr_num].sprite_id == MEDPACK)
		draw_item_sprite(main, 0);
	if (DRM.sect->things[DRS.spr_num].sprite_id == AMMO)
		draw_item_sprite(main, 1);
	if (DRM.sect->things[DRS.spr_num].sprite_id == ARMOR)
		draw_item_sprite(main, 2);
	if (DRM.sect->things[DRS.spr_num].sprite_id == IMP)
		draw_imp_stuff(main);
}

void	item_interactions2(t_main_data *main, int res)
{
	if (res == AMMO)
	{
		PD.inventory.ammo += 15;
		if (PD.inventory.ammo > 300)
			PD.inventory.ammo = 300;
	}
	else if (res == ARMOR)
	{
		PD.inventory.armor += 50;
		if (PD.inventory.armor > 500)
			PD.inventory.armor = 500;
	}
	else if (res == IMP)
		DRM.sect->things[DRS.spr_num].sprite_id = IMP;
}

void	item_interactions(t_main_data *main, int res)
{
	if (res == YELLOW_KEY)
		PD.inventory.yellow_key = 1;
	else if (res == RED_KEY)
		PD.inventory.red_key = 1;
	else if (res == GREEN_KEY)
		PD.inventory.green_key = 1;
	else if (res == MEDPACK)
	{
		PD.inventory.hp += 10;
		if (PD.inventory.hp > 100)
			PD.inventory.hp = 100;
	}
	item_interactions2(main, res);
}

void	draw_sprites_in_sector(t_main_data *main)
{
	int res;

	DRS.spr_num = 0;
	while (DRS.spr_num < 5)
	{
		if (DRM.sect->things[DRS.spr_num].sprite_id >= 0)
		{
			res = calc_sprite_view(main);
			if (res == 10)
				texture_sprite(main);
			else if (res >= 0)
				item_interactions(main, res);
		}
		DRS.spr_num++;
	}
}

void	draw_sprites(t_main_data *main)
{
	int renderedsectors[DR.num_sectors];

	draw_screen_init(main, renderedsectors);
	while (DR.head != DR.tail)
	{
		DRM.now = *DR.tail;
		if (++DR.tail == DR.queue + MAX_QUEUE)
			DR.tail = DR.queue;
		if (renderedsectors[DRM.now.sectorno] & 0x21)
			continue;
		++renderedsectors[DRM.now.sectorno];
		DRM.sect = &SD[DRM.now.sectorno];
		draw_wall_textures(main);
		draw_sprites_in_sector(main);
		++renderedsectors[DRM.now.sectorno];
	}
}
