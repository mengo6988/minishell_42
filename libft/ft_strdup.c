/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:37:13 by mho               #+#    #+#             */
/*   Updated: 2023/10/25 10:52:41 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		dest[i] = s1[i];
	}
	dest[i] = '\0';
	return (dest);
}
