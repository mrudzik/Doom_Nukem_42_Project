/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:32:36 by vomelchu          #+#    #+#             */
/*   Updated: 2019/01/11 20:39:28 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

SDL_Surface		*load_image(char *path)
{
	SDL_Surface *texture;

	texture = IMG_Load(path);
	if (texture == NULL)
	{
		ft_putendl("Bad load image");
		exit(1);
	}
	return (texture);
}

unsigned int	get_pixel_int1(SDL_Surface *surface, int x, int y)
{
	unsigned int	*pixels;

	pixels = (unsigned int*)surface->pixels;
	return (pixels[(y * surface->w) + x]);
}

int				go(t_main_data *main, t_data *data)
{
	parser(data, main);
	start_a_game(main);
	return (0);
}

void			draw_menu(t_main_data *main)
{
	int q;
	int i;

	q = -1;
	while (++q != H - 1)
	{
		i = 0;
		while (++i != W - 1)
			DR.img_buff[q][i] = get_pixel_int1(MM.menu, i, q);
	}
}
