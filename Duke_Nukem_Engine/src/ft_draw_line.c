/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:43:26 by mrudzik           #+#    #+#             */
/*   Updated: 2018/06/04 18:43:30 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

static t_brez	math_magic(t_coord start, t_coord end)
{
	t_brez calc;

	calc.a = end.y - start.y;
	calc.b = start.x - end.x;
	if (calc.a < 0)
		calc.sign_a = -1;
	else
		calc.sign_a = 1;
	if (calc.b < 0)
		calc.sign_b = -1;
	else
		calc.sign_b = 1;
	calc.f = 0;
	calc.x = start.x;
	calc.y = start.y;
	calc.end_x = end.x;
	calc.end_y = end.y;
	return (calc);
}

static void		help_math1(t_brez calc, t_main_data *main, int color)
{
	while (calc.x != calc.end_x || calc.y != calc.end_y)
	{
		calc.f += (calc.a * calc.sign_a);
		if (calc.f > 0)
		{
			calc.f -= (calc.b * calc.sign_b);
			calc.y += calc.sign_a;
		}
		calc.x -= calc.sign_b;
		if (calc.y > 0 && calc.y < H && calc.x > 0 && calc.x < W)
			DR.img_buff[calc.y][calc.x] = color;
	}
}

static void		help_math2(t_brez calc, t_main_data *main, int color)
{
	while (calc.x != calc.end_x || calc.y != calc.end_y)
	{
		calc.f += (calc.b * calc.sign_b);
		if (calc.f > 0)
		{
			calc.f -= (calc.a * calc.sign_a);
			calc.x -= calc.sign_b;
		}
		calc.y += calc.sign_a;
		if (calc.y > 0 && calc.y < H && calc.x > 0 && calc.x < W)
			DR.img_buff[calc.y][calc.x] = color;
	}
}

int				ft_draw_line(t_main_data *main, t_coord start,
	t_coord end, int color)
{
	t_brez calc;

	calc = math_magic(start, end);
	if (ft_abs(calc.a) < ft_abs(calc.b))
		help_math1(calc, main, color);
	else
		help_math2(calc, main, color);
	return (1);
}
