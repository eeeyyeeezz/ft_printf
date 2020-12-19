/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/19 21:36:20 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

#pragma region STR_MANAGE
static	void			manage_arr_min_flag_width_precision(const char *arr, int width, int precision, t_arg *s_struct)
{
	int i;
	int true_precision;

	i = 0;
	true_precision = precision;
	while (precision-- > ft_strlen(arr))
		ft_putchar(arr[i++]);
	ft_putstr(arr);
	if (true_precision > ft_strlen(arr))
		while (width-- - true_precision > 0)
			ft_putchar(' ');
	while (width-- - ft_strlen(arr) > 0 && true_precision < ft_strlen(arr))
		ft_putchar(' ');
	s_struct->flag = 'Z';
}

static	void			manage_arr_width_plus_precision_flags(const char *arr, int width, int precision, t_arg *s_struct)
{
	int true_precision;

	true_precision = precision;
	if (width > 0 && precision > 0 && s_struct->flag == '-')
		manage_arr_min_flag_width_precision(arr, width, precision, s_struct);
	else if (width == 0 && precision == 0 && s_struct->zero_flag == 0 && s_struct->flag == '!')
	{
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}


static	void			manage_arr_width_plus_precision(const char *arr, int width, int precision, t_arg *s_struct)
{
	int i;

	i = 0;
	if (width > 0 && precision > 0 && s_struct->flag == '!')
	{
		if (precision < ft_strlen(arr))
			width += ft_strlen(arr) - precision;
		while (width - ft_strlen(arr) > 0)
		{
			ft_putchar(' ');
			width--;
		}
		while (precision > 0 && ft_strlen(arr) > precision)
		{
			ft_putchar(arr[i]);
			i++;
			precision--;
		}
		if (precision >= ft_strlen(arr))
			ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}

static	void			manage_arr_width_minus(const char *arr, int width, int precision, t_arg *s_struct)
{
	if (width > ft_strlen(arr) && width > precision && s_struct->flag == '-')
	{
		ft_putstr(arr);
		while (width - ft_strlen(arr))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

static	void			manage_arr_width(const char *arr, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen(arr) && width > precision && s_struct->flag != 'Z')
	{
		while (width - ft_strlen(arr) && s_struct->flag != '0')
		{
			ft_putchar(' ');
			width--;
		}
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
	else if ((width == ft_strlen(arr) && width < ft_strlen(arr)) && s_struct->flag != 'Z')
	{
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}

static	void		manage_arr_precesion(const char *arr, int precision, t_arg *s_struct)
{
	int i;
	int width;

	i = 0;
	width = s_struct->width;
	if ((precision < ft_strlen(arr) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
	{
		while (precision-- > 0)
			ft_putchar(arr[i++]);
		s_struct->flag = 'Z';
	}
	else if ((precision >= ft_strlen(arr) || precision < ft_strlen(arr)) && s_struct->flag != 'Z')
	{
		ft_putstr(arr);
		s_struct->flag = 'Z';
	}
}

void 				manage_string(va_list *argptr, t_arg *s_struct)
{
	char	*arr;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	arr = va_arg(*argptr, char*);
	manage_arr_width_plus_precision_flags(arr, width, precision, s_struct);
	manage_arr_width_plus_precision(arr, width, precision, s_struct);
	manage_arr_width_minus(arr, width, precision, s_struct);
	manage_arr_width(arr, width, s_struct);
	manage_arr_precesion(arr, precision, s_struct);
}

#pragma endregion STR_MANAGE

#pragma region HEX_MANAGE
static	char		hex_word(long num)
{
	if (num >= 0 && num <= 9)
		return (num + 48);
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else if (num == 15)
		return ('f');
	return (num);
}

static	int			malloc_count(long num)
{
	int count;

	count = 1;
	while(num >= 16)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

static	void		ft_puthex(long num)
{
	int i;
	int a;
	char tmp;
	char *str;

	i = 0;
	a = 0;
	tmp = 0;
	str = malloc(malloc_count(num));
	while (num > 0)
	{
		str[i] = hex_word((num % 16));
		num = num / 16;
		i++;
	}
	i -= 1;
	while (i >= 0)
		write(1, &str[i--], 1);
	free(str);
	str = NULL;
}

static	void			manage_hex_width_plus_precision_flags(long num, int width, int precision, int o_precesion, t_arg *s_struct)
{
	if (num < 0)
		width -= 1;
	if (width > 0 && precision > 0 && s_struct->flag != '!')
	{
		while (width > precision && s_struct->flag != '-')
		{
			ft_putchar(' ');
			width--;
		}
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision > malloc_count(num))
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		while (width - o_precesion > 0 && s_struct->flag == '-')
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_width_plus_precision(long num, int width, int precision, t_arg *s_struct)
{
	if (num < 0)
		width -= 1;
	if (width > 0 && precision > 0 && s_struct->flag == '!')
	{
		while (width > precision)
		{
			ft_putchar(' ');
			width--;
		}
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision > malloc_count(num))
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_width_minus(long num, int width, int precision, t_arg *s_struct)
{
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag == '-')
	{
		ft_puthex(num);
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ');
			width--;
		}
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_zero(long num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (precision > ft_strlen_atoi(num) && width != precision && precision > width && s_struct->flag == '0')
	{
		if (num < 0 && s_struct->flag == '0')
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision - malloc_count(num) > 0)
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}

static	void			manage_hex_width(long num, int width, t_arg *s_struct)
{
	int precision;

	precision = s_struct->precision;
	if (width > ft_strlen_atoi(num) && width > precision && s_struct->flag != 'Z')
	{
		while (width - ft_strlen_atoi(num))
		{
			ft_putchar(' ');
			width--;
		}
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
	else if ((width == ft_strlen_atoi(num) || width < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}

static	void		manage_hex_precesion(long num, int precision, t_arg *s_struct)
{
	int width;

	width = s_struct->width;
	if ((precision > ft_strlen_atoi(num) && width < precision && s_struct->flag == '!') ||
	(width == precision && s_struct->flag == '!') || (s_struct->flag == '-' && width == 0))
	{
		if (num < 0)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (precision - malloc_count(num) > 0)
		{
			ft_putchar('0');
			precision--;
		}
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
	else if ((precision == ft_strlen_atoi(num) || precision < ft_strlen_atoi(num)) && s_struct->flag != 'Z')
	{
		ft_puthex(num);
		s_struct->flag = 'Z';
	}
}



void		manage_hex(va_list *argptr, t_arg *s_struct)
{
	long	hex;
	int		width;
	int		precision;

	precision = s_struct->precision;
	width = s_struct->width;
	hex = va_arg(*argptr, unsigned int);
	if (width > 0 && precision > 0 && s_struct->flag != '!')
		manage_hex_width_plus_precision_flags(hex, width, precision, precision, s_struct);
	manage_hex_width_plus_precision(hex, width, precision, s_struct);
	manage_hex_width_minus(hex, width, precision, s_struct);
	manage_hex_zero(hex, width, s_struct);
	manage_hex_width(hex, width, s_struct);
	manage_hex_precesion(hex, precision, s_struct);
}

#pragma endregion HEX_MANAGE

#pragma region PTR_MANAGE
void 				manage_pointers(va_list *argptr, t_arg *s_struct)
{
	unsigned long	ptr;
	int				width;
	int				precision;

	precision = s_struct->precision;
	width = s_struct->width;
	ptr = (unsigned long)va_arg(*argptr, void*);
}

#pragma endregion PTR_MANAGE

void			manage_fuction(const char *procent, va_list *argptr, t_arg *s_struct)
{
	int i;

	i = -1;
	(void)procent;
	if (s_struct->type == 'd' || s_struct->type == 'i')
		manage_int(argptr, s_struct);
	if (s_struct->type == 's')
		manage_string(argptr, s_struct);
	if (s_struct->type == 'x')
		manage_hex(argptr, s_struct);
	if (s_struct->type == 'p')
		manage_pointers(argptr, s_struct);
}

int				ft_printf(const char *arr, ...)
{
	int		i;
	va_list	argptr;
	t_arg 	s_struct;

	i = -1;
	va_start(argptr, arr);
	while (arr[++i])
	{
		if (arr[i] == '%')
		{
			ft_parser((char *)&arr[i], &s_struct, &argptr);
			i += s_struct.count;
			manage_fuction((char *)&arr[i], &argptr, &s_struct);
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
