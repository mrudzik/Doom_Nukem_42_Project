/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:17:47 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/10 21:01:11 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	find_pink_msg(t_main_data *main)
{
	SDL_Color	color;
	int			i;

	i = 0;
	while (i < 20)
	{
		color.r += 10;
		color.b += 5;
		SDL_RenderClear(main->renderer);
		draw_text(main, "FIND THE PINK ZONE",
			set_txt(400, 350, color, 50), F_DIGITAL);
		SDL_RenderPresent(main->renderer);
		SDL_Delay(100);
		i++;
	}
}

void	score_msg(t_main_data *main)
{
	SDL_Color	color;
	int			i;
	char		*str;

	i = 0;
	while (i < 20)
	{
		color.r += 10;
		color.b += 5;
		draw_text(main, "YOU HAVE FOUND THE PINK ZONE",
			set_txt(200, 450, color, 50), F_DIGITAL);
		draw_text(main, "KILLS :  ", set_txt(200, 600, color, 50), F_DIGITAL);
		draw_text(main, "ITEMS :  ", set_txt(200, 650, color, 50), F_DIGITAL);
		str = ft_itoa(main->kills);
		draw_text(main, str, set_txt(400, 600, color, 50), F_DIGITAL);
		free(str);
		str = ft_itoa(main->obj);
		draw_text(main, str, set_txt(400, 650, color, 50), F_DIGITAL);
		free(str);
		SDL_RenderPresent(main->renderer);
		SDL_Delay(200);
		i++;
	}
}

void	you_won_msg(t_main_data *main)
{
	SDL_Color	color;
	int			i;

	i = 0;
	while (i < 20)
	{
		color.r += 10;
		color.b += 5;
		SDL_RenderClear(main->renderer);
		draw_text(main, "YOU WON", set_txt(300, 300, color, 150), F_DIGITAL);
		SDL_RenderPresent(main->renderer);
		SDL_Delay(100);
		i++;
	}
	score_msg(main);
	SDL_Delay(1000);
}

void	you_died(t_main_data *main)
{
	SDL_Color	color;
	int			i;

	if (SD[PD.sector].end == 1)
		you_won_msg(main);
	else
	{
		i = 0;
		while (i < 20)
		{
			color.r += 10;
			SDL_RenderClear(main->renderer);
			draw_text(main, "YOU DIED",
				set_txt(330, 300, color, 150), F_DIGITAL);
			SDL_RenderPresent(main->renderer);
			SDL_Delay(100);
			i++;
		}
		SDL_Delay(200);
	}
}

int		calc_damage(t_main_data *main)
{
	if (SD[PD.sector].ceil <= SD[PD.sector].floor)
		PD.inventory.hp -= 10;
	if (PD.inventory.hp <= 0)
		return (-1);
	if (SD[PD.sector].end == 1)
		return (-1);
	return (1);
}
