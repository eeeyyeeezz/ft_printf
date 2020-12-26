/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_manage_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:44:53 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/25 17:17:28 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			mg_uns_zero_flag_width_precision(unsigned int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (precision > ft_strlen_atoi(num) && s_struct->flag == '0')
	{
		while (width-- > precision)
			ft_putchar(' ', s_struct);
		s_struct->flag = 'A';
	}
	while (width-- > ft_strlen_atoi(num) && s_struct->flag == '0')
		ft_putchar(' ', s_struct);
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0', s_struct);
	ft_putuns(num, s_struct);
	s_struct->flag = 'Z';
}

void			mg_uns_min_flag_width_precision(unsigned int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	while (precision-- > ft_strlen_atoi(num))
		ft_putchar('0', s_struct);
	ft_putuns(num, s_struct);
	if (true_precision > ft_strlen_atoi(num))
		while (width-- - true_precision > 0)
			ft_putchar(' ', s_struct);
	while (width-- - ft_strlen_atoi(num) > 0 &&
	true_precision < ft_strlen_atoi(num))
		ft_putchar(' ', s_struct);
	s_struct->flag = 'Z';
}

void			mg_uns_width_plus_precision_flags(unsigned int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		mg_int_zero_flag_width_precision(num, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		mg_int_min_flag_width_precision(num, width, precision, s_struct);
}

void			mg_uns_width_plus_precision(unsigned int num, int width,
				int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > precision && precision > 0 && s_struct->flag == '!')
	{
		if (precision > ft_strlen_atoi(num))
		{
			while (width-- > precision)
				ft_putchar(' ', s_struct);
			s_struct->flag = 'A';
		}
		while (width-- > ft_strlen_atoi(num) && s_struct->flag != 'A')
			ft_putchar(' ', s_struct);
		while (true_precision-- > ft_strlen_atoi(num))
			ft_putchar('0', s_struct);
		ft_putuns(num, s_struct);
		s_struct->flag = 'Z';
	}
}
