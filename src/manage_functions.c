/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:56:49 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 19:35:44 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void				manage_hex(va_list argptr, t_arg *s_struct)
{
	long	hex;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	hex = va_arg(argptr, unsigned int);
	mg_hex_width_plus_precision_flags(hex, width, precision, s_struct);
	mg_hex_width_plus_precision(hex, width, precision, s_struct);
	mg_hex_width_minus(hex, width, precision, s_struct);
	mg_hex_zero(hex, width, s_struct);
	mg_hex_width(hex, width, s_struct);
	mg_hex_precesion(hex, precision, s_struct);
}

void				manage_str(va_list argptr, t_arg *s_struct)
{
	char	*arr;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	manage_all_str(arr, width, precision, s_struct);
	if (!(arr = va_arg(argptr, char*)))
		manage_null_str(arr, width, precision, s_struct);
	else
	{
		manage_all_str(arr, width, precision, s_struct);
		manage_str_put(arr, width, precision, s_struct);
	}
}

void				manage_int(va_list argptr, t_arg *s_struct)
{
	int		num;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(argptr, int);
	if (num == 0 && precision == 0 && s_struct->zero_flag == 1 && width > 0)
	{
		while (width-- > 0)
			ft_putchar(' ', s_struct);
	return ;
	}
	manage_all(num, width, precision, s_struct);
	manage_int_put(num, width, precision, s_struct);
	// mg_int_width_plus_precision_flags(num, width, precision, s_struct);
	// mg_int_width_plus_precision(num, width, precision, s_struct);
	// mg_int_width_minus(num, width, precision, s_struct);
	// mg_int_zero(num, width, s_struct);
	// mg_int_width(num, width, s_struct);
	// mg_int_precesion(num, precision, s_struct);
}

void				manage_uns(va_list argptr, t_arg *s_struct)
{
	unsigned int		num;
	int					width;
	int					precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(argptr, unsigned int);
	mg_uns_width_plus_precision_flags(num, width, precision, s_struct);
	mg_uns_width_plus_precision(num, width, precision, s_struct);
	mg_uns_width_minus(num, width, precision, s_struct);
	mg_uns_zero(num, width, s_struct);
	mg_uns_width(num, width, s_struct);
	mg_uns_precesion(num, precision, s_struct);
}

void				manage_ptr(va_list argptr, t_arg *s_struct)
{
	unsigned long long	ptr;
	int					width;
	int					precision;

	precision = s_struct->precision;
	width = s_struct->width;
	ptr = (unsigned long long)va_arg(argptr, void*);
	mg_ptr_width_plus_precision_flags(ptr, width, precision, s_struct);
	if (width > precision && precision > 0 && s_struct->flag == '!')
		mg_ptr_width_plus_precision(ptr, width, precision, s_struct);
	mg_ptr_width_minus(ptr, width, precision, s_struct);
	mg_ptr_zero(ptr, width, s_struct);
	mg_ptr_width(ptr, width, s_struct);
	mg_ptr_precesion(ptr, precision, s_struct);
}
