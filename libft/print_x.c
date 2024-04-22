/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:59:46 by mho               #+#    #+#             */
/*   Updated: 2023/11/14 13:40:42 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned int n, int base, t_flags *flags)
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

int	ft_puthex(unsigned int n, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->dot && flags->precision == 0 && n == 0)
		return (0);
	if (flags->caps)
		ft_putnbr_base(n, "0123456789ABCDEF");
	else
		ft_putnbr_base(n, "0123456789abcdef");
	len = ft_hexlen(n, 16, flags);
	return (len);
}

void	ft_putnbr_base(unsigned int n, char *base)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}

int	ft_print_x(t_flags *flags, unsigned int n)
{
	int				len;
	int				hex_len;

	len = 0;
	hex_len = ft_hexlen(n, 16, flags);
	if (flags->dot)
	{
		if (flags->precision <= hex_len)
			flags->width = flags->width - hex_len;
		if (flags->precision > hex_len)
			flags->width = flags->width - flags->precision;
	}
	else if (flags->width)
		flags->width = flags->width - hex_len;
	if (flags->width || flags->precision || flags->zero)
	{
		if (flags->hash && flags->zero && !flags->precision)
			flags->width -= 2;
		len += ft_print_xx(flags, n, len, hex_len);
	}
	else
		len += ft_print_xx(flags, n, len, hex_len);
	return (len);
}

int	ft_print_xx(t_flags *flags, unsigned int n, int len, int hex_len)
{
	if (flags->left)
	{
		if (flags->hash && !flags->caps && n != 0)
			len += ft_putstr_custom("0x");
		else if (flags->hash && flags->caps && n != 0)
			len += ft_putstr_custom("0X");
		len += ft_print_width(flags->precision - hex_len, '0');
		len += ft_puthex(n, flags);
		len += ft_print_width(flags->width, ' ');
	}
	else if (!flags->left)
	{
		if (flags->zero)
			len += ft_print_width(flags->width, '0');
		else
			len += ft_print_width(flags->width, ' ');
		if (flags->caps && flags->hash && n != 0)
			len += ft_putstr_custom("0X");
		else if (flags->hash && !flags->caps && n != 0)
			len += ft_putstr_custom("0x");
		len += ft_print_width(flags->precision - hex_len, '0');
		len += ft_puthex(n, flags);
	}
	return (len);
}
// ONLY HASH AND 0 FLAG and MINUS
