/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/20 20:56:10 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

#pragma region PTR_MANAGE
char		ptr_word(long num)
{
	char letter;

	letter = '\0';
	if (num >= 0 && num <= 9)
		return (num + 48);
	else if (num == 10)
		letter = 'a';
	else if (num == 11)
		letter = 'b';
	else if (num == 12)
		letter = 'c';
	else if (num == 13)
		letter = 'd';
	else if (num == 14)
		letter = 'e';
	else if (num == 15)
		letter = 'f';
	return (letter);
}

void		ft_putptr(long num, t_arg *s_struct)
{
	int i;
	int a;
	char tmp;
	char *str;

	i = 0;
	a = 0;
	tmp = 0;
	if (num == 0 && s_struct->precision == 0 && s_struct->zero_flag == 1)
		return ;
	if (!(str = malloc(malloc_count(num))))
		return ;
	if (num == 0)
		write(1, "0", 1);
	write(1, "0x", 2);
	while (num > 0)
	{
		str[i] = ptr_word((num % 16));
		num = num / 16;
		i++;
	}
	i -= 1;
	while (i >= 0)
		write(1, &str[i--], 1);
	free(str);
	str = NULL;
}


void			manage_ptr_zero_flag_width_precision(long num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (precision > malloc_count(num) && num < 0 && s_struct->flag == '0')
		width -= 1;
	if (precision > malloc_count(num) && s_struct->flag == '0')
	{
		while (width-- > precision)
			ft_putchar(' ');
		s_struct->flag = 'A';
	}
	while (width-- > malloc_count(num) && s_struct->flag == '0')
		ft_putchar(' ');
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		width -= 1;
	}
	while (precision-- > malloc_count(num))
		ft_putchar('0');
	ft_putptr(num, s_struct);
	s_struct->flag = 'Z';
}

void			manage_ptr_min_flag_width_precision(long num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		width -= 1;
	}
	while (precision-- > malloc_count(num))
		ft_putchar('0');
	ft_putptr(num, s_struct);
	if (true_precision > malloc_count(num))
		while (width-- - true_precision > 0)
			ft_putchar(' ');
	while (width-- - malloc_count(num) > 0 && true_precision < malloc_count(num))
		ft_putchar(' ');
	s_struct->flag = 'Z';
}

void			manage_ptr_width_plus_precision_flags(long num, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '0')
		manage_hex_zero_flag_width_precision(num, width, precision, s_struct);
	else if (width > 0 && precision > 0 && s_struct->flag == '-')
		manage_hex_min_flag_width_precision(num, width, precision, s_struct);
}

void			manage_ptr_width_plus_precision(long num, int width, int precision, t_arg *s_struct)
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
				ft_putchar(' ');
			s_struct->flag = 'A';
		}
		while (width-- > malloc_count(num) && s_struct->flag != 'A')
			ft_putchar(' ');
		if (num < 0)
		{
			num *= -1;
			ft_putchar('-');
		}
		while (true_precision-- > malloc_count(num))
			ft_putchar('0');
		ft_putptr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void			manage_ptr_width_minus(long num, int width, int precision, t_arg *s_struct)
{
	if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
	if (width > malloc_count(num) && width > precision && s_struct->flag == '-')
	{
		ft_putptr(num, s_struct);
		while (width - malloc_count(num))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

void			manage_ptr_zero(long num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > malloc_count(num) && width != precision && width > precision && s_struct->flag == '0')
	{
		if (num < 0 && s_struct->flag == '0')
		{
			ft_putchar('-');
			width -= 1;
			num *= -1;
		}
		while (width - malloc_count(num) > 0)
		{
			ft_putchar('0');
			width--;
		}
		ft_putptr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void			manage_ptr_width(long num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > malloc_count(num) && width > precision && s_struct->flag != 'Z')
	{
		if (s_struct->zero_flag == 1 && precision == 0 && num == 0)
			width += 1;
		while (width - malloc_count(num) && s_struct->flag != '0')
		{
			ft_putchar(' ');
			width--;
		}
		ft_putptr(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((width == malloc_count(num) && width < malloc_count(num)) && s_struct->flag != 'Z')
	{
		ft_putptr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void		manage_ptr_precesion(long num, int precision, t_arg *s_struct)
{
	int width;

	width = s_struct->width;
	if ((precision > malloc_count(num) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
	{
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision-- - malloc_count(num) > 0)
			ft_putchar('0');
		ft_putptr(num, s_struct);
		s_struct->flag = 'Z';
	}
	else if ((precision == malloc_count(num) || precision < malloc_count(num)) && s_struct->flag != 'Z')
	{
		ft_putptr(num, s_struct);
		s_struct->flag = 'Z';
	}
}

void 				manage_ptr(va_list *argptr, t_arg *s_struct)
{
	unsigned long long	ptr;
	int					width;
	int					precision;

	precision = s_struct->precision;
	width = s_struct->width;
	ptr = (unsigned long long)va_arg(*argptr, void*);
	manage_ptr_width_plus_precision_flags(ptr, width, precision, s_struct);
	manage_ptr_width_plus_precision(ptr, width, precision, s_struct);
	manage_ptr_width_minus(ptr, width, precision, s_struct);
	manage_ptr_zero(ptr, width, s_struct);
	manage_ptr_width(ptr, width, s_struct);
	manage_ptr_precesion(ptr, precision, s_struct);
}

#pragma endregion PTR_MANAGE

#pragma region PRC_MANAGE



#pragma endregion PRC_MANAGE

void			manage_fuction(va_list *argptr, t_arg *s_struct)
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
	// if (s_struct->type == '%')
	// 	manage_per(argptr, s_struct);
}

int				ft_printf(const char *arr, ...)
{
	int			i;
	static va_list	argptr;
	t_arg 			s_struct;

	i = -1;
	va_start(argptr, arr);
	while (arr[++i])
	{
		if (arr[i] == '%')
		{
			ft_parser((char *)&arr[i], &s_struct, &argptr);
			i += s_struct.count;
			manage_fuction(&argptr, &s_struct);
		}
		else
		{
			s_struct.len++;
			ft_putchar(arr[i]);
		}
	}
	va_end(argptr);
	return (s_struct.len);
}
