/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 19:39:43 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

#pragma region INT_MANAGE

static void		manage_int_neg(int num, int precision, t_arg *s_struct)
{
		s_struct->f_len -= 1;
		s_struct->null_put = precision - ft_strlen_atoi(num) + 1;
		if (s_struct->flag == '0')
			s_struct->flag = '!';
		s_struct->f_len = precision + 1;
}

static void		manage_int_plus(int num, int precision, t_arg *s_struct)
{
		s_struct->null_put = precision - ft_strlen_atoi(num);
		if (s_struct->flag == '0')
			s_struct->flag = '!';
		s_struct->f_len = precision;
}

void			manage_all(int num, int width, int precision, t_arg *s_struct)
{
	s_struct->f_len = ft_strlen_atoi(num);
	if (precision > s_struct->f_len && num >= 0)
		manage_int_plus(num, precision, s_struct);
	if (precision > s_struct->f_len - 1 && num < 0)
		manage_int_neg(num, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) && s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - ft_strlen_atoi(num);
}

void			manage_int_put(int num, int width, int precision, t_arg *s_struct)
{
	if (s_struct->flag == '-' && num < 0)
	{
		ft_putchar('-', s_struct);
		num *= -1;
	}
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_putnbr(num, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0 && s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	if (s_struct->flag != '-' && num < 0)
	{
		ft_putchar('-', s_struct);
		num *= -1;
	}
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_putnbr(num, s_struct);
}

#pragma endregion INT_MANAGE

#pragma region STR_MANAGE

void			manage_all_str(const char *arr, int width, int precision, t_arg *s_struct)
{
	s_struct->f_len = ft_strlen(arr);
	if (precision < 0)
	{
		s_struct->zero_flag = 0;
		s_struct->precision = 0;
	}
	if (precision < ft_strlen(arr) && s_struct->zero_flag == 1)
			s_struct->f_len = precision;
	if ((s_struct->zero_flag == 0 || precision < 0) && s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - ft_strlen(arr);
}

void			manage_null_str(const char *arr, int width, int precision, t_arg *s_struct)
{
	int flag;
	int i;

	i = 0;
	flag = 0;
	arr = "(null)";
	s_struct->f_len = ft_strlen(arr);
	if (precision < ft_strlen(arr) && s_struct->zero_flag == 1 && precision >= 0)
		s_struct->f_len = precision;
	while (s_struct->flag == '-' && precision-- > 0 && arr[i] != '\0')
	{
		ft_putchar(arr[i++], s_struct);
		flag = 1;
	}
	if (s_struct->flag == '-' && s_struct->f_len != 0 && flag == 0)
		ft_putstr(arr, s_struct);
	while (width-- > s_struct->f_len)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && precision-- > 0 && arr[i] != '\0')
		ft_putchar(arr[i++], s_struct);
	if (s_struct->flag != '-' && s_struct->zero_flag == 0 && s_struct->f_len != 0)
		ft_putstr(arr, s_struct);
}

void			manage_str_put(const char *arr, int width, int precision, t_arg *s_struct)
{
	int i;

	i = 0;
	if (precision < ft_strlen(arr) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
	while (s_struct->flag == '-' && precision-- > 0 && arr[i] != '\0')
		ft_putchar(arr[i++], s_struct);
	if (s_struct->flag == '-' && s_struct->zero_flag == 0)
		ft_putstr(arr, s_struct);
	while (width-- > s_struct->f_len)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && precision-- > 0 && arr[i] != '\0')
		ft_putchar(arr[i++], s_struct);
	if (s_struct->flag != '-' && s_struct->zero_flag == 0)
		ft_putstr(arr, s_struct);
}


#pragma endregion TRUE_STR_MANAGE

void			manage_fuction(va_list argptr, t_arg *s_struct)
{
	if (s_struct->type == 'd' || s_struct->type == 'i')
		manage_int(argptr, s_struct);
	if (s_struct->type == 'u')
		manage_uns(argptr, s_struct);
	if (s_struct->type == 'c')
		manage_chr(argptr, s_struct);
	if (s_struct->type == 's')
		manage_str(argptr, s_struct);
	if (s_struct->type == 'x' || s_struct->type == 'X')
		manage_hex(argptr, s_struct);
	if (s_struct->type == 'p')
		manage_ptr(argptr, s_struct);
	if (s_struct->type == '%')
		manage_prc(s_struct);
}

int				ft_printf(const char *arr, ...)
{
	int				i;
	static va_list	argptr;
	t_arg			s_struct;

	i = -1;
	s_struct.r_r = 0;
	va_start(argptr, arr);
	while (arr[++i])
	{
		if (arr[i] == '%')
		{
			ft_parser((char *)&arr[i], &s_struct, argptr);
			// printf("width [%d] percesion [%d] flag [%c] ", s_struct.width, s_struct.precision, s_struct.flag);
			i += s_struct.count;
			manage_fuction(argptr, &s_struct);
		}
		else
			ft_putchar(arr[i], &s_struct);
	}
	va_end(argptr);
	return (s_struct.r_r);
}
