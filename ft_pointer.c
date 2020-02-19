/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:19:22 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/19 15:42:44 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_pointer(t_flag flag, va_list ap)
{
	int					i;
	unsigned long int	n;
	char				*base;

	i = -1;
	base = "0123456789abcdef";
	n = va_arg(ap, long);
	if (n == 0 && flag.prec == 0)
	{
		ft_putstr("0x");
		flag.length += 2;
		return (flag);
	}
	if (flag.width - 1 < ft_hex(n))
	{
		ft_putstr("0x");
		ft_putnbrbase(n, base, ft_hex(n), flag);
	}
	if (flag.width > ft_hex(n) && flag.minus == 0)
	{
		while (++i < flag.width - ft_hex(n) - 2)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_putnbrbase(n, base, ft_hex(n), flag);
	}
	else if (flag.minus == 1 && flag.width > ft_hex(n))
	{
		ft_putstr("0x");
		ft_putnbrbase(n, base, ft_hex(n), flag);
		while (++i < flag.width - ft_hex(n) - 2)
			ft_putchar(' ');
	}
	flag.length += (flag.width > ft_hex(n)) ? flag.width : ft_hex(n) + 2;
	flag.length += (flag.width == ft_hex(n) + 1) ? 1 : 0;
	return (flag);
}
