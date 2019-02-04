/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:18:35 by vomelchu          #+#    #+#             */
/*   Updated: 2019/01/02 13:22:46 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	solid_rect(t_data *data)
{
	int x;
	int y;

	x = 494;
	while (++x != WIDTH - 1)
	{
		y = 223;
		while (++y != HEIGHT - 1)
		{
			data->buf[y][x] = get_pixel_int(data->text_menu, x - 494, y - 223);
		}
	}
}

void	picture_icon(t_data *data, int st_x, int st_y, SDL_Surface *icon)
{
	int q;
	int i;

	q = st_y - 1;
	while (++q < st_y + data->pixel_pict)
	{
		if (q < data->min_coord_icon || q > HEIGHT - 1)
			continue;
		i = st_x - 1;
		while (++i < st_x + data->pixel_pict)
		{
			if (i < 0 || i > WIDTH - 1)
				continue;
			if (get_pixel_int(icon, i - st_x, q - st_y) != 0)
				data->buf[q][i] = get_pixel_int(icon, i - st_x, q - st_y);
		}
	}
}

void	picture(t_data *data)
{
	int q;
	int i;

	q = -1;
	while (++q < 223)
	{
		i = -1;
		while (++i < 720)
			data->buf[q][i] =
				get_pixel_int(data->dot[data->picture_menu % 4], i, q);
	}
}

void	menu(t_data *data, int i)
{
	char *str;

	picture(data);
	if (i == 0 && data->show_text != 1 && data->key != 1)
		event_menu(data);
	if (i == 0 && data->flo_or_cei == 0 && data->floor > data->ceil - 5)
		data->floor = data->ceil - 5;
	if (i == 0 && data->flo_or_cei == 1 && data->ceil < data->floor + 5)
		data->ceil = data->floor + 5;
	str = ft_itoa(data->floor);
	data->font_size = 38;
	draw_text(data, str, 130, 75);
	free(str);
	str = ft_itoa(data->ceil);
	draw_text(data, str, 555, 75);
	free(str);
	icons(data);
	textures_menu(data);
}
