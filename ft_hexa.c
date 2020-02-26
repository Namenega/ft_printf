/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:57:54 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/26 14:46:03 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minus1(t_flag flag, long n, int j, char *base)
{
	int		i;

	i = -1;
	if (flag.prec == -1 ||
		(flag.width >= ft_hex(n) && flag.prec >= ft_hex(n)))
		ft_putnbrbase(n, base, ft_hex(n), flag);
	if (flag.prec < ft_hex(n) && flag.prec != -1)
	{
		ft_putnbrbase(n, base, ft_hex(n), flag);
		ft_space(flag, ft_hex(n), 0);
	}
	else
		ft_space(flag, j, 0);
}

static void	ft_minus0_zero0(t_flag flag, long n, int j, char *base)
{
	int		i;

	i = -1;
	if (flag.prec == -1 ||
		(flag.width >= ft_hex(n) && flag.prec >= ft_hex(n)))
		ft_putnbrbase(n, base, ft_hex(n), flag);
	if (flag.prec < ft_hex(n) && flag.prec != -1)
	{
		ft_space(flag, ft_hex(n), 0);
		ft_putnbrbase(n, base, ft_hex(n), flag);
	}
	else
		ft_space(flag, j, 0);
}

static void	ft_minus0_zero1(t_flag flag, long n, int j, char *base)
{
	int		i;

	i = -1;
	if (flag.prec == -1 ||
		(flag.width >= ft_hex(n) && flag.prec >= ft_hex(n)))
		ft_putnbrbase(n, base, ft_hex(n), flag);
	if (flag.prec < ft_hex(n) && flag.prec != -1)
	{
		ft_space(flag, ft_hex(n), 0);
		ft_putnbrbase(n, base, ft_hex(n), flag);
	}
	else if (flag.prec != -1)
		ft_space(flag, j, 0);
	else if (flag.width > flag.prec && flag.prec != -1)
		ft_space(flag, j, 1);
}

t_flag		ft_hexa(t_flag flag, va_list ap, char c)
{
	long	n;
	int		j;
	char	*base;

	base = (c == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	n = va_arg(ap, unsigned int);
	j = (flag.prec >= ft_hex(n)) ? flag.prec : ft_hex(n);
	if (n == 0 && flag.prec == 0)
	{
		ft_space(flag, 0, 0);
		flag.length += flag.width;
		return (flag);
	}
	if (flag.minus == 1)
		ft_minus1(flag, n, j, base);
	if (flag.minus == 0 && flag.zero == 0)
		ft_minus0_zero0(flag, n, j, base);
	if (flag.minus == 0 && flag.prec == 1)
		ft_minus0_zero1(flag, n, j, base);
	if (flag.prec >= ft_hex(n) && flag.width < ft_hex(n))
		ft_putnbrbase(n, base, ft_hex(n), flag);
	flag.length += (j > flag.width) ? j : flag.width;
	return (flag);
}
