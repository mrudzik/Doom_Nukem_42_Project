/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:13:24 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:20:15 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = (char*)malloc(size * sizeof(char) + 1)) == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
