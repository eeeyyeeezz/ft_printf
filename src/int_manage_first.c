/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manage_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:56:03 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/25 21:00:14 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void				mg_int_width_minus(int num, int width,
					int precision, t_arg *s_struct)
{
	if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
		width += 1;
	if (width > ft_strlen_atoi(num) &&
	width > precision && s_struct->flag == '-')
	{
		ft_putnbr(num, s_struct);
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ', s_struct);
			width--;
		}
		s_struct->flag = 'Z';
	}
}

void				mg_int_zero(int num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) && width != precision &&
	width > precision && s_struct->flag == '0')
	{
		if (num < 0 && num != -2147483648 && s_struct->flag == '0')
		{
			ft_putchar('-', s_struct);
			width -= 1;
			num *= -1;
		}
		while (width - ft_strlen_atoi(num) > 0)
		{
			ft_putchar('0', s_struct);
			width--;
		}
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void				mg_int_width(int num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) &&
	width > precision && s_struct->flag != 'Z')
	{
		if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
		while (width - ft_strlen_atoi(num) &&
		num != -2147483648 && s_struct->flag != '0')
		{
			ft_putchar(' ', s_struct);
			width--;
		}
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((width == ft_strlen_atoi(num) &&
	width < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void				mg_int_precesion(int num, int precision, t_arg *s)
{
	int width;

	width = s->width;
	if ((precision > ft_strlen_atoi(num) &&
	width < precision && s->flag == '!') ||
	(width == precision && s->flag == '!') || (s->flag == '-' && width == 0))
	{
		if (num < 0 && num != -2147483648)
		{
			ft_putchar('-', s);
			num *= -1;
		}
		while (precision-- - ft_strlen_atoi(num) > 0)
			ft_putchar('0', s);
		ft_putnbr(num, s);
		s->flag = 'Z';
	}
	else if ((precision == ft_strlen_atoi(num) ||
	precision < ft_strlen_atoi(num)) && s->flag != 'Z')
	{
		ft_putnbr(num, s);
		s->flag = 'Z';
	}
}
