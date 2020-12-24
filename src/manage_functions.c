/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:56:49 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/20 20:59:58 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		manage_hex(va_list argptr, t_arg *s_struct)
{
	long	hex;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	hex = va_arg(argptr, unsigned int);
	manage_hex_width_plus_precision_flags(hex, width, precision, s_struct);
	manage_hex_width_plus_precision(hex, width, precision, s_struct);
	manage_hex_width_minus(hex, width, precision, s_struct);
	manage_hex_zero(hex, width, s_struct);
	manage_hex_width(hex, width, s_struct);
	manage_hex_precesion(hex, precision, s_struct);
}

void 				manage_str(va_list argptr, t_arg *s_struct)
{
	char	*arr;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	if (!(arr = va_arg(argptr, char*)))
		arr = "(null)";
	manage_arr_width_plus_precision_flag(arr, width, precision, s_struct);
	manage_arr_width_plus_precision(arr, width, precision, s_struct);
	manage_arr_width_minus(arr, width, precision, s_struct);
	manage_arr_width(arr, width, s_struct);
	manage_arr_precesion(arr, precision, s_struct);
}

void 				manage_int(va_list argptr, t_arg *s_struct)
{
	int		num;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(argptr, int);
	manage_int_width_plus_precision_flags(num, width, precision, s_struct);
	manage_int_width_plus_precision(num, width, precision, s_struct);
	manage_int_width_minus(num, width, precision, s_struct);
	manage_int_zero(num, width, s_struct);
	manage_int_width(num, width, s_struct);
	manage_int_precesion(num, precision, s_struct);
}

void 				manage_uns(va_list argptr, t_arg *s_struct)
{
	unsigned int		num;
	int					width;
	int					precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(argptr, unsigned int);
	manage_uns_width_plus_precision_flags(num, width, precision, s_struct);
	manage_uns_width_plus_precision(num, width, precision, s_struct);
	manage_uns_width_minus(num, width, precision, s_struct);
	manage_uns_zero(num, width, s_struct);
	manage_uns_width(num, width, s_struct);
	manage_uns_precesion(num, precision, s_struct);
}
