/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:13:30 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 17:51:09 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	upload_all_cards(t_main_data *main)
{
	upload_cards(main, YELLOW_KEY, "media/sprites/items/yellow_key.png");
	ft_putendl("Yellow Card Loaded");
	upload_cards(main, RED_KEY, "media/sprites/items/red_key.png");
	ft_putendl("Red Card Loaded");
	upload_cards(main, GREEN_KEY, "media/sprites/items/green_key.png");
	ft_putendl("Green Card Loaded");
}

void	upload_all_items(t_main_data *main)
{
	upload_items(main, 0, "media/sprites/items/medkit.png");
	ft_putendl("Medpack Loaded");
	upload_items(main, 1, "media/sprites/items/ammo.png");
	ft_putendl("Ammo Box Loaded");
	upload_items(main, 2, "media/sprites/items/true_armor.png");
	ft_putendl("True Armor Loaded");
}

void	upload_all_enemies(t_main_data *main)
{
	upload_items(main, 3, "media/sprites/vrajina/Imp_resized_1.png");
	ft_putendl("Imp 1 Loaded");
	upload_items(main, 4, "media/sprites/vrajina/Imp_resized_2.png");
	ft_putendl("Imp 2 Loaded");
	upload_items(main, 5, "media/sprites/vrajina/Imp_resized_3.png");
	ft_putendl("Imp 3 Loaded");
	upload_items(main, 6, "media/sprites/vrajina/Imp_resized_4.png");
	ft_putendl("Imp 4 Loaded");
	upload_items(main, 7, "media/sprites/vrajina/Imp_resized_5.png");
	ft_putendl("Imp 5 Loaded");
	upload_items(main, 8, "media/sprites/vrajina/Imp_resized_6.png");
	ft_putendl("Imp 6 Loaded");
	upload_items(main, 9, "media/sprites/vrajina/Imp_resized_7.png");
	ft_putendl("Imp 7 Loaded");
	upload_items(main, 10, "media/sprites/vrajina/Imp_resized_8.png");
	ft_putendl("Imp 8 Loaded");
}

int		load_items(t_main_data *main)
{
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		ft_putendl(IMG_GetError());
	DR.card = (int***)malloc(sizeof(int **) * 3);
	upload_all_cards(main);
	DR.item = (int***)malloc(sizeof(int **) * 11);
	upload_all_items(main);
	upload_all_enemies(main);
	return (1);
}
