/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:29:57 by vomelchu          #+#    #+#             */
/*   Updated: 2019/01/11 16:28:23 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

int		event_help(t_main_data *main, t_data *data, SDL_Event event)
{
	if (KEY == SDLK_RETURN && MM.num_menu == 1)
		MM.flag = 1;
	else if (KEY == SDLK_RETURN && MM.num_menu == 2
			&& MM.flag != 1)
		return (1);
	else if (KEY == SDLK_RETURN && MM.num_menu == 0
			&& MM.flag == 1)
	{
		data->name = "./media/maps/1_level.map";
		if (go(main, data) == 1)
			return (1);
	}
	else if (KEY == SDLK_RETURN && MM.num_menu == 2
			&& MM.flag == 1)
	{
		data->name = "./media/maps/2_level.map";
		if (go(main, data) == 1)
			return (1);
	}
	return (0);
}

int		event_menu(t_main_data *main, t_data *data)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(1);
		if (EXIT && MM.flag == 1)
			MM.flag = 0;
		else if (EXIT)
			exit(1);
		else if (event.type == SDL_KEYDOWN && (KEY == SDLK_UP)
				&& MM.num_menu > 0)
			MM.num_menu--;
		else if (event.type == SDL_KEYDOWN && (KEY == SDLK_DOWN)
				&& MM.num_menu < 2)
			MM.num_menu++;
		else if (event_help(main, data, event) == 1)
			return (1);
		else if (KEY == SDLK_RETURN && MM.num_menu == 0
				&& MM.flag != 1)
			if (go(main, data) == 1)
				return (1);
	}
	return (0);
}

void	str_chang(t_main_data *main)
{
	if (MM.flag == 0)
	{
		MM.str[0] = "NEW GAME";
		MM.str[1] = "LEVELS";
		MM.str[2] = "EXIT";
	}
	else
	{
		MM.str[0] = "LEVEL 1";
		MM.str[1] = "";
		MM.str[2] = "LEVEL 2";
	}
}

void	draw_lines(t_main_data *main)
{
	int q;

	q = -1;
	str_chang(main);
	while (++q != 3)
	{
		MM.m_color.r = 255;
		MM.m_color.g = 255;
		MM.m_color.b = 255;
		if (q == MM.num_menu)
		{
			MM.m_color.r = 10;
			MM.m_color.g = 252;
			MM.m_color.b = 18;
		}
		draw_text(main, MM.str[q], set_txt(450, 250 + (q * 100),
			MM.m_color, 100), F_DIGITAL);
	}
}

int		menu(t_main_data *main, t_data *data)
{
	int q;

	q = 0;
	MM.num_menu = 0;
	MM.flag = 0;
	MM.menu = load_image("./media/menu.png");
	while (q == 0)
	{
		render_mechanics(main);
		if (event_menu(main, data) == 1)
			return (0);
		draw_menu(main);
		draw_lines(main);
		SDL_RenderPresent(main->renderer);
	}
	return (0);
}
