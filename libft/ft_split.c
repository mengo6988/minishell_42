/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:03:46 by mho               #+#    #+#             */
/*   Updated: 2023/10/25 10:52:34 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*ft_wordup(char const *s, size_t start, size_t end)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (0);
	while (start < end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_skip_char(char const *s, char c, size_t i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_count_letters(char const *s, char c, size_t i, size_t j)
{
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		i = ft_skip_char(s, c, i);
		if (s[i] == '\0')
			break ;
		j = ft_count_letters(s, c, i, 0);
		if (j > 0)
			res[index++] = ft_wordup(s, i, (i + j));
		i += j;
	}
	res[index] = NULL;
	return (res);
}
