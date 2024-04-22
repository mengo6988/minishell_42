/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:11:31 by mho               #+#    #+#             */
/*   Updated: 2023/11/10 16:08:03 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_width(int width, char c)
{
	int	len;

	len = 0;
	if (width <= 0)
		return (0);
	while (width > 0)
	{
		len += ft_putchar(c);
		width--;
	}
	return (len);
}

int	ft_print_char(t_flags *flags, int c)
{
	int	len;

	len = 0;
	if (flags->width)
	{
		if (flags->left)
		{
			len += ft_putchar(c);
			len += ft_print_width((flags->width - 1), ' ');
		}
		else
		{
			len += ft_print_width((flags->width - 1), ' ');
			len += ft_putchar(c);
		}
	}
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_putstr(char *s, t_flags *flags)
{
	if (flags->dot)
	{
		write(1, s, flags->precision);
		return (flags->precision);
	}
	else
	{
		ft_putstr_fd(s, 1);
		return ((int)ft_strlen(s));
	}
}

int	ft_print_str(t_flags *flags, char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flags->dot)
	{
		if (flags->precision > (int)ft_strlen(str))
			flags->precision = (int)ft_strlen(str);
	}
	else
		flags->precision = (int)ft_strlen(str);
	if (flags->left)
	{
		len += ft_putstr(str, flags);
		len += ft_print_width((flags->width - flags->precision), ' ');
	}
	else
	{
		len += ft_print_width((flags->width - flags->precision), ' ');
		len += ft_putstr(str, flags);
	}
	return (len);
}
