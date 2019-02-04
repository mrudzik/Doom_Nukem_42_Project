/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syst_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:06:43 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 20:35:42 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	unload_data(t_main_data *main)
{
	unsigned int a;

	a = -1;
	while (++a < DR.num_sectors)
		free(SD[a].vertex);
	a = -1;
	while (++a < DR.num_sectors)
		free(SD[a].neighbors);
	free(SD);
	SD = NULL;
	DR.num_sectors = 0;
}

void	prog_quit(int flag, t_main_data *main)
{
	system("leaks doom-nukem");
	if (flag == 1)
		unload_data(main);
	sdl_quit(main, 1);
}
