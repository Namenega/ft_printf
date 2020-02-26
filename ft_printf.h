/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:59:19 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/24 16:35:43 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_flag
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		preca;
	int		i;
	int		length;
}				t_flag;

int				ft_printf(const char *s, ...);
int				ft_isdigit(char c);
int				ft_len(long int n);
int				ft_hex(unsigned long int n);

void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putstrn(char *s, int n);
void			ft_putnbr(long long n, int p, int len, t_flag flag);
void			ft_space(t_flag flag, int n, int m);
void			ft_putnbrbase
				(unsigned long n, char *base, int len, t_flag flag);

t_flag			ft_check_width_prec(t_flag flag);
t_flag			ft_percent(t_flag flag);
t_flag			ft_char(t_flag flag, va_list ap);
t_flag			ft_string(t_flag flag, va_list ap);
t_flag			ft_int(t_flag flag, va_list ap);
t_flag			ft_unsignedint(t_flag flag, va_list ap);
t_flag			ft_hexa(t_flag flag, va_list ap, char c);
t_flag			ft_pointer(t_flag flag, va_list ap);

#endif
