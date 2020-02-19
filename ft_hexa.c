/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:57:54 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/19 15:45:42 by Nathan           ###   ########.fr       */
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
		while (++i < flag.width - ft_hex(n))
			ft_putchar(' ');
	}
	else
		while (++i < flag.width - j)
			ft_putchar(' ');
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
		while (++i < flag.width - ft_hex(n))
			ft_putchar(' ');
		ft_putnbrbase(n, base, ft_hex(n), flag);
	}
	else
		while (++i < flag.width - j)
			ft_putchar(' ');
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
		while (++i < flag.width - ft_hex(n))
			ft_putchar(' ');
		ft_putnbrbase(n, base, ft_hex(n), flag);
	}
	else if (flag.prec != -1)
		while (++i < flag.width - j)
			ft_putchar(' ');
	else if (flag.width > flag.prec && flag.prec != -1)
		while (++i < flag.width - j - 1)
			ft_putchar(' ');
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
		ft_space(flag);
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
		ft_putnbr_base(n, base, ft_hex(n), flag);
	flag.length += (j > flag.width) ? j : flag.width;
	return (flag);
}
