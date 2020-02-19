/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:18:07 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/19 15:50:48 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_minus0_zero1(t_flag flag, unsigned int n, int j)
{
	int		i;

	i = -1;
	if (flag.prec < ft_len(n) && flag.prec != -1)
	{
		while (++i < flag.width - ft_len(n))
			ft_putchar(' ');
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	}
	else if (flag.prec != -1)
		while (++i < flag.width - j)
			ft_putchar(' ');
	else if (flag.width > flag.prec && flag.prec != -1)
		while (++i < flag.width - j - 1)
			ft_putchar(' ');
	if ((flag.prec == -1) ||
		(flag.width >= ft_len(n) && flag.prec >= ft_len(n)))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
}

static void		ft_minus0_zero0(t_flag flag, unsigned int n, int j)
{
	int		i;

	i = -1;
	if (flag.prec < ft_len(n) && flag.prec != -1)
	{
		while (++i < flag.width - ft_len(n))
			ft_putchar(' ');
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	}
	else
		while (++i < flag.width - j)
			ft_putchar(' ');
	if ((flag.prec == -1) ||
		(flag.width >= ft_len(n) && flag.prec >= ft_len(n)))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
}

static void		ft_minus1(t_flag flag, int len, unsigned int n, int j)
{
	int		i;

	i = -1;
	if (flag.prec == -1 ||
		(flag.width >= len && flag.prec >= len))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	if (flag.prec < len && flag.prec != -1)
	{
		ft_putnbr(n, flag.prec, ft_len(n), flag);
		while (++i < flag.width - len)
			ft_putchar(' ');
	}
	else
		while (++i < flag.width - j)
			ft_putchar(' ');
}

t_flag			ft_unsignedint(t_flag flag, va_list ap)
{
	int				i;
	int				j;
	unsigned int	n;

	i = -1;
	n = va_arg(ap, unsigned int);
	j = (flag.prec >= ft_len(n)) ? flag.prec : ft_len(n);
	if (n == 0 && flag.prec == 0)
	{
		while (++i < flag.width)
			ft_putchar(' ');
		flag.length += flag.width;
		return (flag);
	}
	if (flag.minus == 1)
		ft_minus1(flag, ft_len(n), n, j);
	if (flag.minus == 0 && flag.zero == 0)
		ft_minus0_zero0(flag, n, j);
	if (flag.minus == 0 && flag.zero == 1)
		ft_minus0_zero1(flag, n, j);
	if (flag.prec >= ft_len(n) && flag.width < ft_len (n))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	flag.length += (j > flag.width) ? j : flag.width;
	return (flag);
}