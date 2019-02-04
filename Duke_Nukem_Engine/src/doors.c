/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:51:07 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/08 15:48:07 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

static void		open_door_animation(t_main_data *main, int i)
{
	SD[i].ceil += DOOR_SPEED;
	if (SD[i].ceil >= SD[i].start_ceil)
	{
		SD[i].ceil = SD[i].start_ceil;
		SD[i].door = DOOR_OPENED;
		GM.doors_pending--;
	}
}

static void		close_door_animation(t_main_data *main, int i)
{
	SD[i].ceil -= DOOR_SPEED;
	if (SD[i].ceil <= SD[i].floor)
	{
		SD[i].ceil = SD[i].floor;
		SD[i].door = DOOR_CLOSED;
		GM.doors_pending--;
	}
}

void			check_doors(t_main_data *main)
{
	unsigned int i;

	i = -1;
	while (++i < DR.num_sectors)
	{
		if (SD[i].door == DOOR_CLOSING)
			close_door_animation(main, i);
		else if (SD[i].door == DOOR_OPENING)
			open_door_animation(main, i);
	}
}

void			interact_doors(t_main_data *main)
{
	unsigned int	i;
	int				sec_door;

	if (PD.inventory.red_key == 1)
	{
		i = 0;
		while (i < SD[PD.sector].npoints)
		{
			sec_door = SD[PD.sector].neighbors[i];
			if (SD[sec_door].door > 0)
			{
				if (SD[sec_door].door == DOOR_OPENED)
				{
					SD[sec_door].door = DOOR_CLOSING;
					GM.doors_pending++;
				}
				else if (SD[sec_door].door == DOOR_CLOSED)
				{
					SD[sec_door].door = DOOR_OPENING;
					GM.doors_pending++;
				}
			}
			i++;
		}
	}
}
