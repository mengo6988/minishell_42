/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:42:42 by mho               #+#    #+#             */
/*   Updated: 2023/10/25 10:51:18 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int s)
{
	int		len;
	long	n;

	n = s;
	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	size_t	i;
	long	l;

	l = (long)n;
	len = ft_numlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = len;
	if (l < 0)
	{
		res[0] = '-';
		l = -l;
	}
	else if (l == 0)
		res[0] = '0';
	res[i] = '\0';
	while (l > 0)
	{
		res[--i] = (l % 10) + '0';
		l /= 10;
	}
	return (res);
}
