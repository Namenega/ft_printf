/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:27:56 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/19 15:47:17 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minus0_zero1(t_flag flag, int n, int j)
{
	int		i;

	i = -1;
	if (flag.prec != -1 && flag.prec < ft_len(n))
	{
		while (++i < flag.width - ft_len(n))
			ft_putchar(' ');
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	}
	else if ((n < 0 && flag.prec == -1 && flag.zero == 0) ||
		(n >= 0 && flag.prec != -1))
		while (++i < flag.width - j)
			ft_putchar(' ');
	else if (flag.width > flag.prec && flag.prec != -1)
		while (++i < flag.width - j - 1)
			ft_putchar(' ');
	if ((flag.prec == -1) ||
		(flag.width > ft_len(n) && flag.prec >= ft_len(n)))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
}

static void	ft_minus0_zero0(t_flag flag, int n, int j)
{
	int		i;

	i = -1;
	if (flag.prec < ft_len(n) && flag.prec != -1)
	{
		while (++i < flag.width - ft_len(n))
			ft_putchar(' ');
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	}
	else if ((n < 0 && flag.prec = -1) || n >= 0)
		while (++i < flag.width - j)
			ft_putchar(' ');
	else
		while (++i < flag.width - j - 1);
			ft_putchar(' ');
	if ((flag.prec == -1) ||
		(flag.width > ft_len(n) && flag.prec >= ft_len(n)))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
}

static void	ft_minus1(t_flag flag, int len, int n, int j)
{
	int		i;

	i = -1;
	if (flag.prec == -1 ||
		(flag.width > len && flag.prec >= len))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	if (flag.prec < len && flag.prec != -1)
	{
		ft_putnbr(n, flag.prec, ft_len(n), flag);
		while (++i < flag.width - len)
			ft_putchar(' ');
	}
	else if ((n < 0 && flag.prec == -1) || n >= 0)
		while (++i < flag.width - j)
			ft_putchar(' ');
	else
		while (++i < flag.width - j - 1)
			ft_putchar(' ');
}

int			ft_len(long int n)
{
	if (n > 9)
		return (ft_len(n / 10) + 1);
	if (n < 0)
		return (ft_len(n * (-1)) + 1);
	return (1);
}

t_flag		ft_int(t_flag flag, va_list ap)
{
	int		i;
	int		n;
	int		j;

	i = -1;
	n = va_arg(ap, int);
	j = (flag.prec >= ft_len(n)) ? flag.prec : ft_len(n);
	if (n == 0 && flag.prec == 0)
	{
		while (++i < flag.width -1)
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
	if (flag.prec >= ft_len(n) && flag.width <= ft_len(n))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	flag.length += (j > flag.width) ? j : flag.width;
	if (flag.prec >= flag.width && n < 0 && flag.prec >= ft_len(n))
		flag.length++;
	return (flag);
}