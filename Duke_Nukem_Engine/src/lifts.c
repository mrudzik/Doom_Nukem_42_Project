/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:31:43 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 16:11:57 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	check_lifts(t_main_data *main, unsigned int i)
{
	while (i < DR.num_sectors)
	{
		if (SD[i].lift == LIFT_RAISING)
		{
			SD[i].floor += LIFT_SPEED;
			if (SD[i].floor >= SD[i].ceil - 20)
			{
				SD[i].floor = SD[i].ceil - 20;
				SD[i].lift = LIFT_UP;
				GM.lifts_pending--;
			}
		}
		else if (SD[i].lift == LIFT_FALLING)
		{
			SD[i].floor -= LIFT_SPEED;
			if (SD[i].floor <= SD[i].start_floor)
			{
				SD[i].floor = SD[i].start_floor;
				SD[i].lift = LIFT_DOWN;
				GM.lifts_pending--;
			}
		}
		i++;
	}
}

void	interact_lifts(t_main_data *main)
{
	if (PD.inventory.green_key == 1)
		if (SD[PD.sector].lift > 0)
		{
			if (SD[PD.sector].lift == LIFT_DOWN)
			{
				SD[PD.sector].lift = LIFT_RAISING;
				GM.lifts_pending++;
			}
			else if (SD[PD.sector].lift == LIFT_UP)
			{
				SD[PD.sector].lift = LIFT_FALLING;
				GM.lifts_pending++;
			}
		}
}
