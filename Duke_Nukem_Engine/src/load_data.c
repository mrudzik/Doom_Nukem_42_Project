/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:18:39 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 16:18:43 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void				loop_preparations(t_main_data *main)
{
	PD.inventory.green_key = 0;
	PD.inventory.red_key = 0;
	PD.inventory.yellow_key = 0;
	PD.inventory.ammo = 50;
	main->dev_mode = 0;
	main->flag = 0;
	main->time = SDL_GetTicks();
	main->obj = 0;
	main->kills = 0;
	GM.window_modes = 0;
	DRI.windows = 0;
	PD.inventory.weapon_must_hit = 0;
	GM.ground = 0;
	GM.falling = 1;
	GM.moving = 0;
	GM.ducking = 0;
	GM.yaw = 0;
	GM.flying = 0;
	GM.move_vec[0] = 0.f;
	GM.move_vec[1] = 0.f;
}

Mix_Music			*load_music(char *path)
{
	Mix_Music *music;

	if (!(music = Mix_LoadMUS(path)))
		ft_putendl("music error");
	return (music);
}

int					load_all_sounds(t_main_data *main)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		ft_putendl("Could not initialize Volume Mixer");
		return (0);
	}
	main->mus = load_music("media/sounds/music.mp3");
	main->guns[0] = Mix_LoadWAV("media/sounds/pist.wav");
	main->guns[1] = Mix_LoadWAV("media/sounds/drob.wav");
	main->mus2 = load_music("media/sounds/music2.mp3");
	ft_putendl("Sounds Loaded");
	return (1);
}

void				load_textures(t_main_data *main)
{
	int y;

	DR.textures = (int **)malloc(sizeof(int *) * TEX_COUNT);
	y = 0;
	while (y < TEX_COUNT)
	{
		DR.textures[y] = (int *)malloc(sizeof(int) * (int)(TEX_H * TEX_W));
		y++;
	}
	load_image_png(main, 0, "media/textures/Brick_Big_White.png");
	load_image_png(main, 1, "media/textures/iron_diffuse.png");
	load_image_png(main, 2, "media/textures/brick_1.png");
	load_image_png(main, 3, "media/textures/Door_1.png");
	load_image_png(main, 4, "media/textures/Window_compressed.png");
	load_image_png(main, 5, "media/textures/red_hex.png");
	load_image_png(main, 6, "media/textures/gren_hex.png");
	ft_putendl("Textures Loaded!");
}

void				init_backup_framer(t_main_data *main)
{
	int y;
	int x;

	DR.saved_img_buff = (int **)malloc(sizeof(int *) * H);
	y = 0;
	while (y < H)
	{
		DR.saved_img_buff[y] = (int *)malloc(sizeof(int) * W);
		x = 0;
		while (x < W)
		{
			DR.saved_img_buff[y][x] = 0x111111;
			x++;
		}
		y++;
	}
}
