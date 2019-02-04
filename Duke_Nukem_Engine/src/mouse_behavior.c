/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:28:54 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 17:06:10 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	mouse_behavior(t_main_data *main, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (PD.inventory.weapon_type == 1 && PD.inventory.weapon_phase
			== 1 && PD.inventory.ammo >= 1)
		{
			PD.inventory.weapon_phase++;
			PD.inventory.ammo--;
			PD.inventory.weapon_must_hit = 1;
			Mix_PlayChannel(-1, main->guns[0], 0);
		}
		else if (PD.inventory.weapon_type == 2 && PD.inventory.weapon_phase
			== 1 && PD.inventory.ammo >= 5)
		{
			PD.inventory.weapon_phase++;
			PD.inventory.ammo -= 5;
			PD.inventory.weapon_must_hit = 5;
			Mix_PlayChannel(-1, main->guns[1], 0);
		}
	}
}
