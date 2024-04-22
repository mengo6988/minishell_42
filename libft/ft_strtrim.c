/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:28:51 by mho               #+#    #+#             */
/*   Updated: 2023/10/25 10:53:25 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	if (s1[i] == '\0')
		return (ft_substr("", 0, 0));
	if (set[i] == '\0')
		return (ft_substr(s1, i, ft_strlen(s1)));
	while (s1[i] && ft_isset(set, s1[i]))
		i++;
	while (j >= i && ft_isset(set, s1[j]))
		j--;
	if (i > j)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, i, (j - i + 1)));
}
