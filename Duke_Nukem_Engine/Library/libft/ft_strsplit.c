/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:27:54 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 14:52:28 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

char			**ft_strsplit(char const *s, char c)
{
	size_t	index;
	size_t	start;
	size_t	end;
	char	**res;
	int		word;

	index = -1;
	word = 0;
	if (!s)
		return (NULL);
	if ((res = (char**)malloc((ft_word_count(s, c) + 1)
				* sizeof(char*))) == NULL)
		return (NULL);
	while (s[++index] != '\0')
	{
		if (s[index] != c)
		{
			start = index;
			end = ft_ender(s, index, c);
			res[word++] = ft_strsub(s, start, end - start);
			index = end - 1;
		}
	}
	res[word] = NULL;
	return (res);
}
