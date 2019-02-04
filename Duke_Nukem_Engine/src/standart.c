/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:29:27 by ylesik            #+#    #+#             */
/*   Updated: 2019/01/11 20:27:33 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	max(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

float	clamp(float a, float mi, float ma)
{
	return (min(max(a, mi), ma));
}

float	vxs(float x0, float y0, float x1, float y1)
{
	return ((x0) * (y1) - (x1) * (y0));
}

float	pointside(t_vec3 cr1, float y0, float x1, float y1)
{
	return (vxs((x1) - (cr1.z), (y1) - (y0), (cr1.x)
		- (cr1.z), (cr1.y) - (y0)));
}
