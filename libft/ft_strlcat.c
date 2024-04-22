/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:49:36 by mho               #+#    #+#             */
/*   Updated: 2023/10/25 10:52:51 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	if (!len)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	j = dest_len;
	if (dest_len < (len - 1) && len > 0)
	{
		while (src[i] && (dest_len + i) < (len - 1))
			dest[j++] = src[i++];
		dest[j] = 0;
	}
	if (dest_len >= len)
		dest_len = len;
	return (src_len + dest_len);
}
