/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:05:05 by mho               #+#    #+#             */
/*   Updated: 2023/11/10 16:08:02 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uintlen(unsigned int n, int base, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (flags->dot && flags->precision == 0)
			return (0);
		return (1);
	}
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

int	ft_putui(unsigned int n, t_flags *flags)
{
	int	len;

	len = 0;
	ft_putui_fd(n, 1, flags);
	len = ft_uintlen(n, 10, flags);
	return (len);
}

void	ft_putui_fd(unsigned int nb, int fd, t_flags *flags)
{
	if (nb == 0)
	{
		if (flags->dot && flags->precision == 0)
			return ;
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd);
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
}

int	ft_print_u(t_flags *flags, unsigned int n)
{
	int				len;
	int				int_len;

	int_len = ft_uintlen(n, 10, flags);
	if (flags->dot)
	{
		if (flags->precision <= int_len)
			flags->width = flags->width - int_len;
		if (flags->precision > int_len)
			flags->width = flags->width - flags->precision;
	}
	else if (flags->width)
		flags->width = flags->width - int_len;
	len = 0;
	if (flags->width || flags->precision)
		len += ft_print_uu(flags, n, len, int_len);
	else
		len += ft_putui(n, flags);
	return (len);
}

int	ft_print_uu(t_flags *flags, unsigned int n, int len, int intlen)
{
	if (flags->left)
	{
		len += ft_print_width(flags->precision - intlen, '0');
		len += ft_putui(n, flags);
		len += ft_print_width(flags->width, ' ');
	}
	else
	{
		if (flags->zero)
			len += ft_print_width(flags->width, '0');
		else
			len += ft_print_width(flags->width, ' ');
		len += ft_print_width(flags->precision - intlen, '0');
		len += ft_putui(n, flags);
	}
	return (len);
}
