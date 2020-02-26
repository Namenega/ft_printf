/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:18:54 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/24 16:36:39 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_char(t_flag flag, va_list ap)
{
	int		i;

	i = -1;
	if (flag.width == 1)
		ft_putchar(va_arg(ap, int));
	if (flag.minus == 1 && flag.width != 1)
	{
		ft_putchar(va_arg(ap, int));
		ft_space(flag, 1, 0);
	}
	else if (flag.minus == 0 && flag.width != 1)
	{
		ft_space(flag, 1, 0);
		ft_putchar(va_arg(ap, int));
	}
	flag.length += flag.width == 0 ? 1 : flag.width;
	return (flag);
}
