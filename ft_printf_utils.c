/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:14:06 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/19 15:49:18 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void 		ft_putstrn(char *s, int n)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0'&& i < n)
	{
		ft_putchar(s[i]);
		i++;
	}
}

int			ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
