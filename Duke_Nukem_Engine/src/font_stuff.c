/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:44:47 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 14:39:18 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

int			init_fonts(t_main_data *main, char *font_path, int font_size)
{
	MF.font_ttf = TTF_OpenFont(font_path, font_size);
	if (!MF.font_ttf)
	{
		ft_putendl(SDL_GetError());
		return (0);
	}
	return (1);
}

t_text		set_txt(int x, int y, SDL_Color color, int font_size)
{
	t_text res;

	res.pos.x = x;
	res.pos.y = y;
	res.color = color;
	res.size = font_size;
	return (res);
}

int			draw_text(t_main_data *main,
		char *text, t_text txt, char *font_path)
{
	int	tw;
	int	th;

	if (text == NULL)
		return (0);
	if (txt.size < 1 || txt.size > 999)
		return (0);
	MF.font_ttf = TTF_OpenFont(font_path, font_size);
	if (!MF.font_ttf)
	{
		ft_putendl(SDL_GetError());
		return (0);
	}
	MF.font_surf = TTF_RenderText_Solid(MF.font_ttf, text, txt.color);
	MF.font_textr = SDL_CreateTextureFromSurface(main->renderer, MF.font_surf);
	SDL_QueryTexture(MF.font_textr, NULL, NULL, &tw, &th);
	MF.font_rect.x = txt.pos.x;
	MF.font_rect.y = txt.pos.y;
	MF.font_rect.w = tw;
	MF.font_rect.h = th;
	SDL_RenderCopy(main->renderer, MF.font_textr, NULL, &MF.font_rect);
	SDL_DestroyTexture(MF.font_textr);
	SDL_FreeSurface(MF.font_surf);
	TTF_CloseFont(MF.font_ttf);
	return (1);
}
