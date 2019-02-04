/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:29:15 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 20:18:57 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	sprite_write_data(t_main_data *main, int sect, int sprite)
{
	SD[sect].things[sprite].sprite_w = 1;
	SD[sect].things[sprite].sprite_floor = SD[sect].floor;
	SD[sect].things[sprite].sprite_ceil =
	SD[sect].things[sprite].sprite_floor + 8;
	if (SD[sect].things[sprite].sprite_id == YELLOW_KEY
			|| SD[sect].things[sprite].sprite_id == GREEN_KEY
			|| SD[sect].things[sprite].sprite_id == RED_KEY)
	{
		SD[sect].things[sprite].sprite_width = CARD_W;
		SD[sect].things[sprite].sprite_heigh = CARD_H;
	}
	if (SD[sect].things[sprite].sprite_id == MEDPACK
			|| SD[sect].things[sprite].sprite_id == AMMO
			|| SD[sect].things[sprite].sprite_id == ARMOR)
	{
		SD[sect].things[sprite].sprite_width = ITEM_W;
		SD[sect].things[sprite].sprite_heigh = ITEM_H;
	}
	if (SD[sect].things[sprite].sprite_id == IMP)
	{
		SD[sect].things[sprite].sprite_width = ITEM_W;
		SD[sect].things[sprite].sprite_heigh = ITEM_H;
	}
}

void	sprite_analyzing(t_main_data *main)
{
	int sect;
	int sprite;

	sect = 0;
	while ((Uint32)sect < DR.num_sectors)
	{
		sprite = 0;
		while (sprite < MAX_SPRITES)
		{
			if (SD[sect].things[sprite].sprite_id != -1)
				sprite_write_data(main, sect, sprite);
			sprite++;
		}
		sect++;
	}
}

int		sprite_loading(t_main_data *main)
{
	int sect;
	int sprite;

	sect = 0;
	while ((Uint32)sect < DR.num_sectors)
	{
		SD[sect].things = (t_thing*)malloc(sizeof(t_thing) * 5);
		sprite = 0;
		while (sprite < MAX_SPRITES)
		{
			SD[sect].things[sprite].sprite_id = -1;
			sprite++;
		}
		sect++;
	}
	return (1);
}
