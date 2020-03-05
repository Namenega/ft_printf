/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:04:33 by Nathan            #+#    #+#             */
/*   Updated: 2020/03/02 16:55:08 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_newatoi(char *s)
{
	int				i;
	unsigned long	res;

	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	if (res > LONG_MAX)
		return (0);
	return (res);
}

static t_flag	ft_flag_analyze(char *s, t_flag flag, va_list ap)
{
	while (s[++flag.i] == '-' || s[flag.i] == '0')
	{
		if (s[flag.i] == '-')
			flag.minus = 1;
		if (s[flag.i] == '0')
			flag.zero = 1;
	}
	if (flag.minus == 1)
		flag.zero = 0;
	flag.width = (s[flag.i] == '*') ? va_arg(ap, int) : ft_newatoi(s + flag.i);
	if (flag.width < 0)
		flag.minus = 1;
	while (ft_isdigit(s[flag.i]) || s[flag.i] == '*')
		flag.i++;
	if (s[flag.i] == '.')
		flag.prec = (s[flag.i + 1] == '*') ? va_arg(ap, int) :
			ft_newatoi(s + flag.i + 1);
	flag = ft_check_width_prec(flag);
	while (ft_isdigit(s[flag.i]) || s[flag.i] == '*' || s[flag.i] == '.')
		flag.i++;
	return (flag);
}

static t_flag	ft_analyzer(const char *s, t_flag flag, va_list ap)
{
	if (s[flag.i] == '%' && s[flag.i + 1])
		flag = ft_flag_analyze((char *)s, flag, ap);
	if (s[flag.i] == '%')
		flag = ft_percent(flag);
	if (s[flag.i] == 'c')
		flag = ft_char(flag, ap);
	if (s[flag.i] == 's')
		flag = ft_string(flag, ap);
	if (s[flag.i] == 'd' || s[flag.i] == 'i')
		flag = ft_int(flag, ap);
	if (s[flag.i] == 'u')
		flag = ft_unsignedint(flag, ap);
	if (s[flag.i] == 'x' || s[flag.i] == 'X')
		flag = ft_hexa(flag, ap, s[flag.i]);
	if (s[flag.i] == 'p')
		flag = ft_pointer(flag, ap);
	flag.minus = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.prec = -1;
	return (flag);
}

static t_flag	ft_initialize(void)
{
	t_flag	flag;

	flag.minus = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.prec = -1;
	flag.i = 0;
	flag.length = 0;
	return (flag);
}

int				ft_printf(const char *s, ...)
{
	t_flag	flag;
	va_list	ap;

	va_start(ap, s);
	flag = ft_initialize();
	while (s[flag.i])
	{
		while (s[flag.i] && s[flag.i] != '%')
		{
			ft_putchar(s[flag.i++]);
			flag.length++;
		}
		if (s[flag.i] == '%')
			flag = ft_analyzer(s, flag, ap);
		if (s[flag.i] == 0)
			break ;
		flag.i++;
	}
	va_end(ap);
	return (flag.length);
}
