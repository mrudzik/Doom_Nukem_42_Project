/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:09:49 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 20:09:51 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

int		on_segment(t_vec2 p, t_vec2 q, t_vec2 r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x)
			&& q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return (1);
	return (0);
}

int		orientation(t_vec2 p, t_vec2 q, t_vec2 r)
{
	int val;

	val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
		return (0);
	if (val > 0)
		return (1);
	return (2);
}

int		stat_intersect(t_vec2 p1, t_vec2 q1, t_vec2 p2, t_vec2 q2)
{
	int o1;
	int o2;
	int o3;
	int o4;

	o1 = orientation(p1, q1, p2);
	o2 = orientation(p1, q1, q2);
	o3 = orientation(p2, q2, p1);
	o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4)
		return (1);
	if (o1 == 0 && on_segment(p1, p2, q1))
		return (1);
	if (o2 == 0 && on_segment(p1, q2, q1))
		return (1);
	if (o3 == 0 && on_segment(p2, p1, q2))
		return (1);
	if (o4 == 0 && on_segment(p2, q1, q2))
		return (1);
	return (0);
}
