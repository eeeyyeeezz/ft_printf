/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:56:49 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 22:41:01 by gmorra           ###   ########.fr       */
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
	manage_all_hex(hex, width, precision, s_struct);
	manage_hex_put(hex, width, precision, s_struct);
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
	manage_all_int(num, width, precision, s_struct);
	manage_int_put(num, width, precision, s_struct);
}

void				manage_uns(va_list argptr, t_arg *s_struct)
{
	unsigned int		num;
	int					width;
	int					precision;

	precision = s_struct->precision;
	width = s_struct->width;
	num = va_arg(argptr, unsigned int);
	manage_all_uns(num, width, precision, s_struct);
	manage_uns_put(num, width, precision, s_struct);
}

void				manage_ptr(va_list argptr, t_arg *s_struct)
{
	unsigned long long	ptr;
	int					width;
	int					precision;

	precision = s_struct->precision;
	width = s_struct->width;
	ptr = (unsigned long long)va_arg(argptr, void*);
	manage_all_ptr(ptr, width, precision, s_struct);
	manage_ptr_put(ptr, width, precision, s_struct);
}
