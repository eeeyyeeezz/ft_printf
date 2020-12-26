/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manage_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:59:44 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/25 22:05:24 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			mg_int_zero_flag_width_precision(int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (precision > ft_strlen_minus(num) && num < 0 && s_struct->flag == '0')
		width -= 1;
	if (precision > ft_strlen_atoi(num) && s_struct->flag == '0')
	{
		while (width-- > precision)
			ft_putchar(' ', s_struct);
		s_struct->flag = 'A';
	}
	while (width-- > ft_strlen_atoi(num) && s_struct->flag == '0')
		ft_putchar(' ', s_struct);
	if (num < 0 && num != -2147483648)
	{
		ft_putchar('-', s_struct);
		num *= -1;
		width -= 1;
	}
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0', s_struct);
	ft_putnbr(num, s_struct);
	s_struct->flag = 'Z';
}

void			mg_int_min_flag_width_precision(int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (num < 0 && num != -2147483648)
	{
		ft_putchar('-', s_struct);
		num *= -1;
		width -= 1;
	}
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0', s_struct);
	ft_putnbr(num, s_struct);
	if (true_precision > ft_strlen_atoi(num))
		while (width-- - true_precision > 0)
			ft_putchar(' ', s_struct);
	while (width-- - ft_strlen_atoi(num) > 0 &&
	true_precision <= ft_strlen_atoi(num))
		ft_putchar(' ', s_struct);
	s_struct->flag = 'Z';
}

void			mg_int_width_plus_precision_flags(int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		mg_int_zero_flag_width_precision(num, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		mg_int_min_flag_width_precision(num, width, precision, s_struct);
}

void			mg_int_width_plus_precision(int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > precision && precision > 0 && s_struct->flag == '!')
	{
		if (precision > ft_strlen_minus(num) && num < 0)
			width -= 1;
		if (precision > ft_strlen_atoi(num))
		{
			while (width-- > precision)
				ft_putchar(' ', s_struct);
			s_struct->flag = 'A';
		}
		while (width-- > ft_strlen_atoi(num) && s_struct->flag != 'A')
			ft_putchar(' ', s_struct);
		if (num < 0 && num != -2147483648)
		{
			num *= -1;
			ft_putchar('-', s_struct);
		}
		while (true_precision-- > ft_strlen_atoi(num))
			ft_putchar('0', s_struct);
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}
