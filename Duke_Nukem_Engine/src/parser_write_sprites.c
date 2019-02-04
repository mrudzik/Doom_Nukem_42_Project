/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_write_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:30:57 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 15:31:16 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	parse_find_items(t_main_data *main, char **reading, int y,
	int *sec_sprites)
{
	int *num_array;

	if (ft_strncmp("ammunition ", reading[y], 11) == 0)
	{
		num_array = ft_intsplit(reading[y], ' ');
		if (sec_sprites[num_array[5]] < 5)
		{
			if (num_array[2] == 1)
				SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.sprite_id = AMMO;
			else if (num_array[2] == 2)
				SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.sprite_id = MEDPACK;
			else if (num_array[2] == 3)
				SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.sprite_id = ARMOR;
			SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.position.x = num_array[3];
			SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.position.y = num_array[4];
			sec_sprites[num_array[5]]++;
		}
		ft_intdel(&num_array);
	}
}

void	parse_find_enemy(t_main_data *main, char **reading, int y,
	int *sec_sprites)
{
	int *num_array;

	if (ft_strncmp("enemy ", reading[y], 6) == 0)
	{
		num_array = ft_intsplit(reading[y], ' ');
		if (sec_sprites[num_array[4]] < 5)
		{
			SD[num_array[4]].things[sec_sprites[num_array[4]]]
			.sprite_id = IMP;
			SD[num_array[4]].things[sec_sprites[num_array[4]]]
			.position.x = num_array[2];
			SD[num_array[4]].things[sec_sprites[num_array[4]]]
			.position.y = num_array[3];
			sec_sprites[num_array[4]]++;
		}
		ft_intdel(&num_array);
	}
}

void	parse_find_key(t_main_data *main, char **reading, int y,
	int *sec_sprites)
{
	int *num_array;

	if (ft_strncmp("key ", reading[y], 4) == 0)
	{
		num_array = ft_intsplit(reading[y], ' ');
		if (sec_sprites[num_array[5]] < 5)
		{
			if (num_array[2] == 1)
				SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.sprite_id = RED_KEY;
			if (num_array[2] == 2)
				SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.sprite_id = YELLOW_KEY;
			if (num_array[2] == 3)
				SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.sprite_id = GREEN_KEY;
			SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.position.x = num_array[3];
			SD[num_array[5]].things[sec_sprites[num_array[5]]]
			.position.y = num_array[4];
			sec_sprites[num_array[5]]++;
		}
		ft_intdel(&num_array);
	}
}
