/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:50:16 by mrudzik           #+#    #+#             */
/*   Updated: 2018/09/17 18:40:51 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_head.h"

void			ft_intdel(int **del)
{
	if (del)
	{
		free(*del);
		*del = NULL;
	}
}

static int		ft_ender(char const *s, size_t end, char del)
{
	while (s[end] != '\0' && s[end] != del)
		end++;
	return (end);
}

static size_t	ft_word_count(char const *s, char del)
{
	int	words;
	int end;

	end = -1;
	words = 0;
	while (s[++end] != '\0')
	{
		if (s[end] != del && (s[end + 1] == del || s[end + 1] == '\0'))
			words++;
	}
	return (words);
}

int				*ft_intsplit(char const *s, char c)
{
	size_t	index;
	size_t	start;
	size_t	end;
	int		*res;
	int		word;

	index = -1;
	word = 1;
	if (!s)
		return (NULL);
	if ((res = (int*)malloc((ft_word_count(s, c) + 1)
				* sizeof(int))) == NULL)
		return (NULL);
	while (s[++index] != '\0')
	{
		if (s[index] != c)
		{
			start = index;
			end = ft_ender(s, index, c);
			res[word++] = ft_atoi(&s[start]);
			index = end - 1;
		}
	}
	res[0] = word - 1;
	return (res);
}
