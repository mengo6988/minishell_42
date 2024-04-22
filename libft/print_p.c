/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:23:23 by mho               #+#    #+#             */
/*   Updated: 2023/11/10 16:08:04 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ulonglen(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_putp_base(unsigned long long n, char *base)
{
	if (n >= 16)
		ft_putp_base(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}

int	ft_putp(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		ft_putstr_fd(PTR_NULL, 1);
		return (ft_strlen(PTR_NULL));
	}
	ft_putstr_fd("0x", 1);
	ft_putp_base(n, "0123456789abcdef");
	len = ft_ulonglen(n) + 2;
	return (len);
}

int	ft_putstr_custom(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

int	ft_print_p(t_flags *flags, unsigned long long n)
{
	int						len;
	int						int_len;

	len = 0;
	int_len = ft_ulonglen(n);
	if (flags->width)
	{
		if (flags->left)
		{
			len += ft_putp(n);
			len += ft_print_width(flags->width - int_len - 2, ' ');
		}
		else
		{
			len += ft_print_width(flags->width - int_len - 2, ' ');
			len += ft_putp(n);
		}
	}
	else
		len += ft_putp(n);
	return (len);
}

//width and left flag only
