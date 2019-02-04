/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:57:06 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 16:31:34 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	draw_cross(t_main_data *main)
{
	t_coord	start;
	t_coord	end;
	int		color;

	color = 0xedc500;
	start.x = 600;
	start.y = 390;
	end.x = 600;
	end.y = 380;
	ft_draw_line(main, start, end, color);
	start.y = 420;
	end.y = 410;
	ft_draw_line(main, start, end, color);
	start.x = 590;
	start.y = 400;
	end.x = 580;
	end.y = 400;
	ft_draw_line(main, start, end, color);
	start.x = 610;
	end.x = 620;
	ft_draw_line(main, start, end, color);
}

void	take_obj(t_main_data *main)
{
	int q;
	int i;
	int k;
	int color;

	color = 0x005500;
	if (main->flag == 1)
		color = 0x990000;
	q = SDL_GetTicks();
	if (q - main->time < 500)
	{
		i = -1;
		while (++i < H)
		{
			k = -1;
			while (++k < W)
				DR.img_buff[i][k] += color;
		}
	}
	else
		main->flag = 0;
}

void	game_loop(t_main_data *main)
{
	loop_preparations(main);
	sprite_analyzing(main);
	find_pink_msg(main);
	Mix_PlayMusic(main->mus, -1);
	while (1)
	{
		render_mechanics(main);
		ingame_mechanics(main);
		draw_skybox(main);
		draw_screen(main);
		if (GM.ground == 1)
			draw_sprites(main);
		take_obj(main);
		draw_weapons(main);
		draw_cross(main);
		draw_helmet(main);
		draw_minimap(main);
		draw_hud(main);
		SDL_RenderPresent(main->renderer);
	}
	you_died(main);
	prog_quit(1, main);
}

void	start_a_game(t_main_data *main)
{
	if (load_all_sounds(main) == 0)
		prog_quit(1, main);
	load_textures(main);
	load_helmet(main);
	load_weapons(main);
	load_items(main);
	load_skybox_pix(main, "media/skybox/skybox_1.png");
	init_backup_framer(main);
	if (point_on_map(main) != 1)
	{
		you_died(main);
		prog_quit(1, main);
	}
	game_loop(main);
	sdl_quit(main, 0);
}

int		main(int argc, char **argv)
{
	t_main_data		main;
	t_data			*data;

	sdl_start_protocols(&main);
	init_start(&main);
	TTF_Init();
	
	if (argc != 2)
		return (0);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error1("bad t_data malloc\n");
	data->name = argv[1];
	data->fd = open(data->name, O_DIRECTORY);
	if (data->fd >= 0)
		ft_error1("it's directory\n");
	
	menu(&main, data);
	return (0);
}
