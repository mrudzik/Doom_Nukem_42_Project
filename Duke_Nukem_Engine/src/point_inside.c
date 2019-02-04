/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:23:09 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 19:38:07 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

t_vec2	set_unlim_point(t_vec2 point, int flag)
{
	t_vec2		unlim_point;

	if (flag == 1)
	{
		unlim_point.x = point.x;
		unlim_point.y = INF;
	}
	else if (flag == 2)
	{
		unlim_point.x = INF;
		unlim_point.y = INF;
	}
	else
	{
		unlim_point.x = INF;
		unlim_point.y = point.y;
	}
	return (unlim_point);
}

void	set_index(int *index, int *count)
{
	*index = 0;
	*count = 0;
}

int		point_inside(t_vec2 *vertex, Uint32 npoints, t_vec2 point, int flag)
{
	t_vec2		unlim_point;
	int			count;
	int			index;
	int			next;

	set_index(&index, &count);
	unlim_point = set_unlim_point(point, flag);
	if (npoints < 3)
		return (0);
	while (1)
	{
		next = (index + 1) % npoints;
		if (stat_intersect(vertex[index], vertex[next], point, unlim_point))
		{
			if (orientation(vertex[index], point, vertex[next]) == 0)
				return (on_segment(vertex[index], point, vertex[next]));
			count++;
		}
		index = next;
		if (index == 0)
			break ;
	}
	if (count % 2 == 1)
		return (1);
	return (0);
}

int		point_on_map(t_main_data *main)
{
	Uint32	index;
	int		count;
	t_vec2	point;

	point.x = PD.where.x;
	point.y = PD.where.y;
	index = 0;
	while (index < DR.num_sectors)
	{
		count = 0;
		if (point_inside(SD[index].vertex, SD[index].npoints, point, 1) == 1)
			count++;
		if (point_inside(SD[index].vertex, SD[index].npoints, point, 2) == 1)
			count++;
		if (point_inside(SD[index].vertex, SD[index].npoints, point, 3) == 1)
			count++;
		if (count > 0)
			if (PD.sector == index)
				return (1);
		index++;
	}
	return (0);
}
