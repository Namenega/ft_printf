/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:27:56 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/25 11:58:07 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minus0_zero1(t_flag flag, int n, int j)
{
	int		i;

	i = -1;
	if ((flag.prec == -1) ||
		(flag.width > ft_len(n) && flag.prec >= ft_len(n)))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	if (flag.prec != -1 && flag.prec < ft_len(n))
	{
		ft_space(flag, ft_len(n), 0);
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	}
	else if ((n < 0 && flag.prec == -1 && flag.zero == 0) ||
		(n >= 0 && flag.prec != -1))
		ft_space(flag, j, 0);
	else if (flag.width > flag.prec && flag.prec != -1)
		ft_space(flag, j, 1);
}

static void	ft_minus0_zero0(t_flag flag, int n, int j)
{
	int		i;

	i = -1;
	if ((flag.prec == -1) ||
		(flag.width > ft_len(n) && flag.prec >= ft_len(n)))
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	if (flag.prec < ft_len(n) && flag.prec != -1)
	{
		ft_space(flag, ft_len(n), 0);
		ft_putnbr(n, flag.prec, ft_len(n), flag);
	}
	else if ((n < 0 && flag.prec == -1) || n >= 0)
		ft_space(flag, j, 0);
	else
		ft_space(flag, j, 1);
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
		ft_space(flag, len, 0);
	}
	else if ((n < 0 && flag.prec == -1) || n >= 0)
		ft_space(flag, j, 0);
	else
		ft_space(flag, j, 1);
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
		ft_space(flag, 1, 0);
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
