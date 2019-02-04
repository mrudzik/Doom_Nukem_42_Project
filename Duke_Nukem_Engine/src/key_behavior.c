/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_behavior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:03:10 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 14:49:00 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	movement_keys(t_main_data *main)
{
	if (main->key_state[SDL_SCANCODE_DOWN] || main->key_state[SDL_SCANCODE_S])
	{
		GM.pushing = 1;
		GM.move_vec[0] -= PD.anglecos * GM.pl_speed;
		GM.move_vec[1] -= PD.anglesin * GM.pl_speed;
	}
	if (main->key_state[SDL_SCANCODE_UP] || main->key_state[SDL_SCANCODE_W])
	{
		GM.pushing = 1;
		GM.move_vec[0] += PD.anglecos * GM.pl_speed;
		GM.move_vec[1] += PD.anglesin * GM.pl_speed;
	}
	if (main->key_state[SDL_SCANCODE_LEFT] || main->key_state[SDL_SCANCODE_A])
	{
		GM.pushing = 1;
		GM.move_vec[0] += PD.anglesin * GM.pl_speed;
		GM.move_vec[1] -= PD.anglecos * GM.pl_speed;
	}
	if (main->key_state[SDL_SCANCODE_RIGHT] || main->key_state[SDL_SCANCODE_D])
	{
		GM.pushing = 1;
		GM.move_vec[0] -= PD.anglesin * GM.pl_speed;
		GM.move_vec[1] += PD.anglecos * GM.pl_speed;
	}
}

void	advanced_movement_keys(t_main_data *main)
{
	if (main->key_state[SDL_SCANCODE_SPACE])
	{
		if (GM.ground)
		{
			PD.velocity.z += 0.5;
			GM.falling = 1;
		}
	}
	GM.ducking = 0;
	if (main->key_state[SDL_SCANCODE_LCTRL])
	{
		GM.ducking = 1;
		GM.falling = 1;
	}
	if (GM.pushing)
		GM.moving = 1;
}

void	interface_keys(t_main_data *main, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_j)
	{
		if (GM.flying == 0)
		{
			ft_putendl("fly mode on");
			GM.flying = 1;
			PD.velocity.z = 0;
		}
		else
		{
			ft_putendl("fly mode off");
			GM.flying = 0;
			GM.falling = 1;
		}
	}
	if (event.key.keysym.sym == SDLK_m)
	{
		if (main->dev_mode == 0)
			main->dev_mode = 1;
		else
			main->dev_mode = 0;
	}
}

void	interface_keys_2(t_main_data *main, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_1)
		if (PD.inventory.weapon_phase == 1)
			PD.inventory.weapon_type = 1;
	if (event.key.keysym.sym == SDLK_2)
		if (PD.inventory.weapon_phase == 1)
			PD.inventory.weapon_type = 2;
	if (event.key.keysym.sym == SDLK_f)
		interact_doors(main);
	if (event.key.keysym.sym == SDLK_g)
		interact_lifts(main);
	if (event.key.keysym.sym == SDLK_l && PD.inventory.yellow_key > 0)
	{
		if (SD[PD.sector].light == 1)
			SD[PD.sector].light = 0;
		else
			SD[PD.sector].light = 1;
	}
	if (event.key.keysym.sym == SDLK_n)
	{
		if (GM.window_modes == 0)
			GM.window_modes = 1;
		else
			GM.window_modes = 0;
	}
}

void	key_behavior(t_main_data *main)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			ft_putendl("closing cross");
			prog_quit(2, main);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
			mouse_behavior(main, event);
		if (event.type == SDL_KEYDOWN)
		{
			interface_keys(main, event);
			interface_keys_2(main, event);
		}
	}
	physic_behavior(main);
	movement_keys(main);
	advanced_movement_keys(main);
}
