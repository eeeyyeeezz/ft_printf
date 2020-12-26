/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/26 21:22:23 by gmorra           ###   ########.fr       */
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
		if (precision > ft_strlen_atoi(num) && s_struct->zero_flag == 1)
			s_struct->f_len = precision;
}

void			manage_all_int(int num, int width, int precision, t_arg *s_struct)
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

#pragma region UNS_MANAGE
static int			ft_strlen_uns(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

void		manage_uns_plus(unsigned int num, int precision, t_arg *s_struct)
{
		s_struct->null_put = precision - ft_strlen_uns(num);
		if (s_struct->flag == '0')
			s_struct->flag = '!';
		if (precision > ft_strlen_uns(num) && s_struct->zero_flag == 1)
			s_struct->f_len = precision;
}

void			manage_all_uns(unsigned int num, int width, int precision, t_arg *s_struct)
{
	s_struct->f_len = ft_strlen_uns(num);
	if (precision > s_struct->f_len && num >= 0)
		manage_uns_plus(num, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) && s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - ft_strlen_uns(num);
}

void			manage_uns_put(unsigned int num, int width, int precision, t_arg *s_struct)
{
	if (num == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		width += 1;
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_putuns(num, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0 && s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_putuns(num, s_struct);
}



#pragma endregion UNS_MANAGE

#pragma region HEX_MANAGE

static void		manage_hex_plus(unsigned int hex, int precision, t_arg *s_struct)
{
	s_struct->null_put = precision - malloc_count(hex);
	if (s_struct->flag == '0')
		s_struct->flag = '!';
	if (precision > malloc_count(hex) && s_struct->zero_flag == 1)
		s_struct->f_len = precision;
}

void			manage_all_hex(unsigned int hex, int width, int precision, t_arg *s_struct)
{
	s_struct->f_len = malloc_count(hex);
	if (precision > s_struct->f_len && hex >= 0)
		manage_hex_plus(hex, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) && s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - malloc_count(hex);
}

void			manage_hex_put(unsigned int hex, int width, int precision, t_arg *s_struct)
{
	if (hex == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		width += 1;
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_puthex(hex, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0 && s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_puthex(hex, s_struct);
}


#pragma endregion HEX_MANAGE

#pragma region PTR_MANAGE
static void		manage_ptr_plus(long ptr, int precision, t_arg *s_struct)
{
		s_struct->null_put = precision - malloc_count(ptr);
		if (s_struct->flag == '0')
			s_struct->flag = '!';
		if (precision > malloc_count(ptr) && s_struct->zero_flag == 1)
			s_struct->f_len = precision;
}

void			manage_all_ptr(long ptr, int width, int precision, t_arg *s_struct)
{
	s_struct->f_len = malloc_count(ptr);
	if (precision > s_struct->f_len && ptr >= 0)
		manage_ptr_plus(ptr, precision, s_struct);
	if ((s_struct->zero_flag == 0 || precision < 0) && s_struct->flag == '0' && s_struct->f_len < width)
		s_struct->null_put = s_struct->width - malloc_count(ptr);
}

void			manage_ptr_put(long ptr, int width, int precision, t_arg *s_struct)
{
	if (ptr == 0 && s_struct->zero_flag == 1 && s_struct->precision == 0)
		width += 1;
	while (s_struct->flag == '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag == '-')
		ft_putptr(ptr, s_struct);
	if (precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '0')
		width -= 1;
	while ((s_struct->flag != '0' || (precision >= 0 && s_struct->zero_flag == 1)) && s_struct->f_len < width--)
		ft_putchar(' ', s_struct);
	while (s_struct->flag != '-' && s_struct->null_put-- > 0)
		ft_putchar('0', s_struct);
	if (s_struct->flag != '-')
		ft_puthex(ptr, s_struct);
}

#pragma endregion PTR_MANAGE

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
			i += s_struct.count;
			manage_fuction(argptr, &s_struct);
		}
		else
			ft_putchar(arr[i], &s_struct);
	}
	va_end(argptr);
	return (s_struct.r_r);
}
