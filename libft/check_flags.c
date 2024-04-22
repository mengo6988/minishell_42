/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:32:59 by mho               #+#    #+#             */
/*   Updated: 2023/10/31 12:27:18 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_flags(t_flags *flags)
{
	flags->left = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->caps = 0;
	flags->dot = 0;
}

int	is_format(char s)
{
	char	*formats;
	int		i;

	i = -1;
	formats = "cspdiuxX%";
	while (formats[++i])
	{
		if (s == formats[i])
			return (1);
	}
	return (0);
}

int	is_flags(char s)
{
	char	*flags;
	int		i;

	i = -1;
	flags = "-0# +";
	while (flags[++i])
	{
		if (s == flags[i])
			return (1);
	}
	return (0);
}

void	ft_check_flags(const char *s, t_flags *flags, int *i)
{
	ft_init_flags(flags);
	while (s[*i] && is_flags(s[*i]))
	{
		if (s[*i] == '-')
			flags->left = 1;
		else if (s[*i] == '0')
			flags->zero = 1;
		else if (s[*i] == '#')
			flags->hash = 1;
		else if (s[*i] == ' ')
			flags->space = 1;
		else if (s[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
	ft_check_width_precision(s, flags, i);
}

void	ft_check_width_precision(const char *s, t_flags *flags, int *i)
{
	if (s[*i] >= '0' && s[*i] <= '9')
	{
		flags->width = ft_atoi(s + (*i));
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
	if (s[*i] == '.' && s[(*i)++])
	{
		flags->dot = 1;
		flags->zero = 0;
		if (s[*i] >= '0' && s[*i] <= '9')
			flags->precision = ft_atoi(s + (*i));
		while (!(is_format(s[*i])))
			(*i)++;
	}
}
