/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:34:45 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/19 14:17:04 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_l(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static t_flag	ft_stringlength(t_flags flag, char *s)
{
	if (flag.prec == -1 && flag.width > 0 && s)
		flag.length += flag.width > ft_l(s) ? flag.width : ft_l(s);
	if (flag.width == 0 && flag.prec != -1 && s)
		flag.length += flag.prec > ft_l(s) ? ft_l(s) : flag.prec;
	if (flag.prec != -1 && flag.width > 0 && s)
	{
		if (flag.prec > flag.width && flag.prec >= ft_l(s))
			flag.length += flag.width < ft_l(s) ? ft_l(s) : flag.width;
		else if (flag.prec > flag.width && flag.prec < ft_l(s))
			flag.length += flag.width < ft_l(s) ? flag.prec : flag.width;
		else
			flag.length += flag.width;
	}
	if (flag.width == 0 && flag.prec == -1 && s)
		flag.length += ft_l(s);
	if (!s)
		flag.length += flag.width;
	return (flag);
}

static void		ft_minus0(t_flag flag, char *s)
{
	int		i;

	i = -1;
	if (flag.prec < ft_l(s) && flag.prec != -1)
	{
		while (++i < flag.width - flag.prec)
			ft_putchar(' ');
		ft_putstrn(s, flag.prec);
	}
	else
	{
		while (++i < flag.width - ft_l(s))
			ft_putchar(' ');
	}
	if ((flag.prec == -1) ||
		(flag.width > ft_l(s) && flag.prec >= ft_l(s)))
		ft_putstr(s);
}

static void		ft_minus1(t_flag flag, char *s)
{
	int		i;

	i = -1;
	if (flag.prec == -1 ||
		(flag.width > ft_l(s) && flag.prec >= ft_l(s)))
		ft_putstr(s);
	if (flag.prec < ft_l(s) && flag.prec != -1)
	{
		ft_putstrn(s, flag.prec);
		while (++i < flag.width - flag.prec)
			ft_putchar(' ');
	}
	else
	{
		while (++i < flag.width - ft_l(s))
			ft_putchar(' ');
	}
}

t_flag			ft_string(t_flag flag, va_list ap)
{
	char	*str;

	str = va_arg(ap, void *)
	if (!str)
		str = "(null)";
	if (flag.minus == 1 && str)
		ft_minus1(flag, str);
	if (flag.minus == 0 && str)
		ft_minus0(flag, str);
	if (flag.prec >= ft_l(str) && flag.width <= ft_l(str))
		ft_putstr(str);
	flag = ft_stringlength(flag, str);
	return (flag);
}