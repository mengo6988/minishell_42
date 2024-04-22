/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:20:23 by mho               #+#    #+#             */
/*   Updated: 2023/10/25 10:53:20 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			p = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		p = (char *)s;
	return (p);
}

/*

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = ft_strlen(s) + 1;
	p = (char *)s + i;
	while (*p != *s && *p != (unsigned char)c)
	{
		if (*p == (unsigned char)c)
			return (p);
		p--;
	}
	if (*p == (unsigned char)c)
		return (p);
	return (NULL);
}
*/
