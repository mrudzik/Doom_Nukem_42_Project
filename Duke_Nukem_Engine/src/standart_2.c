/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:31:04 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 20:31:06 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

t_vec2	intersect(t_vec3 cr1, t_vec3 cr2, float x4, float y4)
{
	t_vec2 xy;

	xy.x = vxs(vxs(cr1.x, cr1.y, cr1.z, cr2.x), (cr1.x) - (cr1.z),
		vxs(cr2.y, cr2.z, x4, y4), (cr2.y) - (x4)) /
		vxs((cr1.x) - (cr1.z), (cr1.y) - (cr2.x), (cr2.y) - (x4),
			(cr2.z) - (y4));
	xy.y = vxs(vxs(cr1.x, cr1.y, cr1.z, cr2.x), (cr1.y) - (cr2.x),
		vxs(cr2.y, cr2.z, x4, y4), (cr2.z) - (y4)) /
		vxs((cr1.x) - (cr1.z), (cr1.y) - (cr2.x), (cr2.y) - (x4),
			(cr2.z) - (y4));
	return (xy);
}
