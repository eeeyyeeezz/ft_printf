/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manage_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:15:30 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/25 17:11:44 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			mg_hex_width_plus_precision(long num, int width,
int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > precision && precision > 0 && s_struct->flag == '!')
	{
		if (precision > malloc_count(num) && num < 0)
			width -= 1;
		if (precision > malloc_count(num))
		{
			while (width-- > precision)
				ft_putchar(' ', s_struct);
			s_struct->flag = 'A';
		}
		while (width-- > malloc_count(num) && s_struct->flag != 'A')
			ft_putchar(' ', s_struct);
		if (num < 0)
		{
			num *= -1;
			ft_putchar('-', s_struct);
		}
		while (true_precision-- > malloc_count(num))
			ft_putchar('0', s_struct);
		ft_puthex(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void			mg_hex_width_minus(long num, int width,
int precision, t_arg *s_struct)
{
	if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
		width += 1;
	if (width > malloc_count(num) && width > precision && s_struct->flag == '-')
	{
		ft_puthex(num, s_struct);
		while (width - malloc_count(num))
		{
			ft_putchar(' ', s_struct);
			width--;
		}
		s_struct->flag = 'Z';
	}
}

void			mg_hex_zero(long num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > malloc_count(num) && width != precision &&
	width > precision && s_struct->flag == '0')
	{
		if (num < 0 && s_struct->flag == '0')
		{
			ft_putchar('-', s_struct);
			width -= 1;
			num *= -1;
		}
		while (width - malloc_count(num) > 0)
		{
			ft_putchar('0', s_struct);
			width--;
		}
		ft_puthex(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void			mg_hex_width(long num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > malloc_count(num) &&
	width > precision && s_struct->flag != 'Z')
	{
		if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
		while (width - malloc_count(num) && s_struct->flag != '0')
		{
			ft_putchar(' ', s_struct);
			width--;
		}
		ft_puthex(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((width == malloc_count(num) &&
	width < malloc_count(num)) && s_struct->flag != 'Z')
	{
		ft_puthex(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void			mg_hex_precesion(long num, int precision, t_arg *s_struct)
{
	int width;

	width = s_struct->width;
	if ((precision > malloc_count(num) &&
	width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') ||
	(s_struct->flag == '-' && width == 0))
	{
		if (num < 0)
		{
			ft_putchar('-', s_struct);
			num *= -1;
		}
		while (precision-- - malloc_count(num) > 0)
			ft_putchar('0', s_struct);
		ft_puthex(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((precision == malloc_count(num) ||
	precision < malloc_count(num)) && s_struct->flag != 'Z')
	{
		ft_puthex(num, s_struct);
		s_struct->flag = 'Z';
	}
}
