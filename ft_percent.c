/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:02:37 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/19 17:19:32 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_percent(t_flag flag)
{
	int		i;

	i = -1;
	if (flag.width <= 1)
		ft_putchar('%');
	if (flag.minus == 1 && flag.width > 1)
	{
		ft_putchar('%');
		while (++i < flag.width - 1)
			flag.zero == 1 ? ft_putchar('0') : ft_putchar(' ');
	}
	else if (flag.minus == 0 && flag.width > 1)
	{
		while (++i < flag.width - 1)
			flag.zero == '1' ? ft_putchar('0') : ft_putchar(' ');
		ft_putchar('%');
	}
	flag.length += flag.width == 0 ? 1 : flag.width;
	return (flag);
}
