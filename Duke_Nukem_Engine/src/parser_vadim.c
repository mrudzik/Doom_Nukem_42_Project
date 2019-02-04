/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vadim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:48:17 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/11 16:18:44 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void	ft_error1(char *str)
{
	ft_putstr(str);
	exit(1);
}

char	**open_read(t_data *data)
{
	char	*line;
	char	*str;
	char	**ret;

	str = NULL;
	line = NULL;
	if ((data->fd = open(data->name, O_RDONLY)) == -1)
		ft_error1("bad open\n");
	get_next_line(data->fd, &line);
	if (!line || ft_strlen(line) < 1)
		ft_error1("bad gnl\n");
	str = ft_strdup(line);
	while (line != NULL)
	{
		free(line);
		str = ft_joinfree(str, "\n", 3);
		get_next_line(data->fd, &line);
		if (line != NULL)
			str = ft_joinfree(str, line, 3);
	}
	close(data->fd);
	ret = ft_strsplit(str, '\n');
	free(str);
	return (ret);
}

void	parser(t_data *data, t_main_data *main)
{
	char	**reading;
	int		q;

	init_count(data);
	reading = open_read(data);
	count_all(data, reading);
	second_checking(data, reading);
	write_parsed_data(main, data, reading);
	parser_write_additional(main, data, reading);
	q = -1;
	while (reading[++q] != NULL)
		free(reading[q]);
	free(reading);
}
