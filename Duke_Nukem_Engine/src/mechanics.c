/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:36:39 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 16:36:41 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	physic_behavior(t_main_data *main)
{
	GM.pl_speed = 0.15f;
	if (main->key_state[SDL_SCANCODE_LSHIFT])
		GM.pl_speed = 0.3f;
	GM.pushing = 0;
	GM.move_vec[0] = 0.f;
	GM.move_vec[1] = 0.f;
	if (main->key_state[SDL_SCANCODE_ESCAPE])
	{
		ft_putendl("closing escape");
		prog_quit(2, main);
	}
	if (GM.flying == 1)
	{
		if (main->key_state[SDL_SCANCODE_KP_PLUS] && PD.inventory.armor > 0)
		{
			PD.inventory.armor--;
			PD.velocity.z += 0.5;
		}
		if (main->key_state[SDL_SCANCODE_KP_MINUS])
			PD.velocity.z -= 0.5;
	}
}

void	ingame_mechanics(t_main_data *main)
{
	GM.eyeheight = GM.ducking ? DUCKHEIGHT : EYEHEIGHT;
	GM.ground = !GM.falling;
	fly_mode(main);
	vertical_collision(main);
	horizontal_collision(main, GM.move_vec[0], GM.move_vec[1], -1);
	key_behavior(main);
	mouse_aim(main);
	if (calc_damage(main) == -1)
	{
		you_died(main);
		prog_quit(1, main);
	}
	if (GM.doors_pending > 0)
		check_doors(main);
	if (GM.lifts_pending > 0)
		check_lifts(main, 0);
}

void	render_mechanics(t_main_data *main)
{
	SDL_RenderClear(main->renderer);
	SDL_UpdateTexture(main->texture, NULL, DR.img_buff, W << 2);
	SDL_RenderCopy(main->renderer, main->texture, NULL, NULL);
}
