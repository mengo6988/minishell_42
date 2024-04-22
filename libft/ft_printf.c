/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:24:08 by mho               #+#    #+#             */
/*   Updated: 2023/11/10 16:08:06 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_format(char s, t_flags *flags, va_list *args)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_print_char(flags, va_arg(*args, int));
	else if (s == 's')
		len += ft_print_str(flags, va_arg(*args, char *));
	else if (s == 'p')
		len += ft_print_p(flags, va_arg(*args, unsigned long long));
	else if (s == 'd' || s == 'i')
		len += ft_print_i(flags, va_arg(*args, int));
	else if (s == 'u')
		len += ft_print_u(flags, va_arg(*args, unsigned int));
	else if (s == 'x' || s == 'X')
	{
		if (s == 'X')
			flags->caps = 1;
		len += ft_print_x(flags, va_arg(*args, unsigned int));
	}
	else if (s == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags	flags;
	int		len;
	int		i;

	len = 0;
	i = -1;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && ++i)
		{
			ft_init_flags(&flags);
			ft_check_flags(s, &flags, &i);
			len += ft_check_format(s[i], &flags, &args);
		}
		else
			len += ft_putchar(s[i]);
	}
	va_end(args);
	return (len);
}
