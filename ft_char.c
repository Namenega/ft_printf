/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:18:54 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/18 16:27:18 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

t_flag		ft_char(t_flag flag, va_list ap)
{
	int		i;

	i = -1;
	if (flag.width == 1)
		ft_putchar(va_arg(ap, int));
	if (flag.minus == 1 && flag.width != 1)
	{
		ft_putchar(va_arg(ap, int));
		while (++i < flag.width - 1)
			ft_putchar(' ');
	}
	else if (flag.minus == 0 && flag.width != 1)
	{
		while (++i < flag.width - 1)
			ft_putchar(' ');
		ft_putchar(va_arg(ap, int));
	}
	flag.length += flag.width == 0 ? 1 : flag.width;
	return (flag);
}
