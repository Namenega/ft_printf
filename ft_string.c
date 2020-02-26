/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:34:45 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/24 16:39:03 by namenega         ###   ########.fr       */
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

static t_flag	ft_stringlength(t_flag flag, char *s)
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
		ft_space(flag, flag.prec, 0);
		ft_putstrn(s, flag.prec);
	}
	else
		ft_space(flag, ft_l(s), 0);
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
		ft_space(flag, flag.prec, 0);
	}
	else
		ft_space(flag, ft_l(s), 0);
}

t_flag			ft_string(t_flag flag, va_list ap)
{
	char	*s;

	s = va_arg(ap, void *);
	if (!s)
		s = "(null)";
	if (flag.minus == 1 && s)
		ft_minus1(flag, s);
	if (flag.minus == 0 && s)
		ft_minus0(flag, s);
	if (flag.prec >= ft_l(s) && flag.width <= ft_l(s))
		ft_putstr(s);
	flag = ft_stringlength(flag, s);
	return (flag);
}
