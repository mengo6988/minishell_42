/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:14:13 by mho               #+#    #+#             */
/*   Updated: 2023/11/10 16:08:05 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n, int base, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (flags->plus || flags->space)
			return (2);
		if (flags->dot && flags->precision == 0)
			return (0);
		return (1);
	}
	if ((flags->plus && n > 0) || n < 0 || (flags->space && n >= 0))
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

void	ft_putnbr_id(int n, int fd, t_flags *flags)
{
	long	nb;

	nb = (long)n;
	if (nb == 0)
	{
		if (flags->dot && flags->precision == 0)
			return ;
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd);
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
}

int	ft_putnbr(int n, t_flags *flags)
{
	int	len;

	len = ft_intlen(n, 10, flags);
	if (flags->plus && n >= 0)
		ft_putchar_fd('+', 1);
	else if (flags->space && n >= 0 && !flags->plus)
		ft_putchar_fd(' ', 1);
	else if (n < 0)
	{
		flags->precision++;
		ft_putchar_fd('-', 1);
	}
	if (flags->zero && !flags->left)
		len += ft_print_width(flags->width, '0');
	if (flags->precision)
		len += ft_print_width(flags->precision - len, '0');
	ft_putnbr_id(n, 1, flags);
	return (len);
}

int	ft_print_i(t_flags *flags, int n)
{
	int	len;
	int	int_len;

	len = 0;
	int_len = ft_intlen(n, 10, flags);
	ft_print_ii(flags, n, int_len);
	if (flags->width)
	{
		if (flags->left)
		{
			len += ft_putnbr(n, flags);
			len += ft_print_width(flags->width, ' ');
		}
		else
		{
			if (!flags->zero)
				len += ft_print_width(flags->width, ' ');
			len += ft_putnbr(n, flags);
		}
	}
	else
		len += ft_putnbr(n, flags);
	return (len);
}

void	ft_print_ii(t_flags *flags, int n, int int_len)
{
	if (flags->dot)
	{
		if (n < 0)
		{
			if (flags->precision <= int_len - 1)
				flags->width = flags->width - int_len;
			if (flags->precision > int_len - 1)
				flags->width = flags->width - (flags->precision + 1);
		}
		else
		{
			if (flags->precision <= int_len)
				flags->width = flags->width - int_len;
			if (flags->precision > int_len)
				flags->width = flags->width - flags->precision;
		}
	}
	else if (flags->width)
		flags->width = flags->width - int_len;
}
