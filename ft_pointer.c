/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:19:22 by Nathan            #+#    #+#             */
/*   Updated: 2020/03/05 13:52:04 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norminetted(t_flag *flag, char *base, unsigned long int n)
{
	if (flag->width - 1 < ft_hex(n))
	{
		ft_putstr("0x");
		ft_putnbrbase(n, base, ft_hex(n), *flag);
	}
}

static void	ft_norminetted2(t_flag *flag, unsigned long int n, char *base)
{
	if (flag->minus == 0 && flag->width > ft_hex(n))
	{
		ft_space(*flag, ft_hex(n), 2);
		ft_putstr("0x");
		ft_putnbrbase(n, base, ft_hex(n), *flag);
	}
	else if (flag->minus == 1 && flag->width > ft_hex(n))
	{
		ft_putstr("0x");
		ft_putnbrbase(n, base, ft_hex(n), *flag);
		ft_space(*flag, ft_hex(n), 2);
	}
}

t_flag		ft_pointer(t_flag flag, va_list ap)
{
	int					i;
	unsigned long int	n;

	i = -1;
	n = va_arg(ap, long);
	if (n == 0 && flag.prec == 0 && flag.minus == 1)
	{
		ft_putstr("0x");
		ft_space(flag, 2, 0);
		flag.length += (flag.width > 2) ? flag.width : 2;
		return (flag);
	}
	else if (n == 0 && flag.prec == 0 && flag.minus == 0)
	{
		ft_space(flag, 2, 0);
		ft_putstr("0x");
		flag.length += (flag.width > 2) ? flag.width : 2;
		return (flag);
	}
	ft_norminetted(&flag, BASE, n);
	ft_norminetted2(&flag, n, BASE);
	flag.length += (flag.width > ft_hex(n)) ? flag.width : ft_hex(n) + 2;
	flag.length += (flag.width == ft_hex(n) + 1) ? 1 : 0;
	return (flag);
}
