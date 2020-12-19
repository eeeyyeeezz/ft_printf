/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_manage_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:59:44 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 16:59:57 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			manage_int_zero_flag_width_precision(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (precision > ft_strlen_atoi(num) && num < 0 && s_struct->flag == '0')
		width -= 1;
	if (precision > ft_strlen_atoi(num) && s_struct->flag == '0')
	{
		while (width-- > precision)
			ft_putchar(' ');
		s_struct->flag = 'A';
	}
	while (width-- > ft_strlen_atoi(num) && s_struct->flag == '0')
		ft_putchar(' ');
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		width -= 1;
	}
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0');
	ft_putnbr(num, s_struct);
	s_struct->flag = 'Z';
}

void			manage_int_min_flag_width_precision(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		width -= 1;
	}
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0');
	ft_putnbr(num, s_struct);
	if (true_precision > ft_strlen_atoi(num))
		while (width-- - true_precision > 0)
			ft_putchar(' ');
	while (width-- - ft_strlen_atoi(num) > 0 && true_precision < ft_strlen_atoi(num))
		ft_putchar(' ');
	s_struct->flag = 'Z';
}

void			manage_int_width_plus_precision_flags(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		manage_int_zero_flag_width_precision(num, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		manage_int_min_flag_width_precision(num, width, precision, s_struct);
}

void			manage_int_width_plus_precision(int num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > precision && precision > 0 && s_struct->flag == '!')
	{
		if (precision > ft_strlen_atoi(num) && num < 0)
			width -= 1;
		if (precision > ft_strlen_atoi(num))
		{
			while (width-- > precision)
				ft_putchar(' ');
			s_struct->flag = 'A';
		}
		while (width-- > ft_strlen_atoi(num) && s_struct->flag != 'A')
			ft_putchar(' ');
		if (num < 0)
		{
			num *= -1;
			ft_putchar('-');
		}
		while (true_precision-- > ft_strlen_atoi(num))
			ft_putchar('0');
		ft_putnbr(num, s_struct);
		s_struct->flag = 'Z';
	}
}
